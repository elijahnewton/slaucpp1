#pragma once

#include "Data\DatabaseHelper.h"
#include "UI\ModernTheme.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace SLAUGRADING::UI;
using namespace SLAUGRADING::Data;

namespace SLAUGRADING {

    public ref class ResultsForm : public System::Windows::Forms::Form
    {
    public:
        ResultsForm(int studentId)
        {
            this->studentId = studentId;
            InitializeComponent();
            LoadData();
        }

    protected:
        ~ResultsForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container ^components;
        int studentId;
        System::Windows::Forms::Label^ lblTitle;
        System::Windows::Forms::Panel^ cardTop;
        System::Windows::Forms::Label^ lblName;
        System::Windows::Forms::Label^ lblReg;
        System::Windows::Forms::Label^ lblStatus;
        System::Windows::Forms::Label^ lblCourses;
        System::Windows::Forms::Panel^ cardStats;
        System::Windows::Forms::Label^ lblGpa;
        System::Windows::Forms::Label^ lblCgpa;
        System::Windows::Forms::Label^ lblTableTitle;
        System::Windows::Forms::DataGridView^ dgvCourses;
        System::Windows::Forms::Button^ btnClose;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = gcnew System::ComponentModel::Container();
            this->lblTitle = gcnew System::Windows::Forms::Label();
            this->cardTop = gcnew System::Windows::Forms::Panel();
            this->lblCourses = gcnew System::Windows::Forms::Label();
            this->lblStatus = gcnew System::Windows::Forms::Label();
            this->lblReg = gcnew System::Windows::Forms::Label();
            this->lblName = gcnew System::Windows::Forms::Label();
            this->cardStats = gcnew System::Windows::Forms::Panel();
            this->lblCgpa = gcnew System::Windows::Forms::Label();
            this->lblGpa = gcnew System::Windows::Forms::Label();
            this->lblTableTitle = gcnew System::Windows::Forms::Label();
            this->dgvCourses = gcnew System::Windows::Forms::DataGridView();
            this->btnClose = gcnew System::Windows::Forms::Button();
            this->cardTop->SuspendLayout();
            this->cardStats->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCourses))->BeginInit();
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
            this->lblTitle->Text = L"Result Slip";
            //
            // cardTop
            //
            this->cardTop->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->cardTop->Location = System::Drawing::Point(24, 64);
            this->cardTop->Name = L"cardTop";
            this->cardTop->Size = System::Drawing::Size(720, 120);
            //
            // lblCourses
            //
            this->lblCourses->AutoSize = true;
            this->lblCourses->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblCourses->ForeColor = System::Drawing::Color::FromArgb(140, 140, 160);
            this->lblCourses->Location = System::Drawing::Point(560, 120);
            this->lblCourses->Name = L"lblCourses";
            this->lblCourses->Size = System::Drawing::Size(0, 15);
            //
            // lblStatus
            //
            this->lblStatus->AutoSize = true;
            this->lblStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->lblStatus->ForeColor = System::Drawing::Color::FromArgb(140, 140, 160);
            this->lblStatus->Location = System::Drawing::Point(560, 84);
            this->lblStatus->Name = L"lblStatus";
            this->lblStatus->Size = System::Drawing::Size(0, 25);
            //
            // lblReg
            //
            this->lblReg->AutoSize = true;
            this->lblReg->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblReg->ForeColor = System::Drawing::Color::FromArgb(140, 140, 160);
            this->lblReg->Location = System::Drawing::Point(44, 114);
            this->lblReg->Name = L"lblReg";
            this->lblReg->Size = System::Drawing::Size(0, 15);
            //
            // lblName
            //
            this->lblName->AutoSize = true;
            this->lblName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->lblName->ForeColor = System::Drawing::Color::FromArgb(45, 45, 58);
            this->lblName->Location = System::Drawing::Point(44, 84);
            this->lblName->Name = L"lblName";
            this->lblName->Size = System::Drawing::Size(0, 21);
            //
            // cardStats
            //
            this->cardStats->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->cardStats->Location = System::Drawing::Point(24, 200);
            this->cardStats->Name = L"cardStats";
            this->cardStats->Size = System::Drawing::Size(720, 80);
            //
            // lblCgpa
            //
            this->lblCgpa->AutoSize = true;
            this->lblCgpa->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->lblCgpa->ForeColor = System::Drawing::Color::FromArgb(0, 150, 130);
            this->lblCgpa->Location = System::Drawing::Point(400, 224);
            this->lblCgpa->Name = L"lblCgpa";
            this->lblCgpa->Size = System::Drawing::Size(0, 30);
            this->lblCgpa->Text = L"CGPA: -";
            //
            // lblGpa
            //
            this->lblGpa->AutoSize = true;
            this->lblGpa->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->lblGpa->ForeColor = System::Drawing::Color::FromArgb(0, 191, 166);
            this->lblGpa->Location = System::Drawing::Point(44, 224);
            this->lblGpa->Name = L"lblGpa";
            this->lblGpa->Size = System::Drawing::Size(0, 30);
            this->lblGpa->Text = L"GPA: -";
            //
            // lblTableTitle
            //
            this->lblTableTitle->AutoSize = true;
            this->lblTableTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->lblTableTitle->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->lblTableTitle->Location = System::Drawing::Point(24, 296);
            this->lblTableTitle->Name = L"lblTableTitle";
            this->lblTableTitle->Size = System::Drawing::Size(0, 21);
            this->lblTableTitle->Text = L"Courses";
            //
            // dgvCourses
            //
            this->dgvCourses->AllowUserToAddRows = false;
            this->dgvCourses->AllowUserToDeleteRows = false;
            this->dgvCourses->BackgroundColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->dgvCourses->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dgvCourses->EnableHeadersVisualStyles = false;
            this->dgvCourses->Location = System::Drawing::Point(24, 324);
            this->dgvCourses->Name = L"dgvCourses";
            this->dgvCourses->ReadOnly = true;
            this->dgvCourses->RowHeadersVisible = false;
            this->dgvCourses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgvCourses->Size = System::Drawing::Size(720, 160);
            //
            // btnClose
            //
            this->btnClose->BackColor = System::Drawing::Color::FromArgb(70, 70, 90);
            this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnClose->FlatAppearance->BorderSize = 0;
            this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnClose->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnClose->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->btnClose->Location = System::Drawing::Point(624, 494);
            this->btnClose->Name = L"btnClose";
            this->btnClose->Size = System::Drawing::Size(120, 38);
            this->btnClose->Text = L"Close";
            this->btnClose->UseVisualStyleBackColor = false;
            this->btnClose->Click += gcnew System::EventHandler(this, &ResultsForm::OnClose);
            //
            // ResultsForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(30, 30, 46);
            this->ClientSize = System::Drawing::Size(780, 560);
            this->Controls->Add(this->btnClose);
            this->Controls->Add(this->dgvCourses);
            this->Controls->Add(this->lblTableTitle);
            this->Controls->Add(this->cardStats);
            this->Controls->Add(this->cardTop);
            this->Controls->Add(this->lblTitle);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->Name = L"ResultsForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Student Results";
            this->cardTop->ResumeLayout(false);
            this->cardTop->PerformLayout();
            this->cardStats->ResumeLayout(false);
            this->cardStats->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCourses))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        void LoadData() {
            DataTable^ student = DatabaseHelper::GetStudentByRegNo(GetRegNoFromId(studentId));
            if (student != nullptr && student->Rows->Count > 0) {
                DataRow^ r = student->Rows[0];
                lblName->Text = safeString(r["full_name"]);
                lblReg->Text = "Reg: " + safeString(r["registration_number"]);
                if (r["status"] != DBNull::Value) {
                    lblStatus->Text = safeString(r["status"]);
                    lblStatus->ForeColor = safeString(r["status"]) == "PASS"
                        ? ModernTheme::Success : ModernTheme::Danger;
                    lblCourses->Text = safeString(r["total_courses"]) + " course(s)";
                    lblGpa->Text = "GPA: " + safeString(r["gpa"]);
                    lblCgpa->Text = "CGPA: " + safeString(r["cgpa"]);
                }
            }

            DataTable^ courses = DatabaseHelper::GetCoursesByStudentId(studentId);
            if (courses != nullptr) {
                dgvCourses->Columns->Clear();
                dgvCourses->Columns->Add("Code", "Code");
                dgvCourses->Columns->Add("Name", "Course Name");
                dgvCourses->Columns->Add("Marks", "Marks %");
                dgvCourses->Columns->Add("Grade", "Grade");
                dgvCourses->Columns->Add("Points", "Points");
                dgvCourses->Columns["Marks"]->DefaultCellStyle->Alignment =
                    DataGridViewContentAlignment::MiddleCenter;
                dgvCourses->Columns["Grade"]->DefaultCellStyle->Alignment =
                    DataGridViewContentAlignment::MiddleCenter;
                dgvCourses->Columns["Points"]->DefaultCellStyle->Alignment =
                    DataGridViewContentAlignment::MiddleCenter;
                dgvCourses->DataSource = courses;
            }
        }

        String^ GetRegNoFromId(int id) {
            DataTable^ dt = DatabaseHelper::GetAllStudents();
            if (dt != nullptr) {
                for each (DataRow^ r in dt->Rows) {
                    if (Convert::ToInt32(r["id"]) == id)
                        return safeString(r["registration_number"]);
                }
            }
            return "";
        }

        String^ safeString(Object^ o) {
            return o == nullptr || o == DBNull::Value ? "" : o->ToString();
        }

        System::Void OnClose(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }
    };

}