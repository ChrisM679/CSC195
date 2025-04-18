#pragma once
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>    

class Database
{
public:
    ~Database() = default;

    void Create(Animal::eType type);
    void DisplayAll() const;
    void Display(const std::string& name) const;
    void Display(Animal::eType type) const;
    bool Remove(const std::string& name);

private:
    std::vector<std::unique_ptr<Animal>> animals;
};

void Database::Create(Animal::eType type)
{
    std::unique_ptr<Animal> animal;
    switch (type)
    {
    case Animal::eType::CAT:
        animal = std::make_unique<Cat>();
        break;
    case Animal::eType::DOG:
        animal = std::make_unique<Dog>();
        break;
    default:
        return;
    }

    if (animal)
    {
        animal->Read(std::cout, std::cin);
        animals.push_back(std::move(animal));
    }
}

void Database::DisplayAll() const
{
    for (const auto& animal : animals)
    {
        animal->Write(std::cout);
    }
}

void Database::Display(const std::string& name) const
{
    auto it = std::find_if(animals.begin(), animals.end(),
        [&name](const std::unique_ptr<Animal>& animal) {
            return animal->GetName() == name;
        });

    if (it != animals.end())
    {
        (*it)->Write(std::cout);
    }
    else
    {
        std::cout << "Animal not found!" << std::endl;
    }
}

void Database::Display(Animal::eType type) const
{
    bool found = false;
    for (const auto& animal : animals)
    {
        if (animal->GetType() == type)
        {
            animal->Write(std::cout);
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "Animal not found!" << std::endl;
    }
}

bool Database::Remove(const std::string& name)
{
    auto it = std::remove_if(animals.begin(), animals.end(),
        [&name](const std::unique_ptr<Animal>& animal) {
            return animal->GetName() == name;
        });

    if (it != animals.end())
    {
        animals.erase(it, animals.end());
        return true;
    }

    return false;
}