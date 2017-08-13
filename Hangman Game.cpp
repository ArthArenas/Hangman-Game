/*
Hangman.cpp

This program runs the Hangman Guessing-Word Game

by Arturo Arenas Esparza
Instituto Tecnológico y de Estudios Superiores de Monterrey
November 18, 2016
Version 1.0
*/
#include <iostream>
#include <ctype.h>  // toupper()
#include <fstream>  // ifstream()
#include <vector>
#include <cstdlib>  // srand(), rand()
#include <time.h>   // time()
#include <math.h>   // log()

using namespace std;

/*
display

This function displays the corresponding hangman depending on
the number of failed attempts, it also displays the current disclosed
characters and failed attempted letters

Parameters:
  int iN             Number of failed attempts
  string sHidden     Part that has been disclosed from the original word
  string sFailed     Failed attempts (character or wrong word)
  string sOriginal   The word to be guessed
Returns:
  void
*/
void display(int iN, string sHidden, string sFailed, string sOriginal) {
    switch(iN) {
    case 0:
            cout << "____________" << endl;
            cout << "|          |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|    FAILED LETTERS: " << sFailed << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|__  WORD: " << sHidden << endl;
            break;
    case 1:
            cout << "____________" << endl;
            cout << "|          |" << endl;
            cout << "|          O" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|    FAILED LETTERS: " << sFailed << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|__  WORD: " << sHidden << endl;
            break;
    case 2:
            cout << "____________" << endl;
            cout << "|          |" << endl;
            cout << "|          O" << endl;
            cout << "|          |" << endl;
            cout << "|          |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|    FAILED LETTERS: " << sFailed << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|__  WORD: " << sHidden << endl;
            break;
    case 3:
            cout << "____________" << endl;
            cout << "|          |" << endl;
            cout << "|          O" << endl;
            cout << "|         /|" << endl;
            cout << "|          |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|    FAILED LETTERS: " << sFailed << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|__  WORD: " << sHidden << endl;
            break;
    case 4:
            cout << "____________" << endl;
            cout << "|          |" << endl;
            cout << "|          O" << endl;
            cout << "|         /|\\" << endl;
            cout << "|          |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|    FAILED LETTERS: " << sFailed << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|__  WORD: " << sHidden << endl;
            break;
    case 5:
            cout << "____________" << endl;
            cout << "|          |" << endl;
            cout << "|          O" << endl;
            cout << "|         /|\\" << endl;
            cout << "|          |" << endl;
            cout << "|         /" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|    FAILED LETTERS: " << sFailed << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|__  WORD: " << sHidden << endl;
            break;
    case 6:
            cout << "____________" << endl;
            cout << "|          |" << endl;
            cout << "|          O" << endl;
            cout << "|         /|\\" << endl;
            cout << "|          |" << endl;
            cout << "|         / \\" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|    FAILED LETTERS: " << sFailed << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|__  WORD: " << sHidden << endl;
            cout << endl;
            cout << "The right answer was: " << sOriginal << endl;
            break;
    }
}

/*
chooseInputFile

This function deals with getting the input file from the user

Parameters:
  vector<string>& vWords    Stores the words from the input file that we read
  bool& bFile               Stores whether the input file exists in the program or not
Returns:
  void
*/
void chooseInputFile(vector<string>& vWords, bool& bFile) {
    string sLine;
    string sInputFile;
    cout << "Enter your input file or type the number of an existing one (see options below)\n";
    cout << "1. Countries of the world\n";
    cout << "2. Most common first names in the US\n";
    cout << "3. Last names of US presidents\n";
    cout << "4. Animals\n";
    cout << "Select / Input word bank: ";
    cin >> sInputFile; // Reads the input file from the user
    if(sInputFile[0] > '0' && sInputFile[0] < '5' && !sInputFile[1]) {
        switch(sInputFile[0]) {
        case '1':
            sInputFile = "Countries.txt";
            break;
        case '2':
            sInputFile = "Names.txt";
            break;
        case '3':
            sInputFile = "Presidents.txt";
            break;
        case '4':
            sInputFile = "Animals.txt";
            break;
        }
    }
    ifstream file(sInputFile); // Sets a file to be found
    // If the file is in the program then we get in here
    if(file.is_open()) {
        bFile = true; // Set boolean variable to true so that we don't ask the user what to do again
        while(getline(file,sLine)) {
            vWords.push_back(sLine); // Read every word from the input file and store it into a vector since we don't know its size
        }
        file.close();
    }
    // If the file is not in the program then we notify the user
    else {
        cout << "Your file is not in the program yet\n";
        bFile = false; // Set boolean variable to false so that we can ask the user to put his input file again
    }
}

/*
displayStats

This function displays the stats after the player is done with playing the hangman game

Parameters:
  int& iWon        Stores the amount of games won by the user
  int& iLost       Stores the amount of games lost by the user
  double& dScore   Stores the total score of the user
Returns:
  void
*/
void displayStats(int& iWon, int& iLost, double& dScore) {
    cout << "Thanks for playing !!!\n";
    cout << "Games Won: " << iWon << endl;
    cout << "Games Lost: " << iLost << endl;
    cout << "Total Score: " << int(dScore) << endl;
}

