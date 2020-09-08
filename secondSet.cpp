//secondSet.cpp

//Using the struct defined in sceondSet.hpp, it will build 
// an array of structs that will include the students info

#include <iostream>
#include <string>
#include <sstream>

#include "secondSet.hpp"


studentInfo* studentArray(int numOfStudents)
{
    studentInfo* secondSet = new studentInfo[numOfStudents];

    std::cin.ignore(1);

    for (int n = 0; n < numOfStudents; ++n)
    {
        
        std::cin >> secondSet[n].studentId >> secondSet[n].gradeOption;
        std::cin.ignore(1);
        std::getline(std::cin, secondSet[n].studentName);
        //std::cout << secondSet[n].studentId << std::endl;
        
    }
    
    return secondSet;
}


