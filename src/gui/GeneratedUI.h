///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/listctrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>

///////////////////////////////////////////////////////////////////////////

namespace NSPass::GUI
{
	///////////////////////////////////////////////////////////////////////////////
	/// Class BaseCategoryForm
	///////////////////////////////////////////////////////////////////////////////
	class BaseCategoryForm : public wxPanel
	{
		private:

		protected:
			enum
			{
				CategoryIdText_Ctrl = 1000,
				CategoryNameText_Ctrl,
				CategoryGroupCountText_Ctrl,
				CategoryPasswordCountText_Ctrl
			};

			wxStaticText* idLabel;
			wxStaticText* idText;
			wxStaticText* nameLabel;
			wxTextCtrl* nameText;
			wxStaticText* groupCountLabel;
			wxStaticText* groupCountText;
			wxStaticText* passwordCountLabel;
			wxStaticText* passwordCountText;

			// Virtual event handlers, overide them in your derived class
			virtual void OnTextChanged( wxCommandEvent& event ) = 0;


		public:

			BaseCategoryForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
			~BaseCategoryForm();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class BaseGroupForm
	///////////////////////////////////////////////////////////////////////////////
	class BaseGroupForm : public wxPanel
	{
		private:

		protected:
			enum
			{
				GroupIdText_Ctrl = 1000,
				GroupNameText_Ctrl
			};

			wxStaticText* idLabel;
			wxStaticText* idText;
			wxStaticText* nameLabel;
			wxTextCtrl* nameText;
			wxStaticText* urlLabel;
			wxTextCtrl* urlText;
			wxStaticText* descriptionLabel;
			wxTextCtrl* descriptionText;
			wxStaticBoxSizer* passwordSizer;
			wxListCtrl* passwordsList;
			wxStaticBoxSizer* passwordDetailSizer;

			// Virtual event handlers, overide them in your derived class
			virtual void OnTextChanged( wxCommandEvent& event ) = 0;
			virtual void OnItemSelected( wxListEvent& event ) = 0;


		public:

			BaseGroupForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
			~BaseGroupForm();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class BasePasswordForm
	///////////////////////////////////////////////////////////////////////////////
	class BasePasswordForm : public wxPanel
	{
		private:

		protected:
			wxStaticText* idLabel;
			wxStaticText* idText;
			wxStaticText* usernameLabel;
			wxTextCtrl* usernameText;
			wxStaticText* urlLabel;
			wxTextCtrl* urlText;
			wxStaticText* descriptionLabel;
			wxTextCtrl* descriptionText;
			wxStaticText* passwordLabel;
			wxTextCtrl* passwordText;
			wxButton* copyPasswordButton;
			wxButton* openUrlButton;
			wxButton* changePasswordButton;

			// Virtual event handlers, overide them in your derived class
			virtual void OnCopy( wxCommandEvent& event ) = 0;
			virtual void OnOpenUrl( wxCommandEvent& event ) = 0;
			virtual void OnChangePassword( wxCommandEvent& event ) = 0;


		public:

			BasePasswordForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
			~BasePasswordForm();

	};

} // namespace NSPass::GUI
