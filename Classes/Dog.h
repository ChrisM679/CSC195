#pragma once
#include "Animal.h"
#include <iostream>
#include <limits>

class Dog : public Animal
{
public:
    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) const override;
    eType GetType() const override { return eType::DOG; }

private:
    unsigned short friendliness = 0;
};

inline void Dog::Read(std::ostream& ostream, std::istream& istream)
{
    Animal::Read(ostream, istream);

    unsigned short inputFriendliness;
    do
    {
        ostream << "Enter friendliness (1-10): ";
        istream >> inputFriendliness;

        if (istream.fail() || inputFriendliness < 1 || inputFriendliness > 10)
        {
            ostream << "Invalid input. Please enter a number between 1 and 10.\n";
            istream.clear();
            istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            friendliness = inputFriendliness;
            break;
        }
    } while (true);
}

inline void Dog::Write(std::ostream& ostream) const
{
    ostream << "---DOG---\n";
    Animal::Write(ostream);
    ostream << "Friendliness: " << friendliness << "\n";
}