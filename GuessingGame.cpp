#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Initialize variables
    const int lowerBound = 1;
    const int upperBound = 10;
    int secretNumber = rand() % (upperBound - lowerBound + 1) + lowerBound;
    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";

    do {
        // Prompt the user to enter a guess
        std::cout << "Guess a number between " << lowerBound << " and " << upperBound << ": ";
        while (!(std::cin >> userGuess) || userGuess < lowerBound || userGuess > upperBound) {
            // Input validation
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between " << lowerBound << " and " << upperBound << ":";
        }

        // Increment the attempts counter
        attempts++;

        // Check if the guess is correct, too high, or too low
        if (userGuess == secretNumber) {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        }
        else if (userGuess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        }
        else {
            std::cout << "Too high! Try again.\n";
        }

    } while (userGuess != secretNumber);

    return 0;
}

