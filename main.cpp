#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <string>

using namespace std;

int main()
{
	const int MAX_WRONG = 8; 
	vector<string> words;
	words.push_back("ZELDA");
	words.push_back("LINK");
	words.push_back("GANON");
	words.push_back("SHEIK");
	words.push_back("LINKLE");
	words.push_back("MIDNA");
	words.push_back("EPONA");
	words.push_back("NAVI");
	words.push_back("MAJORA");
	words.push_back("CIA");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	
	const string THE_WORD = words[0];
	int wrong = 0;
	string soFar(THE_WORD.size(), '_');
	string used = "";

	cout << "WELCOME TO HYRULE HANGMAN!";


	//MAIN GAME LOOP
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << soFar;

		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;
		guess = toupper(guess);
		while (used.find(guess) != string::npos) {
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;

		
		while (!isalpha(guess)) {
			cout << guess << " is not a valid choice.\n";
			cout << "\n\nEnter your guess: ";
			cin >> guess;
		}

		if (THE_WORD.find(guess) != string::npos) {
			cout << "That's right! " << guess << " is in the word.\n";
			for (int i = 0; i < THE_WORD.length(); i++) {
				if (THE_WORD[i] == guess) {
					soFar[i] = guess;
				}
			}
		}
		else {
			cout << "Sorry, " << guess << " isn't in the word.\n";
			++wrong;
		}
	} 

	if (wrong == MAX_WRONG) {
		cout << "\nYou've been hanged!";
	}
	else {
		cout << "\n You guessed it!";
	}

	cout << "\nThe word was " << THE_WORD << endl;

	return 0;
}
