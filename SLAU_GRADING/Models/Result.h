#pragma once

using namespace System;

namespace SLAUGRADING { namespace Models {

    public value struct Result {
        int id;
        String^ registrationNumber;
        String^ fullName;
        double gpa;
        double cgpa;
        String^ status;
        int totalCourses;
        DateTime createdAt;

        Result(int id, String^ regNo, String^ name, double gpa, double cgpa, String^ status, int courses, DateTime created)
            : id(id), registrationNumber(regNo), fullName(name), gpa(gpa), cgpa(cgpa), status(status), totalCourses(courses), createdAt(created) {}
    };

}}