/*
checkCharacter

This function processes the case when the user's attempt is a character

Parameters:
  string sL          User's attempt
  string& sHidden    Part that has been disclosed from the original word
  string& sFailed    Failed Attempts (character or Wrong Word)
  string sOriginal   The word to be guessed
  int iL             Size of the original word
  int& iN            Number of failed attempts
Returns:
  void
*/
void checkCharacter(string sL, string sOriginal, string& sFailed, string& sHidden, int& iN, int iL) {
    int iSpot = 0; // Stores 0 if the attempt does not match with any letter from the original word and a natural value otherwise
    for(int i = 0; i < iL; i++) {
        // Compare letter by letter to see if it matches each one of them, we compare caps so that it's not a factor of mistake
        if(toupper(sL[0]) == toupper(sOriginal[i])) {
            sHidden[i] = sOriginal[i]; // Disclose the matched characters
            iSpot++; // Tell iSpot when we have found at least one match
        }
    }
    // If no match was found add the character to the failed attempts
    if(iSpot == 0) {
        iN++; // Another failed attempt
        sFailed += sL;
        sFailed += "  ";
    }
    else {
        cout << "You guessed " << iSpot << " letters from the word !\n"; // Tell the user how many characters he guessed if any
    }
}

/*
checkWord

This function processes the case when the user attempts to guess the whole word

Parameters:
  string sL          User's attempt
  string& sHidden    Part that has been disclosed from the original word
  string& sFailed    Failed Attempts (character or Wrong Word)
  string sOriginal   The word to be guessed
  int& iN            Number of failed attempts
Returns:
  void
*/
void checkWord(string sL, string sOriginal, string& sFailed, string& sHidden, int& iN, int& iM) {
    // If it's the same word then both should have the same size
    if(sL.size() == sOriginal.size()) {
        int j = 0; // Stores the index of the letter being analyzed
        int iSpott = 0; // Stores 0 if the words are the same and a natural number otherwise
        // Check every letter in their caps version so that caps are not a factor of mistake
        while(sL[j]) {
            if(toupper(sL[j]) != toupper(sOriginal[j])) {
                iSpott++; // We tell iSpott that we have found a difference between the two words
                break;
            }
            j++;
        }
        // If the attempted word is the right answer then get into this loop
        if(iSpott == 0) {
            iM = 7-iN; // Save how many attempts had been failed
            iN = 7; // Change the value of iN so that we get out of the guessing loop
            sHidden = sOriginal; // Disclose the whole word
        }
        // If there's a different between the two words, we add it to the failed attempts string and report it as "Wrong Word"
        else {
            iN++;
            sFailed += "Wrong Word  ";
        }
    }
    // If the attempted word is not even the size of the original word then it's not correct and a "Wrong Word" report is stored
    else {
        iN++;
        sFailed += "Wrong Word  ";
    }
}

/*
main

This is the main function that runs the program

Parameters:
  void
Returns:
  0
*/
int main() {
    vector<string> vWords; // Stores the words read from the input file
    bool bFile = true; // Stores whether the input file exists in the program or not
    // Invoke the function to choose the input file we are going to play with
    do {
        chooseInputFile(vWords, bFile);
    } while(!bFile); // Repeat until the user gives a valid input file
    char cAns; // Stores the decision of the user on playing or not
    int iWon = 0; // Stores the amount of won games
    int iLost = 0; // Stores the amount of lost games
    double dScore = 0; // Stores the total score
    cout << "Try to guess the word !! You can either try to guess a single letter or the whole word, good luck!" << endl;
    cout << "Do you want to play? (Y/N): ";
    cin >> cAns;
    // Play if he did not say No by answering 'N' or 'n'
    while(!(cAns == 'N' || cAns == 'n')) {
        int iN = 0; // Stores the amount of failed attempts
        int iS = int(vWords.size()); // Stores the amount of words from the input file
        int iM = 0; // Helps me calculate the score when the user has attempted and succeeded to guess the whole word
        double dLocalScore = 0; // Stores local score
        srand(time(NULL));
        iS = rand() % iS;
        string sFailed = ""; // Stores the failed attempts (characters and Wrong Words)
        string sOriginal = vWords[iS]; // Stores the random word from the input file
        string sHidden = sOriginal; // Initializes the Hidden word to be the size of the Original word
        int iL = int(sOriginal.size()); // Stores the number of letters in the word
        // Initialize the Hidden word to asterisks (*)
        for(int i = 0; i < iL; i++) {
            sHidden[i] = '*';
        }
        // While the user has attempts remaining and has not guessed the word yet
        while(iN < 6 && sHidden != sOriginal) {
            display(iN, sHidden, sFailed, sOriginal); // Displays the current hangman
            string sL; // Stores the user's attempt
            cout << "Enter a letter or try to match the whole word: ";
            cin >> sL;
            // If the attempt is a character, check if it's in the word
            if(int(sL.size()) == 1) {
                checkCharacter(sL, sOriginal, sFailed, sHidden, iN, iL);
            }
            // If the user tried to match the whole word, we check if it's the same
            else {
                checkWord(sL, sOriginal, sFailed, sHidden, iN, iM);
            }
        }
        // If the user has exhausted all of his 6 attempts we count it as a lost game and give him a score of 0, we also display the corresponding case
        if(iN == 6) {
            display(iN, sHidden, sFailed, sOriginal);
            iLost++; // Count it as a lost game
            dLocalScore = 0; // He gets a score of 0
        }
        // If the user won the game we count it as a won game and give him a score, we also display the current hangman drawing with the disclosed word
        else {
            display((iN - iM), sHidden, sFailed, sOriginal);
            cout << "Congratulations !!! You saved a life !!!\n\n";
            iWon++; // Count it as a won game
            dLocalScore = log(iN - iM + 1) * 500; // We give the user a score determined by the shown formula
            dScore += (1000 - dLocalScore); // Add the user's score to his total score
        }
        dLocalScore = 0; // Reset the local score to 0
        cout << "Do you want to play again? (Y/N)" << endl;
        cin >> cAns;
    }
    // After the user is done with playing this lovely game, we display his stats
    displayStats(iWon, iLost, dScore);
    // End
    return 0;
}
