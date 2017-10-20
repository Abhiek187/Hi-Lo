/* You've got 7 tries to guess a number between 1 and 100.
 * hi-lo.cpp
 *
 *  Created on: May 21, 2017
 *      Author: Abhiek187
 */

#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	// static used for efficiency, so we only have to calculate this value once
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void guessAnswer(int answer)
{
	// 7 attempts to guess the correct number
	for (int attempt = 1; attempt <= 7; ++attempt)
	{
		std::cout << "Guess #" << attempt << ": ";
		int guess;
		std::cin >> guess;

		if (guess < answer)
			std::cout << "Your guess is too low.\n";
		else if (guess > answer)
			std::cout << "Your guess is too high.\n";
		else
		{
			std::cout << "Correct! You win!\n";
			break;
		}
		if (attempt == 7)
			std::cout << "Sorry, you lose. The answer was " << answer << '\n';
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	char playAgain = 'y'; // Yes, we want to play the game.

	do
	{
		int answer = getRandomNumber(1,100); // number is different each game
		std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
		guessAnswer(answer);

		while (true) // only answers of y or n will break out of this loop
		{
			std::cout << "Would you like to play again (y/n)? ";
			std::cin >> playAgain;

			if (playAgain == 'y' || playAgain == 'n')
				break;
		}
	}
	while (playAgain == 'y');

	std::cout << "Thank you for playing.\n";
	return 0;
}
