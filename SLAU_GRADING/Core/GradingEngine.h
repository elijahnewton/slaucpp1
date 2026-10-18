#pragma once

#include "..\Models\Course.h"

using namespace System;
using namespace SLAUGRADING::Models;

namespace SLAUGRADING::Core {

    public ref class GradingEngine abstract sealed {
    public:
        static double PassMark = 50.0;

        static String^ GetLetterGrade(double percentage) {
            if (percentage < 0 || percentage > 100)
                throw gcnew ArgumentOutOfRangeException("percentage must be between 0 and 100");
            if (percentage >= 90) return "A";
            if (percentage >= 85) return "B+";
            if (percentage >= 80) return "B";
            if (percentage >= 75) return "B-";
            if (percentage >= 70) return "C+";
            if (percentage >= 65) return "C";
            if (percentage >= 60) return "C-";
            if (percentage >= 50) return "D";
            return "F";
        }

        static double GetGradePoints(String^ letterGrade) {
            if (letterGrade == "A") return 5.0;
            if (letterGrade == "B+") return 4.5;
            if (letterGrade == "B") return 4.0;
            if (letterGrade == "B-") return 3.5;
            if (letterGrade == "C+") return 3.0;
            if (letterGrade == "C") return 2.5;
            if (letterGrade == "C-") return 2.0;
            if (letterGrade == "D") return 1.0;
            return 0.0;
        }

        static Course CreateCourse(String^ code, String^ name, double marks) {
            String^ grade = GetLetterGrade(marks);
            double points = GetGradePoints(grade);
            return Course(code, name, marks, grade, points);
        }

        static double CalculateGPA(array<Course>^ courses) {
            if (courses == nullptr || courses->Length == 0)
                return 0.0;
            double total = 0.0;
            for each (Course c in courses)
                total += c.gradePoints;
            return Math::Round(total / courses->Length, 2);
        }

        static String^ DetermineStatus(array<Course>^ courses) {
            for each (Course c in courses) {
                if (c.marksPercentage < PassMark)
                    return "FAIL";
            }
            return "PASS";
        }
    };

}