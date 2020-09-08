//totalScores.cpp

//Uses all of the given information to compute and
//  display the TOTAL SCORES section.

#include <iostream>

#include "totalScores.hpp"


void computeTotals(int numOfArtifacts, int numOfStudents,
                   int* totalPoints, int* relativeWeight,
                   int** rawScores, studentInfo* stuArr)
{
    double classTotal = 0.0;
    double first, second, third;
    for (int x = 0; x < numOfStudents; ++x)
    {
        for (int y = 0; y < numOfArtifacts; ++y)
        {
            first = double(rawScores[x][(y+1)]);
            second = double(totalPoints[y]);
            third = double(relativeWeight[y]);
            classTotal += ((first/second) * third);
        }
        for (int z = 0; z < numOfStudents; ++z)
        {
            if (stuArr[z].studentId == rawScores[x][0])
            {
                stuArr[z].totalPoints = classTotal;
            }
            else
            {
                continue;
            }
        }
        classTotal = 0;
    }
    
    std::cout << "TOTAL SCORES" << std::endl;
    for (int n = 0; n < numOfStudents; ++n)
    {
        std::cout << stuArr[n].studentId << " ";
        std::cout << stuArr[n].studentName << " ";
        std::cout << stuArr[n].totalPoints << std::endl;
    }
}
