#pragma once

#include "Data\DatabaseHelper.h"
#include "Core\GradingEngine.h"
#include "UI\ModernTheme.h"
#include "SettingsForm.h"
#include "ResultsForm.h"
#include "RecordsForm.h"
#include "Models\Course.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace SLAUGRADING::UI;
using namespace SLAUGRADING::Data;
using namespace SLAUGRADING::Core;
using namespace SLAUGRADING::Models;

namespace SLAUGRADING {

    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
            SetupCourseColumns();
            AddCourseRow();
        }

    protected:
        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container ^components;

        System::Windows::Forms::Label^ lblTitle;
        System::Windows::Forms::Label^ lblSubtitle;
        System::Windows::Forms::Button^ btnSettings;
        System::Windows::Forms::Panel^ cardStudent;
        System::Windows::Forms::Label^ lblReg;
        System::Windows::Forms::TextBox^ txtReg;
        System::Windows::Forms::Label^ lblNameLbl;
        System::Windows::Forms::TextBox^ txtName;
        System::Windows::Forms::Label^ lblCoursesTitle;
        System::Windows::Forms::Button^ btnAdd;
        System::Windows::Forms::DataGridView^ dgvCourses;
        System::Windows::Forms::Button^ btnRemove;
        System::Windows::Forms::Label^ lblSummary;
        System::Windows::Forms::Button^ btnClear;
        System::Windows::Forms::Button^ btnView;
        System::Windows::Forms::Button^ btnCalc;
        System::Windows::Forms::Label^ lblGpa;
        System::Windows::Forms::Label^ lblStatus;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = gcnew System::ComponentModel::Container();
            this->lblTitle = gcnew System::Windows::Forms::Label();
            this->lblSubtitle = gcnew System::Windows::Forms::Label();
            this->btnSettings = gcnew System::Windows::Forms::Button();
            this->cardStudent = gcnew System::Windows::Forms::Panel();
            this->txtName = gcnew System::Windows::Forms::TextBox();
            this->lblNameLbl = gcnew System::Windows::Forms::Label();
            this->txtReg = gcnew System::Windows::Forms::TextBox();
            this->lblReg = gcnew System::Windows::Forms::Label();
            this->lblCoursesTitle = gcnew System::Windows::Forms::Label();
            this->btnAdd = gcnew System::Windows::Forms::Button();
            this->dgvCourses = gcnew System::Windows::Forms::DataGridView();
            this->btnRemove = gcnew System::Windows::Forms::Button();
            this->lblSummary = gcnew System::Windows::Forms::Label();
            this->btnClear = gcnew System::Windows::Forms::Button();
            this->btnView = gcnew System::Windows::Forms::Button();
            this->btnCalc = gcnew System::Windows::Forms::Button();
            this->lblGpa = gcnew System::Windows::Forms::Label();
            this->lblStatus = gcnew System::Windows::Forms::Label();
            this->cardStudent->SuspendLayout();
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
            this->lblTitle->Text = L"SLAU Grading System";
            //
            // lblSubtitle
            //
            this->lblSubtitle->AutoSize = true;
            this->lblSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(140, 140, 160);
            this->lblSubtitle->Location = System::Drawing::Point(24, 52);
            this->lblSubtitle->Name = L"lblSubtitle";
            this->lblSubtitle->Size = System::Drawing::Size(0, 15);
            this->lblSubtitle->Text = L"Enter student details and course marks to compute grades, GPA and CGPA.";
            //
            // btnSettings
            //
            this->btnSettings->BackColor = System::Drawing::Color::FromArgb(70, 70, 90);
            this->btnSettings->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnSettings->FlatAppearance->BorderSize = 0;
            this->btnSettings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnSettings->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnSettings->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->btnSettings->Location = System::Drawing::Point(800, 22);
            this->btnSettings->Name = L"btnSettings";
            this->btnSettings->Size = System::Drawing::Size(124, 36);
            this->btnSettings->Text = L"DB Settings";
            this->btnSettings->UseVisualStyleBackColor = false;
            this->btnSettings->Click += gcnew System::EventHandler(this, &MainForm::OnSettings);
            //
            // cardStudent
            //
            this->cardStudent->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->cardStudent->Location = System::Drawing::Point(24, 90);
            this->cardStudent->Name = L"cardStudent";
            this->cardStudent->Padding = System::Windows::Forms::Padding(16);
            this->cardStudent->Size = System::Drawing::Size(900, 96);
            //
            // txtName
            //
            this->txtName->BackColor = System::Drawing::Color::FromArgb(245, 245, 250);
            this->txtName->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtName->ForeColor = System::Drawing::Color::FromArgb(45, 45, 58);
            this->txtName->Location = System::Drawing::Point(380, 130);
            this->txtName->Name = L"txtName";
            this->txtName->Size = System::Drawing::Size(524, 30);
            //
            // lblNameLbl
            //
            this->lblNameLbl->AutoSize = true;
            this->lblNameLbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblNameLbl->ForeColor = System::Drawing::Color::FromArgb(140, 140, 160);
            this->lblNameLbl->Location = System::Drawing::Point(380, 108);
            this->lblNameLbl->Name = L"lblNameLbl";
            this->lblNameLbl->Size = System::Drawing::Size(0, 15);
            this->lblNameLbl->Text = L"Full Name";
            //
            // txtReg
            //
            this->txtReg->BackColor = System::Drawing::Color::FromArgb(245, 245, 250);
            this->txtReg->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtReg->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtReg->ForeColor = System::Drawing::Color::FromArgb(45, 45, 58);
            this->txtReg->Location = System::Drawing::Point(44, 130);
            this->txtReg->Name = L"txtReg";
            this->txtReg->Size = System::Drawing::Size(300, 30);
            //
            // lblReg
            //
            this->lblReg->AutoSize = true;
            this->lblReg->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblReg->ForeColor = System::Drawing::Color::FromArgb(140, 140, 160);
            this->lblReg->Location = System::Drawing::Point(44, 108);
            this->lblReg->Name = L"lblReg";
            this->lblReg->Size = System::Drawing::Size(0, 15);
            this->lblReg->Text = L"Registration Number";
            //
            // lblCoursesTitle
            //
            this->lblCoursesTitle->AutoSize = true;
            this->lblCoursesTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->lblCoursesTitle->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->lblCoursesTitle->Location = System::Drawing::Point(24, 200);
            this->lblCoursesTitle->Name = L"lblCoursesTitle";
            this->lblCoursesTitle->Size = System::Drawing::Size(0, 21);
            this->lblCoursesTitle->Text = L"Course Units";
            //
            // btnAdd
            //
            this->btnAdd->BackColor = System::Drawing::Color::FromArgb(0, 191, 166);
            this->btnAdd->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnAdd->FlatAppearance->BorderSize = 0;
            this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnAdd->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnAdd->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->btnAdd->Location = System::Drawing::Point(820, 196);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(104, 34);
            this->btnAdd->Text = L"+ Add Course";
            this->btnAdd->UseVisualStyleBackColor = false;
            this->btnAdd->Click += gcnew System::EventHandler(this, &MainForm::OnAddCourse);
            //
            // dgvCourses
            //
            this->dgvCourses->AllowUserToAddRows = false;
            this->dgvCourses->AllowUserToDeleteRows = false;
            this->dgvCourses->BackgroundColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->dgvCourses->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dgvCourses->EnableHeadersVisualStyles = false;
            this->dgvCourses->Location = System::Drawing::Point(24, 232);
            this->dgvCourses->MultiSelect = false;
            this->dgvCourses->Name = L"dgvCourses";
            this->dgvCourses->RowHeadersVisible = false;
            this->dgvCourses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgvCourses->Size = System::Drawing::Size(900, 250);
            this->dgvCourses->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::OnCellChanged);
            this->dgvCourses->CurrentCellDirtyStateChanged += gcnew System::EventHandler(this, &MainForm::OnCellDirty);
            //
            // btnRemove
            //
            this->btnRemove->BackColor = System::Drawing::Color::FromArgb(231, 76, 60);
            this->btnRemove->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnRemove->FlatAppearance->BorderSize = 0;
            this->btnRemove->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnRemove->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnRemove->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->btnRemove->Location = System::Drawing::Point(24, 492);
            this->btnRemove->Name = L"btnRemove";
            this->btnRemove->Size = System::Drawing::Size(110, 34);
            this->btnRemove->Text = L"- Remove";
            this->btnRemove->UseVisualStyleBackColor = false;
            this->btnRemove->Click += gcnew System::EventHandler(this, &MainForm::OnRemoveCourse);
            //
            // lblSummary
            //
            this->lblSummary->AutoSize = true;
            this->lblSummary->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblSummary->ForeColor = System::Drawing::Color::FromArgb(140, 140, 160);
            this->lblSummary->Location = System::Drawing::Point(150, 500);
            this->lblSummary->Name = L"lblSummary";
            this->lblSummary->Size = System::Drawing::Size(0, 15);
            //
            // btnClear
            //
            this->btnClear->BackColor = System::Drawing::Color::FromArgb(70, 70, 90);
            this->btnClear->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnClear->FlatAppearance->BorderSize = 0;
            this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnClear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnClear->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->btnClear->Location = System::Drawing::Point(560, 492);
            this->btnClear->Name = L"btnClear";
            this->btnClear->Size = System::Drawing::Size(110, 40);
            this->btnClear->Text = L"Clear";
            this->btnClear->UseVisualStyleBackColor = false;
            this->btnClear->Click += gcnew System::EventHandler(this, &MainForm::OnClear);
            //
            // btnView
            //
            this->btnView->BackColor = System::Drawing::Color::FromArgb(70, 70, 90);
            this->btnView->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnView->FlatAppearance->BorderSize = 0;
            this->btnView->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnView->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnView->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->btnView->Location = System::Drawing::Point(684, 492);
            this->btnView->Name = L"btnView";
            this->btnView->Size = System::Drawing::Size(120, 40);
            this->btnView->Text = L"View Records";
            this->btnView->UseVisualStyleBackColor = false;
            this->btnView->Click += gcnew System::EventHandler(this, &MainForm::OnViewRecords);
            //
            // btnCalc
            //
            this->btnCalc->BackColor = System::Drawing::Color::FromArgb(0, 191, 166);
            this->btnCalc->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnCalc->FlatAppearance->BorderSize = 0;
            this->btnCalc->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnCalc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnCalc->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
            this->btnCalc->Location = System::Drawing::Point(400, 560);
            this->btnCalc->Name = L"btnCalc";
            this->btnCalc->Size = System::Drawing::Size(180, 48);
            this->btnCalc->Text = L"Calculate && Save";
            this->btnCalc->UseVisualStyleBackColor = false;
            this->btnCalc->Click += gcnew System::EventHandler(this, &MainForm::OnCalculate);
            //
            // lblGpa
            //
            this->lblGpa->AutoSize = true;
            this->lblGpa->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
            this->lblGpa->ForeColor = System::Drawing::Color::FromArgb(0, 191, 166);
            this->lblGpa->Location = System::Drawing::Point(24, 570);
            this->lblGpa->Name = L"lblGpa";
            this->lblGpa->Size = System::Drawing::Size(0, 28);
            this->lblGpa->Text = L"GPA: -";
            //
            // lblStatus
            //
            this->lblStatus->AutoSize = true;
            this->lblStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->lblStatus->ForeColor = System::Drawing::Color::FromArgb(140, 140, 160);
            this->lblStatus->Location = System::Drawing::Point(24, 610);
            this->lblStatus->Name = L"lblStatus";
            this->lblStatus->Size = System::Drawing::Size(0, 25);
            this->lblStatus->Text = L"STATUS: -";
            //
            // MainForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(30, 30, 46);
            this->ClientSize = System::Drawing::Size(960, 700);
            this->Controls->Add(this->lblStatus);
            this->Controls->Add(this->lblGpa);
            this->Controls->Add(this->btnCalc);
            this->Controls->Add(this->btnView);
            this->Controls->Add(this->btnClear);
            this->Controls->Add(this->lblSummary);
            this->Controls->Add(this->btnRemove);
            this->Controls->Add(this->dgvCourses);
            this->Controls->Add(this->btnAdd);
            this->Controls->Add(this->lblCoursesTitle);
            this->Controls->Add(this->cardStudent);
            this->Controls->Add(this->btnSettings);
            this->Controls->Add(this->lblSubtitle);
            this->Controls->Add(this->lblTitle);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->Name = L"MainForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"SLAU Grading System";
            this->cardStudent->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCourses))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        void SetupCourseColumns() {
            dgvCourses->Columns->Clear();
            dgvCourses->Columns->Add("Code", "Course Code");
            dgvCourses->Columns->Add("Name", "Course Name");
            dgvCourses->Columns->Add("Marks", "Marks (%)");
            dgvCourses->Columns->Add("Grade", "Grade");
            dgvCourses->Columns->Add("Points", "Points");

            dgvCourses->Columns["Grade"]->ReadOnly = true;
            dgvCourses->Columns["Points"]->ReadOnly = true;

            dgvCourses->Columns["Marks"]->DefaultCellStyle->Alignment =
                DataGridViewContentAlignment::MiddleCenter;
            dgvCourses->Columns["Grade"]->DefaultCellStyle->Alignment =
                DataGridViewContentAlignment::MiddleCenter;
            dgvCourses->Columns["Grade"]->DefaultCellStyle->Font = ModernTheme::HeaderFont;
            dgvCourses->Columns["Points"]->DefaultCellStyle->Alignment =
                DataGridViewContentAlignment::MiddleCenter;

            dgvCourses->Columns["Code"]->FillWeight = 18;
            dgvCourses->Columns["Name"]->FillWeight = 40;
            dgvCourses->Columns["Marks"]->FillWeight = 14;
            dgvCourses->Columns["Grade"]->FillWeight = 14;
            dgvCourses->Columns["Points"]->FillWeight = 14;

            ModernTheme::StyleGrid(dgvCourses);
        }

        void AddCourseRow() {
            dgvCourses->Rows->Add("", "", "", "", "");
        }

        void OnCellDirty(Object^ sender, EventArgs^ e) {
            if (dgvCourses->IsCurrentCellDirty)
                dgvCourses->CommitEdit(DataGridViewDataErrorContexts::Commit);
        }

        void OnCellChanged(Object^ sender, DataGridViewCellEventArgs^ e) {
            if (e->RowIndex < 0) return;
            if (e->ColumnIndex == 2) {
                UpdateGradeForRow(e->RowIndex);
                UpdateSummary();
            }
        }

        void UpdateGradeForRow(int row) {
            Object^ marksObj = dgvCourses->Rows[row]->Cells["Marks"]->Value;
            double marks;
            if (marksObj != nullptr && Double::TryParse(marksObj->ToString(), marks)) {
                String^ grade = GradingEngine::GetLetterGrade(marks);
                double points = GradingEngine::GetGradePoints(grade);
                dgvCourses->Rows[row]->Cells["Grade"]->Value = grade;
                dgvCourses->Rows[row]->Cells["Points"]->Value = points.ToString("0.0");
                dgvCourses->Rows[row]->Cells["Grade"]->Style->ForeColor =
                    (grade == "F") ? ModernTheme::Danger : ModernTheme::TextDark;
            }
        }

        array<Course>^ CollectCourses() {
            System::Collections::Generic::List<Course>^ list =
                gcnew System::Collections::Generic::List<Course>();
            for each (DataGridViewRow^ row in dgvCourses->Rows) {
                if (row->IsNewRow) continue;
                String^ code = CellText(row, "Code");
                String^ name = CellText(row, "Name");
                String^ marksStr = CellText(row, "Marks");
                if (String::IsNullOrWhiteSpace(code) && String::IsNullOrWhiteSpace(marksStr))
                    continue;
                if (String::IsNullOrWhiteSpace(code) || String::IsNullOrWhiteSpace(name))
                    throw gcnew Exception("Each course needs a code and a name.");
                double marks;
                if (!Double::TryParse(marksStr, marks))
                    throw gcnew Exception("Enter a valid numeric mark for course '" + code + "'.");
                if (marks < 0 || marks > 100)
                    throw gcnew Exception("Marks for '" + code + "' must be between 0 and 100.");
                list->Add(GradingEngine::CreateCourse(code, name, marks));
            }
            return list->ToArray();
        }

        String^ CellText(DataGridViewRow^ row, String^ col) {
            Object^ v = row->Cells[col]->Value;
            return v == nullptr ? "" : v->ToString()->Trim();
        }

        void UpdateSummary() {
            try {
                array<Course>^ courses = CollectCourses();
                if (courses->Length == 0) {
                    lblGpa->Text = "GPA: -";
                    lblStatus->Text = "STATUS: -";
                    lblSummary->Text = "";
                    return;
                }
                double gpa = GradingEngine::CalculateGPA(courses);
                String^ status = GradingEngine::DetermineStatus(courses);
                lblGpa->Text = "GPA: " + gpa.ToString("0.00") + " / 5.00";
                lblStatus->Text = "STATUS: " + status;
                lblStatus->ForeColor = status == "PASS" ? ModernTheme::Success : ModernTheme::Danger;
                lblSummary->Text = courses->Length + " course(s) entered";
            }
            catch (Exception^) {
                lblGpa->Text = "GPA: -";
                lblStatus->Text = "STATUS: -";
            }
        }

        System::Void OnAddCourse(System::Object^ sender, System::EventArgs^ e) {
            AddCourseRow();
        }

        System::Void OnRemoveCourse(System::Object^ sender, System::EventArgs^ e) {
            if (dgvCourses->SelectedRows->Count > 0 && !dgvCourses->SelectedRows[0]->IsNewRow) {
                dgvCourses->Rows->Remove(dgvCourses->SelectedRows[0]);
            }
            else if (dgvCourses->Rows->Count > 1) {
                dgvCourses->Rows->RemoveAt(dgvCourses->Rows->Count - 1);
            }
            UpdateSummary();
        }

        System::Void OnClear(System::Object^ sender, System::EventArgs^ e) {
            txtReg->Clear();
            txtName->Clear();
            dgvCourses->Rows->Clear();
            AddCourseRow();
            lblGpa->Text = "GPA: -";
            lblStatus->Text = "STATUS: -";
            lblStatus->ForeColor = ModernTheme::Muted;
            lblSummary->Text = "";
        }

        System::Void OnSettings(System::Object^ sender, System::EventArgs^ e) {
            SettingsForm^ sf = gcnew SettingsForm();
            if (sf->ShowDialog(this) == System::Windows::Forms::DialogResult::OK) {
                MessageBox::Show(this, "Connection saved.", "Settings", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }

        System::Void OnViewRecords(System::Object^ sender, System::EventArgs^ e) {
            try {
                DataTable^ dt = DatabaseHelper::GetAllStudents();
                if (dt == nullptr || dt->Rows->Count == 0) {
                    MessageBox::Show(this, "No records found.", "View Records", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    return;
                }
                RecordsForm^ rf = gcnew RecordsForm(dt);
                rf->ShowDialog(this);
            }
            catch (Exception^ ex) {
                MessageBox::Show(this, "Error loading records: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        System::Void OnCalculate(System::Object^ sender, System::EventArgs^ e) {
            String^ reg = txtReg->Text->Trim();
            String^ name = txtName->Text->Trim();

            if (String::IsNullOrWhiteSpace(reg)) { ShowError("Enter a registration number."); txtReg->Focus(); return; }
            if (String::IsNullOrWhiteSpace(name)) { ShowError("Enter the student's full name."); txtName->Focus(); return; }

            array<Course>^ courses;
            try {
                courses = CollectCourses();
            }
            catch (Exception^ ex) {
                ShowError(ex->Message);
                return;
            }
            if (courses->Length == 0) { ShowError("Add at least one course with marks."); return; }

            if (String::IsNullOrWhiteSpace(DatabaseConfig::ConnectionString)) {
                SettingsForm^ sf = gcnew SettingsForm();
                if (sf->ShowDialog(this) != System::Windows::Forms::DialogResult::OK) {
                    ShowError("Database connection is required before saving.");
                    return;
                }
            }

            if (DatabaseHelper::RegistrationExists(reg)) {
                System::Windows::Forms::DialogResult dr = MessageBox::Show(this,
                    "A student with registration number '" + reg + "' already exists. Overwrite existing record?",
                    "Duplicate", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
                if (dr != System::Windows::Forms::DialogResult::Yes) return;
            }

            try {
                int studentId = DatabaseHelper::SaveStudent(reg, name);
                if (studentId < 0) { ShowError("Failed to save student."); return; }

                for each (Course c in courses)
                    DatabaseHelper::SaveCourse(studentId, c.courseCode, c.courseName, c.marksPercentage, c.letterGrade, c.gradePoints);

                double gpa = GradingEngine::CalculateGPA(courses);
                double cgpa = gpa;
                String^ status = GradingEngine::DetermineStatus(courses);
                DatabaseHelper::SaveResult(studentId, gpa, cgpa, status, courses->Length);

                ResultsForm^ rf = gcnew ResultsForm(studentId);
                rf->ShowDialog(this);
            }
            catch (Exception^ ex) {
                ShowError("Saving failed: " + ex->Message);
            }
        }

        void ShowError(String^ msg) {
            MessageBox::Show(this, msg, "Validation", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    };

}