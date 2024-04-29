#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<string> words = {"hello", "world", "hangman", "programming", "computer"};

string chooseWord() {
    srand(time(NULL));
    return words[rand() % words.size()];
}

bool contains(char c, const string& word) {
    return word.find(c) != string::npos;
}

void displayWord(const string& word, const vector<char>& guessedLetters) {
    for (char c : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end()) {
            cout << c << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}
int main() {
    string word = chooseWord();
    int attempts = 6;
    vector<char> guessedLetters;

    cout << "Welcome to Hangman" << endl;

    while (attempts > 0) {
        cout << "Attempts left: " << attempts << endl;
        displayWord(word, guessedLetters);

        char guess;
        cout << "Enter a letter guess: ";
        cin >> guess;

        if (contains(guess, word)) {
            cout << "Correct guess!" << endl;
            guessedLetters.push_back(guess);
        } else {
            cout << "Incorrect guess!" << endl;
            attempts--;
        }
        bool foundAllLetters = true;
        for (char c : word) {
            if (find(guessedLetters.begin(), guessedLetters.end(), c) == guessedLetters.end()) {
                foundAllLetters = false;
                break;
            }
        }
        if (foundAllLetters) {
            cout << "Congratulations! You've guessed the word: " << word << endl;
            break;
            }
        }
        if (attempts == 0) {
            cout << "Sorry, you ran out of attempts. The word was: " << word << endl;
        }
        return 0;
}