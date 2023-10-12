/*
*   Abdullah Muhammad
*   Movie Puzzle Word Finder Project
*   Started on 5/08/2023
*/

#include <iostream>
#include<Windows.h>
#include <windows.h>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <string>
//#include <unistd.h>


using namespace std;

void display(); 
string convert(string);
void timer();
int gameFunction();

int main()
{
    string name;
    cout << "Enter Player Name : ";
    getline(cin,name);
    cout << endl;
 

    int score = 0;
    char input; //playAgain input (Y/y/N/n)

    do { //game code
        system("cls");
        cout << "Welcome, " << name << "!\n\n" << endl;
        display();
        score += gameFunction();
        cout << "\nWould you like to play again ( y/n ) : ";
        cin >> input;
        cout << endl;
    } while (input != 'n' && input != 'no' && input != 'NO' && input != 'No');
    cout << "Thank you for playing, " << name << "! Your score is " << score << "\n" << endl;
    cout << "--------------------------------------------------" << endl;

}

void display() {
    cout << "Word Searching Puzzle Game\n" << endl;
    cout << "A hidden word puzzle is displayed on the screen. You have to guess the hidden word to increase your points.\n" << endl;
    cout << "Previous high score is: 4\n" << endl;
}

void timer() {
    
    short minutes = 0;
    short seconds = 3;
    int time;

    time = minutes != 0 ? minutes * 60 : 0;
    time += seconds;

    for (int i = time; i > 0; i--) {
        //system("cls");

        cout << "\n\n\n              TIME TO LOOK AND THINK: 0:" << minutes << ":" << seconds;
        minutes = i % 60 == 0 ? --minutes : minutes;
        seconds = seconds == 0 ? 59 : --seconds;
        system("TIMEOUT 4");
    }
  

}

int gameFunction() {
    
    string array[10] = { "henry","thomas","will","phil","brian","john","jack","jill","james","carter" };
    char matrix[10][10];
    int r;
    char c;
    
    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 10; j++) {

            r = rand() % 26;
            c = 'a' + r;
            matrix[i][j] = c;
        }
    }
    int index = rand() % 10;
    string output = array[index];
    if (array[index].length() % 2 == 0) {

        //horizontally
        int row = rand() % 10;
        int col = rand() % 4;
        for (int i = 0; array[index][i] != '\0'; i++, col++) {
            matrix[row][col] = array[index][i];
        }
    }
    else {
        //vertically
        int row = rand() % 4;
        int col = rand() % 10;
        for (int i = 0; array[index][i] != '\0'; i++, row++) {
            matrix[row][col] = array[index][i];
        }
    }
    cout << "               Puzzle    " << endl << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << " ";
            Sleep(10);
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "\n";
    string guess;
    int hint;
    timer();
    cout << "\n1 - for a direct guess " << endl;
    cout << "2 - to see hint before guessing word " << endl;
    cout << "Enter option 1 or 2: ";
a:
    cin >> hint;
    cout << endl;
    
    while (hint != 1 && hint != 2)
    {
        cout << "Please enter option 1 for direct guess or option 2 to take a hint: " << endl;
        cin >> hint;
        if (hint == 1 || hint == 2) {
            goto b;
        }
    }
    b:
    if (hint == 1) {
        cout << "Enter your guess below: ";
        cin >> guess;
        cout << endl;
    }
   
    if (hint == 2) {
        cout << "The size of the word is " << output.length() << endl;
        cout << "Enter your final guess below: ";
        cin >> guess;
        cout << endl;
    }

  
    
    if (convert(output) == convert(guess)) {
        cout << "Congratulations! You have guessed the right word. " << endl << endl;
    }
    else {
        cout << "\nSorry, you have guessed the wrong word. " << endl;
        return 0;
    }
}

string convert(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
    return s;
}

