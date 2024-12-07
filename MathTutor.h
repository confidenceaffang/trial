// This is the header file for the Math Tutor version 6 project
#ifndef MATHTUTOR_H
#define MATHTUTOR_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime> // Needed for system time



using namespace std;



// Function Prototypes
void DisplayGameIntro();
string GetUserName();
int GetNumericValue();
string YesNoQuestion(string question);
void DisplaySummaryReport(const vector<vector<int>> &allQuestions);
vector<int> GenerateRandomQuestion(int mathLevel, int currentRange);
bool GiveThreeAttempts(string userName, vector<int> &currentQuestion, int &totalCorrect, int &totalIncorrect);
void CheckForLevelChange(int &totalCorrect, int &totalIncorrect, int &mathLevel, int &currentRange);
void SaveCurrentGame(string userName, const vector<vector<int>> &allQuestions, int mathLevel, int currentRange);
void LoadPreviousGame(string userName ,const vector<vector<int>> &allQuestions, int& mathLevel, int& currentRange);

#endif //MATHTUTOR_H