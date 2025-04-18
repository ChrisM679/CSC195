#include "Database.h"
#include <iostream>
#include <limits>

enum MenuOptions {
    ADD_ANIMAL = 1,
    DISPLAY_ALL,
    REMOVE_ANIMAL,
    DISPLAY_BY_TYPE,
    QUIT
};

void ClearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    Database database;

    bool quit = false;
    while (!quit)
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Animal\n";
        std::cout << "2. Display All Animals\n";
        std::cout << "3. Remove Animal\n";
        std::cout << "4. Display Animals by Type\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";

        unsigned short selection;
        std::cin >> selection;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number between 1 and 5.\n";
            ClearInputStream();
            continue;
        }

        switch (selection) {
        case ADD_ANIMAL: {
            std::cout << "Enter type (0 for CAT or 1 for DOG): ";
            int t;
            std::cin >> t;

            if (std::cin.fail() || t < 0 || t > 2) {
                std::cout << "Invalid type. Please enter 0 or 1\n";
                ClearInputStream();
                break;
            }

            database.Create(static_cast<Animal::eType>(t));
            break;
        }
        case DISPLAY_ALL:
            database.DisplayAll();
            break;
        case REMOVE_ANIMAL: {
            std::cout << "Enter name: ";
            std::string name;
            std::cin >> name;
            database.Display(name);
            break;
        }
        case DISPLAY_BY_TYPE: {
            std::cout << "Enter type (0 for CAT or 1 for DOG): ";
            int t;
            std::cin >> t;

            if (std::cin.fail() || t < 0 || t > 2) {
                std::cout << "Invalid type. Please enter 0 or 1\n";
                ClearInputStream();
                break;
            }

            database.Display(static_cast<Animal::eType>(t));
            break;
        }
        case QUIT:
            quit = true;
            break;
        default:
            std::cout << "Invalid selection. Please choose a number between 1 and 5.\n";
            break;
        }
    }

    return 0;
}

