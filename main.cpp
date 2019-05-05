#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <string>

using namespace std;

string randomizer(vector<string> v);
int playAgain();
char enterInput();


int main()
{
	string n[] = { "LINK", "ZELDA", "NAVI", "EPONA", "GANON",
				   "SHEIK", "CIA", "MIDNA", "IMPA", "ZANT",
				   "RUTO", "NAYRU" };
	vector<string> words;
	words.insert(words.end(), begin(n), end(n));

	const int MAX_WRONG = 8;
	int attempts = 0;
	char guess;
	string used;

	const string THE_WORD = randomizer(words);
	string soFar(THE_WORD.size(), '_');

	cout << "\n\nWelcome to Hyrule Hangman!\n\n";

	while (attempts < MAX_WRONG && soFar != THE_WORD) {
		cout << "You have " << MAX_WRONG - attempts << " attempts remaining.\n";
		cout << soFar;
		guess = enterInput();


		while (!isalpha(guess)) {
			cout << guess << " is not a valid answer. Please enter a character.\n";
			guess = enterInput();
		}

		while (used.find(guess) != string::npos) {
			cout << "\nYou've already used " << guess << ". Guess again.\n";
			guess = enterInput();
		}

		if (!isalpha(guess)) {
			cout << "That is not a valid guess. Please enter a character.";
		}

		if (THE_WORD.find(guess) != string::npos) {
			cout << guess << " is in the word!\n";
			for (int i = 0; i < THE_WORD.length(); i++) {
				if (THE_WORD[i] == guess) {
					soFar[i] = guess;
					used += guess;
				}
			}
		}
		else {
			cout << guess << " is not in the word. Try again.\n";
			used += guess;
			attempts++;
		}
	}
	if (attempts == MAX_WRONG) {
		cout << "\nGAME OVER\n";
		cout << "RETURN OF GANON\n";
	}
	else {
		cout << "\nYou guessed it!";
		cout << "\nYou're the hero of Hyrule\n!";
	}
	cout << "\nThe word was " << THE_WORD << "!" << endl;
	playAgain();
}

string randomizer(vector<string> v) {
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(v.begin(), v.end());
	const string THE_WORD = v[0];
	return THE_WORD;
}
int playAgain() {
	char yesNo;
	cout << "Would you like to play again? (y/n)\n";
	cin >> yesNo;
	if (yesNo == 'y') {
		main();
	}
	else {
		cout << "Goodbye!\n\n\n";
		return 0;
	}
}
char enterInput(){
	char g;
	cout << "\nEnter your guess: ";
	cin >> g;
	return toupper(g);
}
