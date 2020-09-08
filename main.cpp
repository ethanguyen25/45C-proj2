//main.cpp

//Main file that calls every function

#include <iostream>
#include <string>
#include <sstream>

#include "firstSet.hpp"
#include "secondSet.hpp"
#include "structs.hpp"
#include "thirdSet.hpp"
#include "totalScores.hpp"
#include "cutpoints.hpp"

int main()
{
    int numOfArtifacts;
    std::cin >> numOfArtifacts;
    std::cin.ignore(1);

    int* totalPoints = gradedArtifacts(numOfArtifacts);
    int* relativeWeight = gradedArtifacts(numOfArtifacts);
    
    int numOfStudents;
    std::cin >> numOfStudents;

    studentInfo* stuArr = studentArray(numOfStudents);
    
    int numOfRawScores;
    std::cin >> numOfRawScores;
    
    int** rawScores = getRawScores(numOfRawScores, numOfArtifacts,
                                   numOfStudents, stuArr);

    computeTotals(numOfArtifacts, numOfStudents, totalPoints,
                  relativeWeight, rawScores, stuArr);

    int numOfCutpoints;
    std::cin >> numOfCutpoints;
    std::cin.ignore(1);

    cutpoints(numOfCutpoints, numOfStudents, stuArr);

    delete[] totalPoints;
    delete[] relativeWeight;
    delete[] stuArr;
    for (int n = 0; n < numOfStudents; ++n)
    {
        delete[] rawScores[n];
    }
    delete[] rawScores;
    
    return 0;
}



    /*  //SEE WHATS IN ARRAYS
    std::cout << "TP" << std::endl;
    for (int i = 0; i < numOfArtifacts; ++i)
    {
        std::cout << totalPoints[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "RW" << std::endl;
    for (int i = 0; i < numOfArtifacts; ++i)
    {
        std::cout << relativeWeight[i] << " ";
    }
    std::cout << std::endl; 
    */


    /* //SEE WHATS IN THE ARRAY/STRUCT 
    for (int n = 0; n < numOfStudents; ++n)
    {
        std::cout << stuArr[n].studentId << std::endl;
        std::cout << stuArr[n].gradeOption << std::endl;
        std::cout << stuArr[n].studentName << std::endl;
        std::cout << stuArr[n].totalPoints << std::endl;
    }
    */


    /*  //SEE WHATS IN RAWSCORES
    for (int n = 0; n < numOfStudents; ++n)
    {
        for (int nn = 0; nn < (1+numOfArtifacts); ++nn)
        {
            std::cout << rawScores[n][nn] << " ";
        }
        std::cout << std::endl;
    }
    */












