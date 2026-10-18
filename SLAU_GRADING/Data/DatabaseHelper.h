#pragma once

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace SLAUGRADING::Data {

    public ref class DatabaseConfig {
    public:
        static String^ ConnectionString;

        static void Save(String^ connStr) {
            ConnectionString = connStr;
            try {
                System::IO::File::WriteAllText(ConfigPath(), connStr);
            }
            catch (Exception^) {}
        }

        static bool Load() {
            try {
                if (System::IO::File::Exists(ConfigPath())) {
                    ConnectionString = System::IO::File::ReadAllText(ConfigPath());
                    return !String::IsNullOrWhiteSpace(ConnectionString);
                }
            }
            catch (Exception^) {}
            return false;
        }

        static String^ ConfigPath() {
            return System::IO::Path::Combine(
                System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetEntryAssembly()->Location),
                "db.config");
        }
    };

    public ref class DatabaseHelper {
    private:
        static MySqlConnection^ GetConnection() {
            if (String::IsNullOrWhiteSpace(DatabaseConfig::ConnectionString))
                throw gcnew InvalidOperationException("Database connection string is not configured.");
            return gcnew MySqlConnection(DatabaseConfig::ConnectionString);
        }

    public:
        static bool TestConnection(String^ connStr) {
            try {
                MySqlConnection^ conn = gcnew MySqlConnection(connStr);
                conn->Open();
                conn->Close();
                return true;
            }
            catch (Exception^) {
                return false;
            }
        }

        static bool InitializeSchema() {
            try {
                MySqlConnection^ conn = GetConnection();
                conn->Open();
                String^ sql =
                    "CREATE TABLE IF NOT EXISTS students ("
                    " id INT AUTO_INCREMENT PRIMARY KEY,"
                    " registration_number VARCHAR(20) UNIQUE NOT NULL,"
                    " full_name VARCHAR(100) NOT NULL);"
                    "CREATE TABLE IF NOT EXISTS courses ("
                    " id INT AUTO_INCREMENT PRIMARY KEY,"
                    " student_id INT NOT NULL,"
                    " course_code VARCHAR(20) NOT NULL,"
                    " course_name VARCHAR(100) NOT NULL,"
                    " marks_percentage DECIMAL(5,2) NOT NULL,"
                    " letter_grade VARCHAR(3) NOT NULL,"
                    " grade_points DECIMAL(3,2) NOT NULL,"
                    " FOREIGN KEY (student_id) REFERENCES students(id) ON DELETE CASCADE);"
                    "CREATE TABLE IF NOT EXISTS results ("
                    " id INT AUTO_INCREMENT PRIMARY KEY,"
                    " student_id INT NOT NULL,"
                    " gpa DECIMAL(3,2) NOT NULL,"
                    " cgpa DECIMAL(3,2) NOT NULL,"
                    " status VARCHAR(10) NOT NULL,"
                    " total_courses INT NOT NULL,"
                    " created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,"
                    " FOREIGN KEY (student_id) REFERENCES students(id) ON DELETE CASCADE);";
                MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
                cmd->ExecuteNonQuery();
                conn->Close();
                return true;
            }
            catch (Exception^) {
                return false;
            }
        }

        static bool RegistrationExists(String^ regNo) {
            try {
                MySqlConnection^ conn = GetConnection();
                conn->Open();
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "SELECT COUNT(*) FROM students WHERE registration_number = @reg", conn);
                cmd->Parameters->AddWithValue("@reg", regNo);
                int count = Convert::ToInt32(cmd->ExecuteScalar());
                conn->Close();
                return count > 0;
            }
            catch (Exception^) {
                return false;
            }
        }

        static int SaveStudent(String^ regNo, String^ fullName) {
            try {
                MySqlConnection^ conn = GetConnection();
                conn->Open();
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "INSERT INTO students (registration_number, full_name) VALUES (@reg, @name)",
                    conn);
                cmd->Parameters->AddWithValue("@reg", regNo);
                cmd->Parameters->AddWithValue("@name", fullName);
                cmd->ExecuteNonQuery();
                int id = Convert::ToInt32(cmd->LastInsertedId);
                conn->Close();
                return id;
            }
            catch (Exception^) {
                return -1;
            }
        }

        static bool SaveCourse(int studentId, String^ code, String^ name, double marks, String^ grade, double points) {
            try {
                MySqlConnection^ conn = GetConnection();
                conn->Open();
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "INSERT INTO courses (student_id, course_code, course_name, marks_percentage, letter_grade, grade_points) "
                    "VALUES (@sid, @code, @name, @marks, @grade, @points)", conn);
                cmd->Parameters->AddWithValue("@sid", studentId);
                cmd->Parameters->AddWithValue("@code", code);
                cmd->Parameters->AddWithValue("@name", name);
                cmd->Parameters->AddWithValue("@marks", marks);
                cmd->Parameters->AddWithValue("@grade", grade);
                cmd->Parameters->AddWithValue("@points", points);
                cmd->ExecuteNonQuery();
                conn->Close();
                return true;
            }
            catch (Exception^) {
                return false;
            }
        }

        static bool SaveResult(int studentId, double gpa, double cgpa, String^ status, int totalCourses) {
            try {
                MySqlConnection^ conn = GetConnection();
                conn->Open();
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "INSERT INTO results (student_id, gpa, cgpa, status, total_courses) "
                    "VALUES (@sid, @gpa, @cgpa, @status, @total)", conn);
                cmd->Parameters->AddWithValue("@sid", studentId);
                cmd->Parameters->AddWithValue("@gpa", gpa);
                cmd->Parameters->AddWithValue("@cgpa", cgpa);
                cmd->Parameters->AddWithValue("@status", status);
                cmd->Parameters->AddWithValue("@total", totalCourses);
                cmd->ExecuteNonQuery();
                conn->Close();
                return true;
            }
            catch (Exception^) {
                return false;
            }
        }

        static DataTable^ GetStudentByRegNo(String^ regNo) {
            try {
                MySqlConnection^ conn = GetConnection();
                conn->Open();
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "SELECT s.id, s.registration_number, s.full_name, r.gpa, r.cgpa, r.status, r.total_courses "
                    "FROM students s LEFT JOIN results r ON s.id = r.student_id "
                    "WHERE s.registration_number = @reg ORDER BY r.created_at DESC LIMIT 1", conn);
                cmd->Parameters->AddWithValue("@reg", regNo);
                MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
                DataTable^ dt = gcnew DataTable();
                da->Fill(dt);
                conn->Close();
                return dt;
            }
            catch (Exception^) {
                return nullptr;
            }
        }

        static DataTable^ GetCoursesByStudentId(int studentId) {
            try {
                MySqlConnection^ conn = GetConnection();
                conn->Open();
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "SELECT course_code, course_name, marks_percentage, letter_grade, grade_points "
                    "FROM courses WHERE student_id = @sid ORDER BY id", conn);
                cmd->Parameters->AddWithValue("@sid", studentId);
                MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
                DataTable^ dt = gcnew DataTable();
                da->Fill(dt);
                conn->Close();
                return dt;
            }
            catch (Exception^) {
                return nullptr;
            }
        }

        static DataTable^ GetAllStudents() {
            try {
                MySqlConnection^ conn = GetConnection();
                conn->Open();
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "SELECT s.id, s.registration_number, s.full_name, "
                    "COALESCE(r.gpa, 0) AS gpa, COALESCE(r.cgpa, 0) AS cgpa, "
                    "COALESCE(r.status, 'N/A') AS status, COALESCE(r.total_courses, 0) AS total_courses "
                    "FROM students s LEFT JOIN results r ON s.id = r.student_id "
                    "ORDER BY s.registration_number", conn);
                MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
                DataTable^ dt = gcnew DataTable();
                da->Fill(dt);
                conn->Close();
                return dt;
            }
            catch (Exception^) {
                return nullptr;
            }
        }
    };

}