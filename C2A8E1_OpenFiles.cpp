//
// Aladin Sidahmed U08614258 
// aladin.sidahmed@gmail.com
// C/C++ Programming II 
// Section 145010 Ray Mitchell 
// 06 MAR 2020
// C2A8E1_OpenFiles.cpp
// Operating System: Windows 7 
// Visual Studio Community 2019 Version 16.3.2 
//
// Implements a function that open a set of files passed as an array
//

#include <iostream>
#include <fstream>
using namespace std;

ifstream *OpenFiles(char * const fileNames[], size_t count)
{
    //check for a valid number of inputs
    if (count == 0)
    {
        cerr << "NO INPUT FILES SPECIFIED\n";
        exit(EXIT_FAILURE);
    }
    ifstream *filesArray = new ifstream[count];
    //loop through file by file and attempt to open the file
    //if the file doesn't open, close all previously opened files,
    //print an error to the screen, delete the memory allocated to 
    //the files, then exit the program with EXIT_FAILURE code
    for (int arraysIndex = 0; arraysIndex < (int)count; arraysIndex++)
    {
        filesArray[arraysIndex].open(fileNames[arraysIndex]);
        if (!filesArray[arraysIndex].is_open())
        {
            cerr << "Failed to open " << fileNames[arraysIndex];
            //Attempt to close any open files
            for (int openIndex = 0; openIndex < arraysIndex; openIndex++)
            {
                filesArray[openIndex].close();
            }
            //release all files from memory
            delete[] filesArray;
            exit(EXIT_FAILURE);
        }
    }
    return filesArray;
}
