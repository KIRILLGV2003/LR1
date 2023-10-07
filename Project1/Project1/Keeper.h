// Keeper.h
#include "Animal.h"

#ifndef KEEPER_H
#define KEEPER_H

#include <vector>
#include <iostream>
#include <fstream>

class Keeper {
public:
    Keeper();
    ~Keeper();

    void addAnimal(Animal* animal);
    void removeAnimal(int index);
    void printAllAnimals() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<Animal*> animals;
};

#endif // KEEPER_H
