//cutpoints.cpp

//Reads each set of cutpoints and prints out the format (studentID, studentName, finalGrade)

#include <iostream>
#include <string>
#include <sstream>

#include "cutpoints.hpp"


void cutpoints(int numOfCutpoints, int numOfStudents,
               studentInfo* stuArr)
{
    std::string fournums;
    double a,b,c,d;
    for (int x = 1; x <= numOfCutpoints; ++x)
    {
        std::getline(std::cin, fournums);
        std::stringstream ss(fournums);
        ss >> a >> b >> c >> d;
        std::cout << "CUTPOINT SET " << x << std::endl;
        //std::cout << "GRADES " << a << " ";
        //std::cout << b << " " << c << " " << d << std::endl;
        for (int y = 0; y < numOfStudents; ++y)
        {
            //std::cout << "Bool " << (stuArr[y].totalPoints > a) << std::endl;
            if (stuArr[y].gradeOption == "P")
            {
                if (stuArr[y].totalPoints >= c)
                {
                    stuArr[y].finalGrade = "P";
                }
                else
                {
                    stuArr[y].finalGrade = "NP";
                }
            }
            else
            {
                if (stuArr[y].totalPoints >= a)
                {
                    stuArr[y].finalGrade = "A";
                }
                else if ((stuArr[y].totalPoints < a) and (stuArr[y].totalPoints >= b))
                {
                    stuArr[y].finalGrade = "B";
                }
                else if ((stuArr[y].totalPoints < b) and (stuArr[y].totalPoints >= c))
                {
                    stuArr[y].finalGrade = "C";
                }
                else if ((stuArr[y].totalPoints < c) and (stuArr[y].totalPoints >= d))
                {
                    stuArr[y].finalGrade = "D";
                }
                else
                {
                    stuArr[y].finalGrade = "F";
                }
            }
            std::cout << stuArr[y].studentId << " ";
            std::cout << stuArr[y].studentName << " ";
            std::cout << stuArr[y].finalGrade << std::endl;
        }

    }
}
