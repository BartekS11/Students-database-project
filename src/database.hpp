#pragma once
#include "student.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

class Database
{
    public:
    void addStudentToDb(const Student & s);
    std::string showDbContent() const;
    std::string showSortedStudentsByFirstName();
    std::string showSortedStudentsByPESELNumber();

    private:
    std::vector<Student> _students;
};