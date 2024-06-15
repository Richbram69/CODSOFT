#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    int randomNumber = std::rand() % 100 + 1;
    int guess;

    std::cout << "Welcome to the Guessing Game!" << std::endl;
    std::cout << "I have generated a random number between 1 and 100." << std::endl;
    std::cout << "Can you guess what it is?" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << randomNumber << std::endl;
        }
    } while (guess != randomNumber);

    return 0;
}
