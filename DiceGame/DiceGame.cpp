// DiceGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <random>
#include <vector>

class Dice {
private:
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist;
public:
    Dice() : rng(std::random_device{}()), dist(1, 6) {}
    int roll() {
        return dist(rng);
    }
};

class Game {
private:
    std::vector<Dice> dice;
    int rounds;
public:
    Game(int numDice, int numRounds) : rounds(numRounds) {
        dice.resize(numDice);
    }

    int getRounds() const {
        return rounds;
    }

    void setRounds(int r) {
        rounds = r;
    }

    int rollAllDice() {
        int total = 0;
        for (auto& die : dice) {
            total += die.roll();
        }
        return total;
    }
};

class Player {
private:
    std::string playerName;
    int playerScore = 0;
public:
    const std::string& getPlayerName() const {
        return playerName;
    }

    void setPlayerName(const std::string& name) {
        playerName = name;
    }

    int getPlayerScore() const {
        return playerScore;
    }

    void addScore(int score) {
        playerScore += score;
    }
};

int main() {
    int numRounds = 3;
    int numDice = 4;

    std::cout << "Welcome to the Dice Game!\n";
    std::cout << "Enter your name: ";
    std::string playerName;
    std::getline(std::cin, playerName);

    Player player;
    player.setPlayerName(playerName);

    Game game(numDice, numRounds);

    std::cout << "Starting the game with " << numRounds << " rounds and " << numDice << " dice.\n";

    for (int round = 1; round <= numRounds; ++round) {
        std::cout << "Round " << round << ": Press Enter to roll the dice...";
        std::cin.ignore();

        int roundScore = game.rollAllDice();
        player.addScore(roundScore);

        std::cout << "You rolled a total of " << roundScore << " points!\n";
    }

    std::cout << "Game over! " << player.getPlayerName() << ", your total score is " << player.getPlayerScore() << " points.\n";

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
