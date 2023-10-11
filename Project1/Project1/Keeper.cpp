// Keeper.cpp
#include "Keeper.h"

Keeper::Keeper() : animals(nullptr), capacity(0), size(0) {
    std::cout << "Keeper default constructor called." << std::endl;
}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }
    delete[] animals;
    std::cout << "Keeper destructor called." << std::endl;
}

void Keeper::addAnimal(Base* animal) {
    if (size == capacity) {
        resize();
    }
    animals[size++] = animal;
}

void Keeper::removeAnimal(int index) {
    if (index >= 0 && index < size) {
        delete animals[index];
        for (int i = index; i < size - 1; ++i) {
            animals[i] = animals[i + 1];
        }
        size--;
    }
    else {
        std::cerr << "Invalid index for removal." << std::endl;
    }
}

void Keeper::printAllAnimals() const {
    for (int i = 0; i < size; ++i) {
        animals[i]->printInfo();
    }
}

void Keeper::saveToFile(const char* filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << size << std::endl;
        for (int i = 0; i < size; ++i) {
            animals[i]->saveToFile(file);
        }
        file.close();
        std::cout << "Data saved to file: " << filename << std::endl;
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void Keeper::loadFromFile(const char* filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        int loadedSize;
        file >> loadedSize;

        // Clear existing data
        for (int i = 0; i < size; ++i) {
            delete animals[i];
        }
        delete[] animals;

        // Allocate new space
        capacity = loadedSize;
        size = 0;
        animals = new Base * [capacity];

        // Load data
        for (int i = 0; i < loadedSize; ++i) {
            int type;
            file >> type;
            Base* animal = nullptr;
            switch (type) {
            case 1: // Fish
                animal = new Fish();
                break;
            case 2: // Bird
                animal = new Bird();
                break;
            case 3: // Cat
                animal = new Cat();
                break;
            default:
                std::cerr << "Unknown animal type in file." << std::endl;
                delete animal;
                continue;
            }
            animal->loadFromFile(file);
            addAnimal(animal);
        }

        file.close();
        std::cout << "Data loaded from file: " << filename << std::endl;
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void Keeper::resize() {
    int newCapacity = (capacity == 0) ? 1 : capacity * 2;
    Base** newArray = new Base * [newCapacity];
    for (int i = 0; i < size; ++i) {
        newArray[i] = animals[i];
    }
    delete[] animals;
    animals = newArray;
    capacity = newCapacity;
}
