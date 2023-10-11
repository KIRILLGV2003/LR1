// Fish.cpp
#include "Fish.h"

Fish::Fish() : feedingType(nullptr) {
    std::cout << "Fish default constructor called." << std::endl;
}

Fish::Fish(const char* breed, const char* color, const char* feedingType) : Base(breed, color), feedingType(nullptr) {
    setFeedingType(feedingType);
    std::cout << "Fish parameterized constructor called." << std::endl;
}

Fish::Fish(const Fish& other) : Base(other), feedingType(nullptr) {
    setFeedingType(other.feedingType);
    std::cout << "Fish copy constructor called." << std::endl;
}

Fish::~Fish() {
    delete[] feedingType;
    std::cout << "Fish destructor called." << std::endl;
}

const char* Fish::getFeedingType() const {
    return feedingType;
}

void Fish::setFeedingType(const char* feedingType) {
    delete[] this->feedingType;
    size_t len = strlen(feedingType) + 1;
    this->feedingType = new char[len];
    strcpy_s(this->feedingType, len, feedingType);
}

void Fish::printInfo() const {
    std::cout << "Fish - Breed: " << getBreed() << ", Color: " << getColor() << ", Feeding Type: " << feedingType << std::endl;
}

void Fish::saveToFile(std::ofstream& file) const {
    file << "4 "; // ћетка, что сохран€ем объект класса Fish
    file << getBreed() << " " << getColor() << " " << feedingType << std::endl;
}

void Fish::loadFromFile(std::ifstream& file) {
    char buffer[100];
    file >> buffer; // —читываем метку
    file >> buffer; // —читываем породу
    setBreed(buffer);
    file >> buffer; // —читываем цвет
    setColor(buffer);
    file >> buffer; // —читываем тип питани€
    setFeedingType(buffer);
}
