#pragma once

using namespace System;

namespace SLAUGRADING { namespace Models {

    public value struct Student {
        int id;
        String^ registrationNumber;
        String^ fullName;
        DateTime createdAt;

        Student(int id, String^ regNo, String^ name, DateTime created)
            : id(id), registrationNumber(regNo), fullName(name), createdAt(created) {}
    };

}}