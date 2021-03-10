//
// Created by Marco Bassaletti on 05-03-21.
//
#include "catch.hpp"
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <list>
#include <sstream>
#include "../storage/Storage.h"
#include "../Group.h"

using namespace std;
using namespace std::string_literals;
using namespace OwnPass;
using namespace OwnPass::Storage;

class JsonStorageFixture {
public:
	JsonStorageFixture()
	{
		db = StorageFactory::make();
		db->purge();
	}
protected:
	shared_ptr<OwnPass::Storage::Storage> db;

	void save_category(const string& prefix, int index = 0)
	{
		stringstream category_name;
		category_name << prefix << index;
		Category category{ category_name.str() };
		db->save_category(category);
	}

	Group save_group(Category& category, const string& name, const string& url, const string& description)
	{
		Group group = GroupFactory::make_group(name, url, description);
		category.add_group(group);
		db->save_category(category);
		return group;
	}

	Group save_site(Category& category, const string& name, const string& url, const string& description)
	{
		Group site = GroupFactory::make_site(name, url, description);
		category.add_group(site);
		db->save_category(category);
		return site;
	}

	Group save_application(Category& category, const string& name, const string& url, const string& description)
	{
		Group application = GroupFactory::make_application(name, url, description);
		category.add_group(application);
		db->save_category(category);
		return application;
	}

	void flush_and_reload()
	{
		db->flush();
		db->reload();
	}

	tuple<shared_ptr<OwnPass::Storage::Storage>, list<Category>&, Category&> initialize_db_with_category() {
		shared_ptr<OwnPass::Storage::Storage> db2 = StorageFactory::make();
		{
			db2->purge();
			Category category;
			db2->save_category(category);
			db2->flush();
			db2->reload();
		}
		auto& categories = db2->list_categories();
		auto& first_category = categories.front();
		return tuple<shared_ptr<OwnPass::Storage::Storage>, list<Category>&, Category&>(db2, categories, first_category);
	}
};

TEST_CASE_METHOD(JsonStorageFixture, "make instance")
{
	REQUIRE_NOTHROW(StorageFactory::make());
}

TEST_CASE_METHOD(JsonStorageFixture, "categories")
{
	SECTION("empty") {
		list<Category> categories = db->list_categories();
		REQUIRE(categories.empty());
	}

	SECTION("add 10 list again") {
		for (auto i = 0; i < 10; i++) {
			save_category("Category #", i);
		}
		list<Category> categories = db->list_categories();
		REQUIRE(categories.size() == 10);
		for (auto& category : categories) {
			REQUIRE(category.get_name().find("Category #") != string::npos);
		}
	}

	SECTION("search for specific string") {
		for (auto i = 0; i < 10; i++) {
			save_category("Category #", i);
		}
		auto category_name = "Category #5";
		auto category = db->find_category(category_name);
		REQUIRE(category.get_name() == category_name);
		auto category_name2 = "category #5";
		auto category2 = db->find_category(category_name2);
		REQUIRE(boost::algorithm::icontains(category2.get_name(), category_name2));
	}
}

TEST_CASE_METHOD(JsonStorageFixture, "groups")
{
	auto [db, categories, first_category] = initialize_db_with_category();

	SECTION("new category with no group") {
		REQUIRE(first_category.get_groups().empty());
	}

	SECTION("add group to existing category")
	{
		auto group_name = "Group #1";
		auto group_url = "https://test.com";
		auto group_description = "lorem ipsum dolor senet";
		auto original_group = save_group(first_category, group_name, group_url, group_description);
		flush_and_reload();
		auto& first_category2 = db->list_categories().front();
		REQUIRE_FALSE(first_category2.get_groups().empty());
		auto& group = first_category2.get_groups().front();
		REQUIRE(group.get_id() == original_group.get_id());
		REQUIRE(group.get_type() == GroupType::Group);
		REQUIRE(group.get_name() == group_name);
		REQUIRE(group.get_url() == group_url);
		REQUIRE(group.get_description() == group_description);

		SECTION("modify a copy of existing category and group and then save it") {
			Category first_category_copy = db->list_categories().front();
			first_category_copy.set_name("Updated Category");
			first_category_copy.get_groups().front().set_name("Updated Group");
			db->save_category(first_category_copy);
			flush_and_reload();
			auto& updated_category = db->list_categories().front();
			REQUIRE(updated_category.get_name() == "Updated Category");
			auto& updated_group = updated_category.get_groups().front();
			REQUIRE(updated_group.get_name() == "Updated Group");
		}
	}

	SECTION("remove group from existing category") {
		auto first_group = save_group(first_category, "Group #1", "https://test.com", "lorem ipsum dolor senet");
		flush_and_reload();
		auto second_group = save_group(first_category, "Group #2", "https://test2.com", "senet dolor ipsum lorem");
		flush_and_reload();

		auto& first_category2 = db->list_categories().front();
		REQUIRE(first_category2.get_groups().size() == 2);
		first_category2.remove_group(first_group);
		flush_and_reload();

		auto& first_category3 = db->list_categories().front();
		REQUIRE(first_category3.get_groups().size() == 1);
		auto existing_group = first_category3.get_groups().front();
		REQUIRE(second_group.get_id() == existing_group.get_id());
	}
}

TEST_CASE_METHOD(JsonStorageFixture, "sites") {
	auto [db, categories, first_category] = initialize_db_with_category();

	SECTION("add site to existing category") {
		auto site_name = "Site #1";
		auto site_url = "https://www.site.com";
		auto site_description = "lorem ipsum dolor senet";
		auto original_site = save_site(first_category, site_name, site_url, site_description);
		flush_and_reload();
		auto& first_category2 = db->list_categories().front();
		REQUIRE_FALSE(first_category2.get_groups().empty());
		auto& site = first_category2.get_groups().front();
		REQUIRE(site.get_id() == original_site.get_id());
		REQUIRE(GroupType::Site == site.get_type());
		REQUIRE(site.get_type() == GroupType::Site);
		REQUIRE(site.get_name() == site_name);
		REQUIRE(site.get_url() == site_url);
		REQUIRE(site.get_description() == site_description);
	}
}

TEST_CASE_METHOD(JsonStorageFixture, "applications") {
	auto [db, categories, first_category] = initialize_db_with_category();

	SECTION("add application to existing category") {
		auto app_name = "App #1";
		auto app_url = "https://www.app.com";
		auto app_description = "lorem ipsum dolor senet";
		auto original_app = save_application(first_category, app_name, app_url, app_description);
		flush_and_reload();
		auto& first_category2 = db->list_categories().front();
		REQUIRE_FALSE(first_category2.get_groups().empty());
		auto& site = first_category2.get_groups().front();
		REQUIRE(original_app.get_id() == site.get_id());
		REQUIRE(GroupType::Application == site.get_type());
		REQUIRE(app_name == site.get_name());
		REQUIRE(app_url == site.get_url());
		REQUIRE(app_description == site.get_description());
	}
}
