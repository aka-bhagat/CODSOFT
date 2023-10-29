#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;
    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number game!\n";
    std::cout << "I've selected a random number between 1 and 100. Try to guess it!\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " correctly in " << attempts << " attempts.\n";
        }
    } while (userGuess != secretNumber);

    return 0;
}
