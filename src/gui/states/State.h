//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_STATE_H
#define NSPASS_STATE_H

#include <memory>
#include "../../Category.h"
#include "../../Group.h"

namespace NSPass::GUI::States {
	class State {
	public:
		virtual void OpenDefault() { };
		virtual void Open() { };
		virtual void Close() { };
		virtual void Save() { };
		virtual void SelectCategory(const CategoryPtr& category) { };
		virtual void SelectGroup(const CategoryPtr& category, const GroupPtr& group) { };
	};

	typedef std::unique_ptr<State> StatePtr;
}

#endif //NSPASS_STATE_H
