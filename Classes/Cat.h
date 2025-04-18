#pragma once
#include "Animal.h"
#include <iostream>
#include <limits>

class Cat : public Animal
{
public:
    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) const override;
    eType GetType() const override { return eType::CAT; }

private:
    unsigned short agility = 0;
};

inline void Cat::Read(std::ostream& ostream, std::istream& istream)
{
    Animal::Read(ostream, istream);

    unsigned short inputAgility;
    do
    {
        ostream << "Enter agility (1-10): ";
        istream >> inputAgility;

        if (istream.fail() || inputAgility < 1 || inputAgility > 10)
        {
            ostream << "Invalid input. Please enter a number between 1 and 10.\n";
            istream.clear();
            istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            agility = inputAgility;
            break;
        }
    } while (true);
}

inline void Cat::Write(std::ostream& ostream) const
{
    ostream << "---CAT---\n";
    Animal::Write(ostream);
    ostream << "Agility: " << agility << "\n";
}
