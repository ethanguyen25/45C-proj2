//firstSet.cpp

//Given the number of artifacts, it will build an array
//  with that size.

#include <iostream>
#include <string>
#include <sstream>


int* gradedArtifacts(int numOfArtifacts)
{
    int* firstSet = new int[numOfArtifacts];
    
    std::string line;
    std::getline (std::cin, line);
    std::stringstream ss1(line);

    for (int n = 0; n < numOfArtifacts; ++n)
    {
        ss1 >> firstSet[n];
    }
    
    return firstSet;
}
