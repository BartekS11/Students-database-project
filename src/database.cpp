#include "database.hpp"

void Database::addStudentToDb(const Student & s) 
{
    _students.push_back(s);
}

std::string Database::showDbContent() const 
{
    std::string result = "";
    for(auto && student : _students) {
        result += student.showStudent();
    }
    return result;
}

std::string Database::showSortedStudentsByFirstName()
{
    std::string result = "";
    sort(_students.begin(), _students.end(), [](const Student& ls, const Student& rs){
        return ls.getName() < rs.getName();
    });
    for(auto && student : _students) {
        result += student.showStudent();
    }
    return result;
}

std::string Database::showSortedStudentsByPESELNumber()
{
    std::string result = "";
    sort(_students.begin(), _students.end(), [](const Student& ls, const Student& rs){
        return ls.getPESEL() < rs.getPESEL();
    });
    for(auto && student : _students) {
        result += student.showStudent();
    }
    return result;
}