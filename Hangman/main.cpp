#include <iostream>;
#include <cstdlib>;
#include <ctime>;
#include <cctype>;
#include <vector>;
#include <string>;
#include <algorithm>;
#include <stdio.h>;
#include <string.h>;

using namespace std;


int main(){
	//the words to choose from
	vector<string> words{ "hello", "hang", "man", "guitar", "operator" };
	vector<string> ::iterator myIter;
	string usedLetters = "";
	char guess;
	
	//shuffle the words and select the first word
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	string secretWord = words[0];
	string progressWord = secretWord;

	//turn each letter into dashes
	for (int i = 0; i < progressWord.size(); ++i){
		progressWord[i] = '_';
	}
	//set the amount of attempts allowed
	unsigned int allowedAttempts = secretWord.size();
	unsigned int incorrectAttempts = 0;
	bool gameWon = false;
	bool playAgain = false;
	
	//game loop
	while (!gameWon &&  incorrectAttempts != allowedAttempts){
		cout << "You have " << allowedAttempts - incorrectAttempts << " attempts left." << endl; // show the amount of attempts remaining.
		cout << "\nCurrent word progress:" << endl;
		for (int i = 0; i < progressWord.size(); ++i){	//print out the progression of the word.
			cout << " " << progressWord[i] << " ";
		}

		if(!usedLetters.empty())
		cout << "\nUSED LETTERS : " << usedLetters << endl; // print out he used letters to the player
		
		cout << "Enter your guess:" << endl;
		cin >> guess;
		guess = tolower(guess);
		while (usedLetters.find(guess) != string::npos){
			cout << "You have already guessed this letter." << endl;
			cout << "Enter your guess" << endl;
			cin >> guess;
			guess = tolower(guess);
		}
		usedLetters += guess;

		//check and see if the guess is in the secret word
		if (secretWord.find(guess) != string::npos){
			for (int i = 0; i < secretWord.size(); ++i){
				if (secretWord[i] == guess){
					progressWord[i] = guess; //change the progress word from '_' to the correct letter.
					cout << "Well done you guessed correctly." << endl;
					cout << "\n";

				}
			}
		}
			else{
				incorrectAttempts++; //its an incorrect guess.
				cout << "You guessed incorrectly" << endl;
				cout << "\n";
			}
		
		// check that each space in the progress word now contains 
		bool fullWord = false;
		if (secretWord.compare(progressWord) == 0){
			fullWord = true;
		}
		else{
			fullWord = false;
		}
		gameWon = fullWord;

		if (incorrectAttempts == allowedAttempts){
			cout << "YOU HAVE BEEN HANGED!" << endl;
		}
		else if (gameWon && incorrectAttempts < allowedAttempts){
			cout << "Congratulations you have won!\n The word was: " <<  secretWord<< endl;
		}
		
	}
	system("pause");
	return 0;
}