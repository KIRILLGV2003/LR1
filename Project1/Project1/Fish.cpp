// Fish.cpp
#include "Fish.h"

Fish::Fish() : feedingType(nullptr) {
    std::cout << "Вызывается конструктор Fish по умолчанию." << std::endl;
}

Fish::Fish(const char* breed, const char* color, const char* feedingType) : Base(breed, color), feedingType(nullptr) {
    setFeedingType(feedingType);
    std::cout << "Вызывается параметризованный конструктор Fish." << std::endl;
}

Fish::Fish(const Fish& other) : Base(other), feedingType(nullptr) {
    setFeedingType(other.feedingType);
    std::cout << "Вызывается конструктор копирования Fish." << std::endl;
}

Fish::~Fish() {
    delete[] feedingType;
    std::cout << "Вызванный деструктор рыбы." << std::endl;
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
    std::cout << "Рыба - Порода: " << getBreed() << ", Цвет: " << getColor() << ", Тип питания: " << feedingType << std::endl;
}

void Fish::saveToFile(std::ofstream& file) const {
    file << "4 "; // Метка, что сохраняем объект класса Fish
    file << getBreed() << " " << getColor() << " " << feedingType << std::endl;
}

void Fish::loadFromFile(std::ifstream& file) {
    char buffer[100];
    file >> buffer; // Считываем породу
    setBreed(buffer);
    file >> buffer; // Считываем цвет
    setColor(buffer);
    file >> buffer; // Считываем тип питания
    setFeedingType(buffer);
}
