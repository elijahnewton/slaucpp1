#pragma once

using namespace System;

namespace SLAUGRADING { namespace Models {

    public value struct Course {
        String^ courseCode;
        String^ courseName;
        double marksPercentage;
        String^ letterGrade;
        double gradePoints;

        Course(String^ code, String^ name, double marks, String^ grade, double points)
            : courseCode(code), courseName(name), marksPercentage(marks), letterGrade(grade), gradePoints(points) {}
    };

}}