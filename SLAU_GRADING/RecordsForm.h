#pragma once

#include "Data\DatabaseHelper.h"
#include "UI\ModernTheme.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace SLAUGRADING::UI;
using namespace SLAUGRADING::Data;

namespace SLAUGRADING {

    public ref class RecordsForm : public System::Windows::Forms::Form
    {
    public:
        RecordsForm(DataTable^ students)
        {
            this->students = students;
            InitializeComponent();
            LoadData();
        }

    protected:
        ~RecordsForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container ^components;
        DataTable^ students;
        System::Windows::Forms::Label^ lblTitle;
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Button^ btnClose;
        System::Windows::Forms::DataGridView^ dgv;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = gcnew System::ComponentModel::Container();
            this->lblTitle = gcnew System::Windows::Forms::Label();
            this->txtSearch = gcnew System::Windows::Forms::TextBox();
            this->btnClose = gcnew System::Windows::Forms::Button();
            this->dgv = gcnew System::Windows::Forms::DataGridView();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv))->BeginInit();
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
            this->lblTitle->Text = L"Saved Records";
            //
            // txtSearch
            //
            this->txtSearch->BackColor = System::Drawing::Color::FromArgb(245, 245, 250);
            this->txtSearch->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtSearch->ForeColor = System::Drawing::Color::FromArgb(45, 45, 58);
            this->txtSearch->Location = System::Drawing::Point(24, 64);
            this->txtSearch->Name = L"txtSearch";
            this->txtSearch->Size = System::Drawing::Size(340, 30);
            this->txtSearch->TextChanged += gcnew System::EventHandler(this, &RecordsForm::OnSearch);
            //
            // btnClose
            //
            this->btnClose->BackColor = System::Drawing::Color::FromArgb(70, 70, 90);
            this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnClose->FlatAppearance->BorderSize = 0;
            this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnClose->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnClose->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->btnClose->Location = System::Drawing::Point(716, 64);
            this->btnClose->Name = L"btnClose";
            this->btnClose->Size = System::Drawing::Size(108, 30);
            this->btnClose->Text = L"Close";
            this->btnClose->UseVisualStyleBackColor = false;
            this->btnClose->Click += gcnew System::EventHandler(this, &RecordsForm::OnClose);
            //
            // dgv
            //
            this->dgv->AllowUserToAddRows = false;
            this->dgv->AllowUserToDeleteRows = false;
            this->dgv->BackgroundColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->dgv->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dgv->EnableHeadersVisualStyles = false;
            this->dgv->Location = System::Drawing::Point(24, 112);
            this->dgv->MultiSelect = false;
            this->dgv->Name = L"dgv";
            this->dgv->ReadOnly = true;
            this->dgv->RowHeadersVisible = false;
            this->dgv->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgv->Size = System::Drawing::Size(800, 380);
            this->dgv->DoubleClick += gcnew System::EventHandler(this, &RecordsForm::OnOpen);
            //
            // RecordsForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(30, 30, 46);
            this->ClientSize = System::Drawing::Size(860, 540);
            this->Controls->Add(this->dgv);
            this->Controls->Add(this->btnClose);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->lblTitle);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->Name = L"RecordsForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Saved Records";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        void LoadData() {
            dgv->Columns->Clear();
            dgv->Columns->Add("id", "ID");
            dgv->Columns["id"]->Visible = false;
            dgv->Columns->Add("registration_number", "Reg Number");
            dgv->Columns->Add("full_name", "Full Name");
            dgv->Columns->Add("gpa", "GPA");
            dgv->Columns->Add("cgpa", "CGPA");
            dgv->Columns->Add("status", "Status");
            dgv->Columns->Add("total_courses", "Courses");
            dgv->Columns["gpa"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dgv->Columns["cgpa"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dgv->Columns["status"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dgv->Columns["total_courses"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dgv->DataSource = students->Copy();
        }

        void OnSearch(Object^ sender, EventArgs^ e) {
            String^ q = txtSearch->Text->Trim()->ToLower();
            DataView^ dv = students->DefaultView;
            if (String::IsNullOrWhiteSpace(q))
                dv->RowFilter = "";
            else
                dv->RowFilter = "full_name LIKE '%" + q + "%' OR registration_number LIKE '%" + q + "%'";
            dgv->DataSource = dv->ToTable();
            RehideId();
        }

        void RehideId() {
            if (dgv->Columns["id"] != nullptr)
                dgv->Columns["id"]->Visible = false;
        }

        System::Void OnOpen(System::Object^ sender, System::EventArgs^ e) {
            if (dgv->SelectedRows->Count == 0) return;
            int id = Convert::ToInt32(dgv->SelectedRows[0]->Cells["id"]->Value);
            ResultsForm^ rf = gcnew ResultsForm(id);
            rf->ShowDialog(this);
        }

        System::Void OnClose(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }
    };

}