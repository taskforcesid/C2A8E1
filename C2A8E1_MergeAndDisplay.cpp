//
// Aladin Sidahmed U08614258 
// aladin.sidahmed@gmail.com
// C/C++ Programming II 
// Section 145010 Ray Mitchell 
// 06 MAR 2020
// C2A8E1_MergeAndDisplay.cpp
// Operating System: Windows 7 
// Visual Studio Community 2019 Version 16.3.2 
//
// Implements a function that would print the contents of the
// provided input lines, one line per file at a time
//

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_CHAR = 512;

static bool CheckFilesForEof(bool const eof_markers[], int count)
{
    //Scans the array for flags, return true if any is true
    for (int eof_index = 0; eof_index < count; eof_index++)
    {
        if (eof_markers[eof_index] == true)
            return true;
    }
    //No true flags were found within the array, return false
    return false;
}

void MergeAndDisplay(ifstream files[], size_t count)
{
    //create a flag array that will be used to mark the files 
    //that have not reached eof an initiate to true
    bool *eof_markers = new bool[count];
    for (int eof_index = 0; eof_index < (int)count; eof_index++)
        eof_markers[eof_index] = true;

    while (CheckFilesForEof(eof_markers, (int)count))
    {
        for (int fileIndex = 0; fileIndex < (int)count; fileIndex++)
        {
            char inputBuffer[MAX_CHAR];
            if (eof_markers[fileIndex])
            {
                if (files[fileIndex].getline(inputBuffer, MAX_CHAR))
                {
                    //print the value of the new line
                    cout << inputBuffer << "\n";
                }
                else
                {
                    //close the file for reading
                    eof_markers[fileIndex] = false;
                }
            }
        }
    }
    // return to memory the flags array
    delete[] eof_markers;
}
