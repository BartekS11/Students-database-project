#include "student.hpp"

Student::Student(std::string name, std::string lastName, std::string address,
                int indexNumber, std::string pesel, Gender gender)
{
                _name = name;
                _lastName = lastName;
                _address = address;
                _indexNumber = indexNumber;
                _pesel = pesel;
                _gender = gender;
}

std::string Student::getStringForEnum( int enum_val ) const
{
    std::string tmp(enum_str[enum_val]);

    return tmp;
}

std::string Student::showStudent() const 
{
        return  _name + " " 
                + _lastName + "; "
                + _address + "; " 
                + std::to_string(_indexNumber) + "; " 
                + _pesel + "; " 
                + getStringForEnum(_gender) + " ";
}

std::string Student::getName() const
{
        return _name;
}

std::string Student::getPESEL() const
{
        return _pesel;
}