//thirdSet.cpp

//Builds a 2D array to store each students ID
// and points.

#include <iostream>
#include <string>
#include <sstream>

#include "thirdSet.hpp"


int** getRawScores(int numOfRawScores, int numOfArtifacts, 
                   int numOfStudents, studentInfo* stuArr)
{
    //Creation of 2D array
    int** thirdSet = new int*[numOfStudents];
    for (int n = 0; n < numOfStudents; ++n)
    {
        thirdSet[n] = new int[1 + numOfArtifacts];
    }
    
    //Reading inputs
    std::cin.ignore(1);
    int counter = 0;
    int add = 0;
    for (int nn = 0; nn < numOfRawScores; ++ nn)
    {
        std::string restOfline;
        std::getline (std::cin, restOfline);
        int stuID;
        std::stringstream ss2(restOfline);        
        ss2 >> stuID;
        //Check if student ID exists
        for (int i = 0; i < numOfStudents; ++i)
        {
            if (stuID == stuArr[i].studentId)
            {
                counter += 1;
            }
            else
            {
                
                continue;
            }
        }
        //If it exits, then add it to array
        if (counter > 0)
        {
            thirdSet[add][0] = stuID;
            for (int nnn = 1; nnn < (1+numOfArtifacts); ++nnn)
            {
                ss2 >> thirdSet[add][nnn]; 
            }
            add += 1;
        }
        else
        {
            continue;
        }
        counter = 0;
    }
    int counter2 = 0;
    
    //For student Id's that didn't show up when inputting Raw Scores, 
    //  their student ID's will be added to the set, with all raw
    //  scores of zero.
    for (int num = 0; num < numOfStudents; ++num)
    {
        for (int inner = 0; inner < numOfStudents; ++inner)
        {
            if (stuArr[num].studentId == thirdSet[inner][0])
            {
                counter2 = 0;
                break;
            }
            else
            {
                counter2 += 1;
                continue;
            }
        }
        if (counter2 > 0)
        {
            for (int replace = 0; replace < numOfStudents; ++replace)
            {
                if (thirdSet[replace][0] == 0)
                {
                    thirdSet[replace][0] = stuArr[num].studentId;
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
        else
        {
            counter2 = 0;
        }
    }
    return thirdSet;
}

