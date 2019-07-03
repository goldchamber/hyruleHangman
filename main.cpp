#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>



std::string randomWord(std::vector<std::string> v);
void playAgain();

int main() {


	constexpr int MAX_GUESSES{ 11 };
	int numberOfGuesses{ 0 };
	char charGuess{};
	std::string WORDS_ARRAY[] = { "LINK", "ZELDA", "NAVI", "NAYRU",
											"EPONA", "GANONDORF", "SHEIK", "CIA",
											"MIDNA", "IMPA", "RUTO", "ZANT",
											"HYRULE", "WINDWAKER", "TWILIGHT", "GERUDO"};
	std::vector<std::string> possibleWords;
	possibleWords.insert(possibleWords.end(), begin(WORDS_ARRAY), end(WORDS_ARRAY));
	const std::string THE_WORD{ randomWord(possibleWords) };
	std::string wordSoFar(THE_WORD.size(), '_');
	std::string userGuessesSoFar{};


	std::cout << "WELCOME TO HYRULE HANGMAN 2.0!\n\n";


		
		while (numberOfGuesses < MAX_GUESSES && wordSoFar != THE_WORD) {

			std::cout << "You have " << MAX_GUESSES - numberOfGuesses << " guesses remaining. \n";
			std::cout << wordSoFar << "\n";
			std::cout << "\nGuess a letter!";

			std::cin >> charGuess;
			charGuess = toupper(charGuess);
			
			while (!isalpha(charGuess)) {
				std::cout << charGuess << " is not a valid character. Please input a letter.\n";
				std::cout << "\nGuess a letter!";
				std::cin >> charGuess;
			}

			while (userGuessesSoFar.find(charGuess) != std::string::npos) {
				std::cout << "\nYou've already used " << charGuess << ". Guess again.\n";
				std::cout << wordSoFar << "\n";
				std::cout << "\nGuess a letter!";
				std::cin >> charGuess;
			}

			

			if (THE_WORD.find(charGuess) != std::string::npos) {
				std::cout << charGuess << " is in the word!\n";
				for (int i = 0; i < THE_WORD.length(); i++) {
					if (THE_WORD[i] == charGuess) {
						wordSoFar[i] = charGuess;
						userGuessesSoFar += charGuess;
						numberOfGuesses++;
					}
				}
			}
			else {
				std::cout << charGuess << " is not in the word. Try again.\n";
				userGuessesSoFar += charGuess;
				numberOfGuesses++;
			}
		}

		if (numberOfGuesses == MAX_GUESSES && wordSoFar != THE_WORD) {
			std::cout << "\nGAME OVER\n";
			std::cout << "RETURN OF GANON\n";
		}

		if (wordSoFar == THE_WORD) {
			std::cout << "\nYou guessed it!";
			std::cout << "\nYou're the hero of Hyrule!\n";
		}
		std::cout << "\nThe word was " << THE_WORD << "!\n\n";
		playAgain();
	}

void playAgain() {
	std::cout << "Would you like to play again?\n";
	std::cout << "Y / N \n";
	char choice{};
	std::cin >> choice;
	if (toupper(choice) == 'Y') {
		std::cout << "\n\n";
		main();
	}
	else {
		std::cout << "Goodbye!\n\n";
	}
}



std::string randomWord(std::vector<std::string> v) {

	std::random_device dev;
	std::mt19937 rng(dev());
	std::shuffle(begin(v), end(v), rng);
	const std::string THE_WORD = v[0];
	return THE_WORD;

}


