// Base.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Base.h"
#include <cstring>

Base::Base() : breed(nullptr), color(nullptr) {
    std::cout << "Base default constructor called." << std::endl;
}

Base::Base(const char* breed, const char* color) : breed(nullptr), color(nullptr) {
    setBreed(breed);
    setColor(color);
    std::cout << "Base parameterized constructor called." << std::endl;
}

Base::Base(const Base& other) : breed(nullptr), color(nullptr) {
    setBreed(other.breed);
    setColor(other.color);
    std::cout << "Base copy constructor called." << std::endl;
}

Base::~Base() {
    delete[] breed;
    delete[] color;
    std::cout << "Base destructor called." << std::endl;
}

const char* Base::getBreed() const {
    return breed;
}

const char* Base::getColor() const {
    return color;
}

void Base::setBreed(const char* breed) {
    delete[] this->breed;
    // »спользуем _strdup, так как он безопасен с точки зрени€ Microsoft
    this->breed = _strdup(breed);
}

void Base::setColor(const char* color) {
    delete[] this->color;
    // »спользуем _strdup, так как он безопасен с точки зрени€ Microsoft
    this->color = _strdup(color);
}

void Base::printInfo() const {
    std::cout << "Base - Breed: " << breed << ", Color: " << color << std::endl;
}

void Base::saveToFile(std::ofstream& file) const {
    file << "1 "; // ћетка, что сохран€ем объект класса Base
    file << breed << " " << color << std::endl;
}

void Base::loadFromFile(std::ifstream& file) {
    char buffer[100];
    file >> buffer; // —читываем метку
    file >> buffer; // —читываем породу
    setBreed(buffer);
    file >> buffer; // —читываем цвет
    setColor(buffer);
}
