//
// Created by Marco Bassaletti on 30-03-21.
//

#ifndef OWNPASS_GROUPQUERY_H
#define OWNPASS_GROUPQUERY_H

#include "../NSPass.h"
#include "../Group.h"
#include "Query.h"

#include <utility>

namespace NSPass::Query {
	struct GroupQueryItem {
		CategoryPtr category;
		GroupPtr group;
		GroupQueryItem(CategoryPtr category, GroupPtr group)
				:category{ std::move(category) }, group{ std::move(group) } { }
	};

	class GroupQuery : public Query<GroupQueryItem> {
	public:
		struct QueryArguments {
			std::string category_search;
			std::string search;
		};

		explicit GroupQuery(Storage::Storage& storage)
				:Query<GroupQueryItem>(storage) { }
		GroupQuery(Storage::Storage& storage, QueryArguments args)
				:Query<GroupQueryItem>(storage), args{ std::move(args) } { }
		GroupQueryItem find(ObjectId group_id) override;
		std::vector<GroupQueryItem> find() override;
		GroupQueryItem find_first() override;
		bool empty() override;
		size_t size() override;
	protected:
		QueryArguments args;
		std::vector<NSPass::CategoryPtr> categories;
		std::vector<GroupQueryItem> results;
		void find_categories();
	};
}

#endif //OWNPASS_GROUPQUERY_H
