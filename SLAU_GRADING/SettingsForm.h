#pragma once

#include "Data\DatabaseHelper.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace SLAUGRADING::UI;
using namespace SLAUGRADING::Data;

namespace SLAUGRADING {

    public ref class SettingsForm : public System::Windows::Forms::Form
    {
    public:
        SettingsForm(void)
        {
            InitializeComponent();
            txtConn->Text = DatabaseConfig::ConnectionString;
        }

        property String^ ConnectionString;

    protected:
        ~SettingsForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container ^components;
        System::Windows::Forms::Label^ lblTitle;
        System::Windows::Forms::Label^ lblHelp;
        System::Windows::Forms::TextBox^ txtConn;
        System::Windows::Forms::Label^ lblStatus;
        System::Windows::Forms::Button^ btnTest;
        System::Windows::Forms::Button^ btnSave;
        System::Windows::Forms::Button^ btnClose;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = gcnew System::ComponentModel::Container();
            this->lblTitle = gcnew System::Windows::Forms::Label();
            this->lblHelp = gcnew System::Windows::Forms::Label();
            this->txtConn = gcnew System::Windows::Forms::TextBox();
            this->lblStatus = gcnew System::Windows::Forms::Label();
            this->btnTest = gcnew System::Windows::Forms::Button();
            this->btnSave = gcnew System::Windows::Forms::Button();
            this->btnClose = gcnew System::Windows::Forms::Button();
            this->SuspendLayout();
            //
            // lblTitle
            //
            this->lblTitle->AutoSize = true;
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
            this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->lblTitle->Location = System::Drawing::Point(24, 20);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(0, 32);
            this->lblTitle->Text = L"MySQL Connection";
            //
            // lblHelp
            //
            this->lblHelp->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblHelp->ForeColor = System::Drawing::Color::FromArgb(140, 140, 160);
            this->lblHelp->Location = System::Drawing::Point(24, 58);
            this->lblHelp->Name = L"lblHelp";
            this->lblHelp->Size = System::Drawing::Size(560, 34);
            this->lblHelp->Text = L"Enter the MySQL connection string below.\r\nExample: Server=localhost;Port=3306;Database=slau_grading;Uid=root;Pwd=yourpassword;";
            //
            // txtConn
            //
            this->txtConn->BackColor = System::Drawing::Color::FromArgb(245, 245, 250);
            this->txtConn->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtConn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtConn->ForeColor = System::Drawing::Color::FromArgb(45, 45, 58);
            this->txtConn->Location = System::Drawing::Point(24, 100);
            this->txtConn->Name = L"txtConn";
            this->txtConn->Size = System::Drawing::Size(560, 30);
            //
            // lblStatus
            //
            this->lblStatus->AutoSize = true;
            this->lblStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblStatus->ForeColor = System::Drawing::Color::FromArgb(140, 140, 160);
            this->lblStatus->Location = System::Drawing::Point(24, 142);
            this->lblStatus->Name = L"lblStatus";
            this->lblStatus->Size = System::Drawing::Size(0, 15);
            //
            // btnTest
            //
            this->btnTest->BackColor = System::Drawing::Color::FromArgb(70, 70, 90);
            this->btnTest->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnTest->FlatAppearance->BorderSize = 0;
            this->btnTest->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnTest->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnTest->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->btnTest->Location = System::Drawing::Point(24, 190);
            this->btnTest->Name = L"btnTest";
            this->btnTest->Size = System::Drawing::Size(160, 40);
            this->btnTest->Text = L"Test Connection";
            this->btnTest->UseVisualStyleBackColor = false;
            this->btnTest->Click += gcnew System::EventHandler(this, &SettingsForm::OnTest);
            //
            // btnSave
            //
            this->btnSave->BackColor = System::Drawing::Color::FromArgb(0, 191, 166);
            this->btnSave->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnSave->FlatAppearance->BorderSize = 0;
            this->btnSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnSave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnSave->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->btnSave->Location = System::Drawing::Point(200, 190);
            this->btnSave->Name = L"btnSave";
            this->btnSave->Size = System::Drawing::Size(180, 40);
            this->btnSave->Text = L"Save && Connect";
            this->btnSave->UseVisualStyleBackColor = false;
            this->btnSave->Click += gcnew System::EventHandler(this, &SettingsForm::OnSave);
            //
            // btnClose
            //
            this->btnClose->BackColor = System::Drawing::Color::FromArgb(70, 70, 90);
            this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnClose->FlatAppearance->BorderSize = 0;
            this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnClose->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnClose->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->btnClose->Location = System::Drawing::Point(400, 190);
            this->btnClose->Name = L"btnClose";
            this->btnClose->Size = System::Drawing::Size(120, 40);
            this->btnClose->Text = L"Close";
            this->btnClose->UseVisualStyleBackColor = false;
            this->btnClose->Click += gcnew System::EventHandler(this, &SettingsForm::OnClose);
            //
            // SettingsForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(30, 30, 46);
            this->ClientSize = System::Drawing::Size(620, 340);
            this->Controls->Add(this->btnClose);
            this->Controls->Add(this->btnSave);
            this->Controls->Add(this->btnTest);
            this->Controls->Add(this->lblStatus);
            this->Controls->Add(this->txtConn);
            this->Controls->Add(this->lblHelp);
            this->Controls->Add(this->lblTitle);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"SettingsForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Database Connection Settings";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        System::Void OnTest(System::Object^ sender, System::EventArgs^ e) {
            String^ conn = txtConn->Text->Trim();
            if (String::IsNullOrWhiteSpace(conn)) {
                lblStatus->Text = "Please enter a connection string.";
                lblStatus->ForeColor = ModernTheme::Danger;
                return;
            }
            lblStatus->Text = "Testing connection...";
            lblStatus->ForeColor = ModernTheme::Muted;
            this->Refresh();
            if (DatabaseHelper::TestConnection(conn)) {
                lblStatus->Text = "Connection successful!";
                lblStatus->ForeColor = ModernTheme::Success;
            }
            else {
                lblStatus->Text = "Connection failed. Check the string and server.";
                lblStatus->ForeColor = ModernTheme::Danger;
            }
        }

        System::Void OnSave(System::Object^ sender, System::EventArgs^ e) {
            String^ conn = txtConn->Text->Trim();
            if (String::IsNullOrWhiteSpace(conn)) {
                lblStatus->Text = "Please enter a connection string.";
                lblStatus->ForeColor = ModernTheme::Danger;
                return;
            }
            if (!DatabaseHelper::TestConnection(conn)) {
                lblStatus->Text = "Cannot save: connection failed.";
                lblStatus->ForeColor = ModernTheme::Danger;
                return;
            }
            DatabaseConfig::Save(conn);
            DatabaseHelper::InitializeSchema();
            this->ConnectionString = conn;
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();
        }

        System::Void OnClose(System::Object^ sender, System::EventArgs^ e) {
            this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->Close();
        }
    };

}