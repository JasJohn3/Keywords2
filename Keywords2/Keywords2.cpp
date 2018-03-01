// Keywords2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
//srand(static_cast<unsigned int>(time(0)));//<cstdlib> function for random <ctime> for seeding time
#include <string>
#include <vector>
#include <algorithm>
//random_shuffle(words.begin(), words.end());//<algorithm> library function
#include <cctype>



using namespace std;
void Hangman(string name);

int main()
{
	const int MAX_GUESSES = 8;
	// Display Title of program to user
	cout << "Welcom to Keywords CIA Training program" << endl;

		// Ask the recruit to login using thier name
	cout << "Please enter your last name: " << endl;
	string user_name;
	cin >> user_name;
	// Create an int var to count the number of simulations being run starting at 1
	int simulations = 1;
	// Display the simulation # is staring to the recruit. 

	while (simulations <3)
	{
		cout << "Simulation " << simulations << " starts Now!  Good luck recruit!";
		Hangman(user_name);
		simulations++;
	}




	// Hold the recruit's name in a var, and address them by it throughout the simulation.

	// Display an overview of what Keywords II is to the recruit 

	// Display an directions to the recruit on how to use Keywords



	// Create a collection of 10 words you had wrote down manually




	// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 



	// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word

	//     Tell recruit how many incorrect guesses he or she has left

	//     Show recruit the letters he or she has guessed

	//     Show player how much of the secret word he or she has guessed

	//     Get recruit's next guess

	//     While recruit has entered a letter that he or she has already guessed

	//          Get recruit ’s guess

	//     Add the new guess to the group of used letters

	//     If the guess is in the secret word

	//          Tell the recruit the guess is correct

	//          Update the word guessed so far with the new letter

	//     Otherwise

	//          Tell the recruit the guess is incorrect

	//          Increment the number of incorrect guesses the recruit has made

	// If the recruit has made too many incorrect guesses

	//     Tell the recruit that he or she has failed the Keywords II course.

	// Otherwise

	//     Congratulate the recruit on guessing the secret words

	// Ask the recruit if they would like to run the simulation again

	// If the recruit wants to run the simulation again

	//     Increment the number of simiulations ran counter

	//     Move program execution back up to // Display the simulation # is staring to the recruit. 

	// Otherwise 

	//     Display End of Simulations to the recruit

	//     Pause the Simulation with press any key to continue
    return 0;
}
	void Hangman(string name)
{
		const int MAX_WRONG = 26; //Maximum Number of incorrect Guesses

		vector<string> words; //collection of possible words to guess
		words.push_back("Alpha");
		words.push_back("Bravo");
		words.push_back("Charlie");
		words.push_back("Delta");
		words.push_back("Echo");
		words.push_back("Whiskey");
		words.push_back("Tango");
		words.push_back("Foxtrot");
		words.push_back("Zulu");
		words.push_back("Xray");

		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());

		const string THE_WORD = words[0];
		int wrong = 0;
		string soFar(THE_WORD.size(), '-');
		string used = "";

		cout << "Welcome to Hangman. Good Luck\n";

		while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
		{
			cout << "\n\nYou Have " << (MAX_WRONG - wrong);
			cout << " incorrect guesses left.\n\n";
			cout << "\nYou've used the following letters:\n" << used << endl;
			cout << "\nSo far, the word is :\n" << soFar << endl;

			char guess;
			cout << "\n\nEnter your guess: ";
			cin >> guess;

			guess = toupper(guess); //Make Uppercase since secret word is uppercase

			while (used.find(guess) != string::npos)
			{
				cout << "\nYou've already guessed " << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}
			used += guess;
			if (THE_WORD.find(guess) != string::npos)
			{
				cout << "That's right!" << guess << " is in the word.\n";
				//update soFar to include newly guess letter
				for (int i = 0; i < THE_WORD.length(); ++i)
				{
					if (THE_WORD[i] == guess)
					{
						soFar[i] = guess;
					}
				}
			}
			else
			{
				cout << "Sorry, " << guess << " isn't in the word.\n";
				++wrong;
			}
		}
		//shut down
		if (wrong == MAX_WRONG)
		{
			cout << "\nYou've been Hanged!";
		}
		else
		{
			cout << "\nYou guessed it!";
		}
		cout << "\nThe word was " << THE_WORD << endl;

}

