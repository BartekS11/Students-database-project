#pragma once
#include <string>

enum Gender 
{
    Male,
    Female
};

static const char *enum_str[] = { "Male", "Female" };

class Student 
{
public:
    Student(std::string name, std::string lastName,
            std::string address, int indexNumber,
            std::string pesel, Gender gender);

    std::string showStudent() const;
    std::string getName() const;
    std::string getPESEL() const;
    std::string getStringForEnum( int enum_val ) const;

private:
    std::string _name;
    std::string _lastName;
    std::string _address; 
    int _indexNumber;
    std::string _pesel; 
    Gender _gender;
};