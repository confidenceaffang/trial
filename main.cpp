/***************************************************************************
Course Section: Section 3 - 12:00 p.m.
Program: MathTutorV6
Programmers: Jacob, Seth and Confidence
Date: 12/2/2024
GitHub URL: https://github.com/KylianJ65/MathTutorV5.git
Description: This is the Funniest and Craziest Math
Tutor Game for Children. Version 3 invites you to the Math Tutor game.
It welcomes you, gives you fun math facts, it asks for your name,
it asks you a math question that has a variety of different equations,
and then it tells you whether you got the question right or wrong while
giving you the answer. Furthermore, if you got the question right
multiple times, you can increase the difficulty by "level 2" to be
challenged by advance math problems. However, if you get the same
problem wrong multiple times, it will decrease the level and put you
back to level 1, if you are on level 2. Either way, you can always play
this game and test your knowledge by choosing to continue or if you
want to stop, you can have the option. This is a fun program to
practice your knowledge on math while having fun. Throughout the program the
information such as the left number, math symbol, right number, answer, and
attempts is stored in a 2D vector. This allows us to make a summary report
at the end which the user can review to see what problems they had and how
they did on the test. To put it simply, Version 5 is an updated program of
Version 4, in which we subdivided the 4th Version into several factors,
so that the code looks more simple, neat, and appealing to the eye. In other words,
it teaches us how to clean codes so that it's not overly too complicated to look at.
MathtutorV6 will ask the user if they want to save the game and if they say yes,
the program will write a 2D vector to a text file (mathtutor.txt) and will also
let the user know how many questions were successfully saved. When the user goes
back into the game it will ask if they want to load their previous game. If they say yes,
then the previous game will be loaded from the 2D vector and then will let the user know
it was successfully loaded.
***************************************************************************/

#include "MathTutor.h"
#include <iostream> // Needed for cin/cout, /t for tab spacing, and left and right alignment
#include <string> // Needed for string variables - date types
#include <cstdlib> // Needed for random numbers
#include <limits> // Used for limits library
#include <vector> // used so we can make our 2D Vector
#include <iomanip> //for the setw
using namespace std;

int main() {
    int totalCorrect = 0; // Used to calculate the total correct questions a user has gotten
    int totalIncorrect = 0; // Used to calculate the total incorrect questions a user has gotten
    int mathLevel = 1; // Used for the math level
    int currentRange = 10; // Initial range of random numbers
    vector<vector<int> > questions; //stores every question the suer answers
    string userName, userInput; // Gets the user answer
    bool playAgain = true;

   // Displays the game's intro and gets the user's name
    DisplayGameIntro();
    userName = GetUserName();
   
    try {
        LoadPreviousGame(userName, questions, mathLevel, currentRange);
        if (!questions.empty() && userInput == "yes") {
            cout << "Welcome back, " << userName << "! Your previous game has been loaded." << endl;
        } else {
            cout << "No saved game found. Starting fresh!" << endl;
        }
    } catch (const runtime_error &e) {
        cout << e.what() << endl;
        cout << "Starting a new session instead." << endl;
    }
    // Seed the random number generator
    srand(time(0));

    // Shows if the user wants to play again
    while (playAgain) {
        // Generate a random math question
        vector<int> question = GenerateRandomQuestion(mathLevel, currentRange);

        // Allow the user to attempt the question
        GiveThreeAttempts(userName, question, totalCorrect, totalIncorrect);

        // Record the question for the summary
        questions.push_back(question);

        // Check for level changes
        CheckForLevelChange(totalCorrect, totalIncorrect, mathLevel, currentRange);

        // Ask the user if they want to play again
        userInput = YesNoQuestion(userName + "*\tDo you want to continue (y=yes | n=no)");
        playAgain = (userInput == "y" || userInput == "yes");
    }

    // Shows the summary of the questions in a proper display
    DisplaySummaryReport(questions);

    try {
        SaveCurrentGame(userName, questions, mathLevel, currentRange);
    } catch (runtime_error& e) {
        //Prints error message passed by throw statement
        cout << e.what() << endl;
        cout << "Cannot compute health info." << endl;

    }

    // Displaying to the User that the Program is Finished and that it will be back.
    cout << endl << "\tCheck back soon for the next version. Goodbye!" << endl;
    return 0;
}