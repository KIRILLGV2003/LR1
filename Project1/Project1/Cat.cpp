// Cat.cpp
#include "Cat.h"

Cat::Cat() : ownerName(nullptr), petName(nullptr) {
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const char* breed, const char* color, const char* ownerName, const char* petName) : Base(breed, color), ownerName(nullptr), petName(nullptr) {
    setOwnerName(ownerName);
    setPetName(petName);
    std::cout << "Cat parameterized constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Base(other), ownerName(nullptr), petName(nullptr) {
    setOwnerName(other.ownerName);
    setPetName(other.petName);
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat() {
    delete[] ownerName;
    delete[] petName;
    std::cout << "Cat destructor called." << std::endl;
}

const char* Cat::getOwnerName() const {
    return ownerName;
}

const char* Cat::getPetName() const {
    return petName;
}

void Cat::setOwnerName(const char* ownerName) {
    delete[] this->ownerName;
    // »спользуем _strdup
    this->ownerName = _strdup(ownerName);
}

void Cat::setPetName(const char* petName) {
    delete[] this->petName;
    // »спользуем _strdup
    this->petName = _strdup(petName);
}

void Cat::printInfo() const {
    std::cout << "Cat - Breed: " << getBreed() << ", Color: " << getColor() << ", Owner: " << ownerName << ", Pet Name: " << petName << std::endl;
}


void Cat::loadFromFile(std::ifstream& file) {
    char buffer[100];
    file >> buffer; // —читываем метку
    file >> buffer; // —читываем породу
    setBreed(buffer);
    file >> buffer; // —читываем цвет
    setColor(buffer);
    file >> buffer; // —читываем им€ владельца
    setOwnerName(buffer);
    file >> buffer; // —читываем кличку
    setPetName(buffer);
}
void Cat::saveToFile(std::ofstream& file) const {
    file << "3 "; // ћетка, что сохран€ем объект класса Cat
    file << getBreed() << " " << getColor() << " " << ownerName << " " << petName << std::endl;
}