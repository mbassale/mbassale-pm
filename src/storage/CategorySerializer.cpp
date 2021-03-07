//
// Created by Marco Bassaletti on 07-03-21.
//

#include <iostream>
#include "GroupSerializer.h"
#include "CategorySerializer.h"

namespace OwnPass::Storage {

    boost::json::object CategorySerializer::serialize(const Category& obj) {
        GroupSerializer group_serializer;
        return {
            { "name", obj.get_name() },
            { "groups", group_serializer.serialize(obj.get_groups()) }
        };
    }

    boost::json::array CategorySerializer::serialize(const std::list<Category>& objs) {
        boost::json::array category_data;
        for (auto& category : objs) {
            auto category_datum = serialize(category);
            category_data.push_back(category_datum);
        }
        return category_data;
    }

    Category CategorySerializer::deserialize(boost::json::object& obj) {
        auto category_name = obj["name"].as_string();
        auto groups_data = obj["groups"].as_array();
        GroupSerializer group_serializer;
        std::list<Group> groups = group_serializer.deserialize(groups_data);
        Category category{ category_name.c_str(), groups };
        return category;
    }

    std::list<Category> CategorySerializer::deserialize(boost::json::array& objs) {
        std::list<Category> categories;
        for (auto category_datum : objs) {
            auto category_obj = category_datum.as_object();
            auto category = deserialize(category_obj);
            categories.push_back(category);
        }
        if (categories.empty()) return make_default();
        return categories;
    }

    std::list<Category> CategorySerializer::make_default() {
        return std::list<Category>();
    }

}