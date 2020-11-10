// Program name: Lab1d
//
// Description: This lab will take user input of sentences and will
//          capitalize the first letter of each sentence.
//
// What's on your mind about this lab? 
//          This lab taught me how to find the first letter of each
//          sentence as well as edit a string within a void function.
//
// Author: Allester Ramayrat
//
// Date: 10/17/2020
//
// IDE Used: Visual Studio Code

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

void sentenceCapitalizer(char *userString);

int main() {
    const int MAX_SIZE = 1024;
    
    char userString[MAX_SIZE];
    
    //get user string
    cin.getline(userString, MAX_SIZE);

    //print userString uncapitalized
    cout << "The text before the modification:";
    cout << userString << '\n';

    //capitalize userString
    sentenceCapitalizer(userString);

    //print userString again
    cout << "The text after the modification:";
    cout << userString << '\n';

    return 0;
}

//************************************************************************
//* Function name: sentenceCapitalizer
//*
//* This function capitalizes the first letter in each sentence contained
//* in a passed C-string.
//*
//* Parameters:
//*    userString - pointer to the caller's C-string to be capitalized
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void sentenceCapitalizer(char *userString) {

    string punctString = ".?!";
    bool punctFound = true;

    //reads through index of userString
    for (int index = 0; index < strlen(userString); index++)
    {
        //reads thoroigh index of punctString
        for (int listIndex = 0; listIndex < punctString.size(); listIndex++)
        {
            //checks if current char is a punctuation (punctString)
            if (userString[index] == punctString[listIndex])
            {
                punctFound = true;
            }
        }

        //capitalize if there's punctuation and is a letter
        if (punctFound && isalpha(userString[index]))
        {
            userString[index] = toupper(userString[index]);
            punctFound = false;
        }
    }
}
