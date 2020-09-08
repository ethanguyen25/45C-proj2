//structs.hpp

//Creation of the student struct.

#include <iostream>
#include <string>


#ifndef STRUCTS_HPP
#define STRUCTS_HPP

struct studentInfo
{
    int studentId;
    std::string gradeOption;
    std::string studentName;
    double totalPoints;
    std::string finalGrade;
};

#endif
