#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

void playGame(int maxAttempts, int range) {
    // Generate a random number between 1 and the specified range
    int numberToGuess = rand() % range + 1;
    int playerGuess;
    int attempts = 0;

    std::cout << "I have chosen a number between 1 and " << range << ". Try to guess it!" << std::endl;

    // Game loop: give player a limited number of attempts
    while (attempts < maxAttempts) {
        std::cout << "Attempt " << attempts + 1 << "/" << maxAttempts << ": Enter your guess: ";
        std::cin >> playerGuess;
        attempts++;

        if (playerGuess == numberToGuess) {
            std::cout << "Congratulations! You guessed the number correctly in " << attempts << " attempts." << std::endl;
            return;
        } else if (playerGuess > numberToGuess) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Too low! Try again." << std::endl;
        }
    }

    std::cout << "Sorry, you've used all your attempts. The number was " << numberToGuess << "." << std::endl;
}

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    int maxAttempts = 5;   // Number of attempts allowed
    int range = 100;       // Range of the random number (1 to 100)

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    playGame(maxAttempts, range);

    return 0;
}