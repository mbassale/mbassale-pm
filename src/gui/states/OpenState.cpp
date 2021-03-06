//
// Created by Marco Bassaletti on 10-04-21.
//

#include "../App.h"
#include "OpenState.h"
#include "SaveState.h"

namespace NSPass::GUI::States {
	OpenState::OpenState(StateContext& context)
			:context{ context }
	{
	}

	void OpenState::OpenDefault()
	{
		const auto masterPassword = wxGetPasswordFromUser("Please enter master password:", "Master Password Required",
				wxEmptyString, wxGetActiveWindow());
		if (masterPassword.empty()) return;
		auto& app = Application::instance();
		auto& vault = app.get_vault();
		vault.set_master_password(std::string(masterPassword.c_str()));
		vault.set_storage_location(app.get_settings().get_data_directory()+"/nspass.db");
		vault.open();
		context.SetCurrentState(StateName::Open);
		context.Notify(StateName::Open);
	}

	void OpenState::Save()
	{
		context.GetState(StateName::Save).Save();
	}

	void OpenState::Close()
	{
		context.GetState(StateName::Close).Close();
	}

	void OpenState::SelectCategory(const CategoryPtr& category)
	{
		context.GetState(StateName::SelectCategory).SelectCategory(category);
	}

	void OpenState::SelectGroup(const CategoryPtr& category, const GroupPtr& group)
	{
		context.GetState(StateName::SelectGroup).SelectGroup(category, group);
	}
}
