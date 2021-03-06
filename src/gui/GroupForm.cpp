//
// Created by Marco Bassaletti on 08-04-21.
//

#include "CreatePasswordForm.h"
#include "PasswordForm.h"
#include "GroupForm.h"
#include "../commands/UpdateGroupCommand.h"
#include "../commands/DeleteGroupCommand.h"

namespace NSPass::GUI {
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::UpdateGroupCommand;
	using NSPass::Commands::DeleteGroupCommand;

	GroupForm::GroupForm(wxWindow* parent, CategoryPtr category, GroupPtr group)
			:BaseGroupForm(parent), category{ std::move(category) }, group{ std::move(group) }
	{
		FillData();
		passwordCreatedConnection = GetSignalContext().get_password_created().connect([&](const PasswordPtr& password) {
			OnPasswordCreated(password);
		});
		passwordUpdatedConnection = GetSignalContext().get_password_updated().connect([&](const PasswordPtr& password) {
			FillPasswordsData();
		});
		passwordDeletedConnection = GetSignalContext().get_password_deleted().connect([&](const PasswordPtr& password) {
			OnPasswordDeleted();
		});
	}

	void GroupForm::FillData()
	{
		wxString id{ object_id_to_string(group->get_id()) };
		idText->SetLabel(id);
		wxString name{ group->get_name().data() };
		nameText->SetValue(name);
		wxString url{ group->get_url().data() };
		urlText->SetValue(url);
		wxString description{ group->get_description().data() };
		descriptionText->SetValue(description);

		FillPasswordsData();
	}

	void GroupForm::FillPasswordsData()
	{
		passwordsList->Hide();
		passwordsList->ClearAll();
		wxListItem urlColumn;
		urlColumn.SetText("URL");
		urlColumn.SetAlign(wxLIST_FORMAT_LEFT);
		passwordsList->InsertColumn(0, urlColumn);

		wxListItem usernameColumn;
		usernameColumn.SetText("Username");
		usernameColumn.SetAlign(wxLIST_FORMAT_LEFT);
		passwordsList->InsertColumn(1, usernameColumn);

		int row = 0;
		for (auto& password : group->get_passwords()) {
			wxString password_id{ object_id_to_string(password->get_id()) };
			wxString password_url{ password->get_url().data() };
			wxString username{ password->get_username().data() };
			if (password_url.length() > 32) {
				password_url = password_url.substr(0, 30)+"..";
			}
			long itemId = passwordsList->InsertItem(row, password_id, 0);
			passwordsList->SetItemData(itemId, row);
			passwordsList->SetItemPtrData(itemId, reinterpret_cast<wxUIntPtr>(&password));
			passwordsList->SetItem(itemId, 0, password_url);
			passwordsList->SetItem(itemId, 1, username);
			row++;
		}
		passwordsList->SetColumnWidth(0, wxLIST_AUTOSIZE);
		passwordsList->SetColumnWidth(1, wxLIST_AUTOSIZE);
		passwordsList->Show();
	}

	void GroupForm::OnItemSelected(wxListEvent& event)
	{
		auto& password = *(reinterpret_cast<PasswordPtr*>(event.GetData()));
		auto* passwordForm = new PasswordForm(this, password);
		passwordDetailSizer->Clear(true);
		passwordDetailSizer->Add(passwordForm, wxSizerFlags().Expand().Border(wxALL, 0));
		RedrawForm();
	}

	void GroupForm::OnEdit(wxCommandEvent& event)
	{
		EnableEdition();
	}

	void GroupForm::OnSave(wxCommandEvent& event)
	{
		try {
			auto& commandRunner = wxGetApp().GetCommandRunner();
			UpdateGroupCommand::UpdateData update_data;
			update_data.name = nameText->GetValue();
			update_data.url = urlText->GetValue();
			update_data.description = descriptionText->GetValue();
			CommandPtr update_group_command{
					new UpdateGroupCommand(Application::instance(), group->get_id(), update_data) };
			commandRunner.run_command(update_group_command);
			FillData();
			DisableEdition();
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error saving group", wxICON_ERROR);
		}
	}

	void GroupForm::OnCancel(wxCommandEvent& event)
	{
		FillData();
		DisableEdition();
	}

	void GroupForm::OnDelete(wxCommandEvent& event)
	{
		auto* messageDialog = new wxMessageDialog(this,
				"Are you sure to delete this group? All passwords on this group will be deleted.", "Please Confirm",
				wxYES_NO | wxCENTRE);
		auto result = messageDialog->ShowModal();
		if (result == wxID_YES) {
			try {
				auto& commandRunner = wxGetApp().GetCommandRunner();
				CommandPtr delete_group_command{
						new DeleteGroupCommand(Application::instance(), group->get_id()) };
				commandRunner.run_command(delete_group_command);
			}
			catch (ApplicationException& ex) {
				wxMessageBox(ex.what(), "Error deleting group", wxICON_ERROR);
			}
		}
	}

	void GroupForm::OnAddPassword(wxCommandEvent& event)
	{
		auto* passwordForm = new CreatePasswordForm(this, category, group);
		passwordDetailSizer->Clear(true);
		passwordDetailSizer->Add(passwordForm, wxSizerFlags().Expand().Border(wxALL, 0));
		RedrawForm();
	}

	void GroupForm::OnPasswordCreated(const PasswordPtr& password)
	{
		FillPasswordsData();
		auto* passwordForm = new PasswordForm(this, password);
		passwordDetailSizer->Clear(true);
		passwordDetailSizer->Add(passwordForm, wxSizerFlags().Expand().Border(wxALL, 0));
		RedrawForm();
	}

	void GroupForm::OnPasswordDeleted()
	{
		FillPasswordsData();
		passwordDetailSizer->Clear(true);
		RedrawForm();
	}

	void GroupForm::EnableEdition()
	{
		nameText->SetEditable(true);
		urlText->SetEditable(true);
		descriptionText->SetEditable(true);

		editButton->Hide();
		saveButton->Show();
		cancelButton->Show();

		RedrawForm();
	}

	void GroupForm::DisableEdition()
	{
		nameText->SetEditable(false);
		urlText->SetEditable(false);
		descriptionText->SetEditable(false);

		editButton->Show();
		saveButton->Hide();
		cancelButton->Hide();

		RedrawForm();
	}

	void GroupForm::RedrawForm()
	{
		this->Layout();
	}
	bool GroupForm::Destroy()
	{
		passwordCreatedConnection.disconnect();
		passwordUpdatedConnection.disconnect();
		passwordDeletedConnection.disconnect();
		return wxWindowBase::Destroy();
	}
}
