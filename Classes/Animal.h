#pragma once
#include <iostream>
#include <string>

class Animal
{
public:
    enum class eType
    {
        CAT,
        DOG,
        BIRD,
        UNKNOWN
    };

    Animal() = default;
    Animal(const std::string& name, unsigned short lifespan)
        : name(name), lifespan(lifespan) {
    }
    virtual ~Animal() = default;

    std::string GetName() const { return name; }
    unsigned short GetLifespan() const { return lifespan; }

    void SetName(const std::string& newName) { name = newName; }
    void SetLifespan(unsigned short newLifespan) { lifespan = newLifespan; }

    virtual eType GetType() const = 0;

    virtual void Read(std::ostream& ostream, std::istream& istream);
    virtual void Write(std::ostream& ostream) const;

protected:
    std::string name;
    unsigned short lifespan = 0;
};

inline void Animal::Read(std::ostream& ostream, std::istream& istream)
{
    ostream << "Enter Name: ";
    istream >> name;

    ostream << "Enter lifespan (Years): ";
    while (!(istream >> lifespan) || lifespan == 0)
    {
        ostream << "Invalid input. Please enter a positive number for lifespan.\n";
        istream.clear();
        istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

inline void Animal::Write(std::ostream& ostream) const
{
    ostream << "Name: " << name << "\n";
    ostream << "Lifespan in years: " << lifespan << "\n";
}
