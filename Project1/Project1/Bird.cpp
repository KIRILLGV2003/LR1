// Bird.cpp
#include "Bird.h"

Bird::Bird() : diet(nullptr), habitat(nullptr) {
    std::cout << "Bird default constructor called." << std::endl;
}

Bird::Bird(const char* breed, const char* color, const char* diet, const char* habitat) : Base(breed, color), diet(nullptr), habitat(nullptr) {
    setDiet(diet);
    setHabitat(habitat);
    std::cout << "Bird parameterized constructor called." << std::endl;
}

Bird::Bird(const Bird& other) : Base(other), diet(nullptr), habitat(nullptr) {
    setDiet(other.diet);
    setHabitat(other.habitat);
    std::cout << "Bird copy constructor called." << std::endl;
}

Bird::~Bird() {
    delete[] diet;
    delete[] habitat;
    std::cout << "Bird destructor called." << std::endl;
}

const char* Bird::getDiet() const {
    return diet;
}

const char* Bird::getHabitat() const {
    return habitat;
}

void Bird::setDiet(const char* diet) {
    delete[] this->diet;
    // ���������� _strdup
    this->diet = _strdup(diet);
}

void Bird::setHabitat(const char* habitat) {
    delete[] this->habitat;
    // ���������� _strdup
    this->habitat = _strdup(habitat);
}

void Bird::printInfo() const {
    std::cout << "Bird - Breed: " << getBreed() << ", Color: " << getColor() << ", Diet: " << diet << ", Habitat: " << habitat << std::endl;
}

void Bird::saveToFile(std::ofstream& file) const {
    file << "2 "; // �����, ��� ��������� ������ ������ Bird
    file << getBreed() << " " << getColor() << " " << diet << " " << habitat << std::endl;
}

void Bird::loadFromFile(std::ifstream& file) {
    char buffer[100];
    file >> buffer; // ��������� �����
    file >> buffer; // ��������� ������
    setBreed(buffer);
    file >> buffer; // ��������� ����
    setColor(buffer);
    file >> buffer; // ��������� �����
    setDiet(buffer);
    file >> buffer; // ��������� ����� ��������
    setHabitat(buffer);
}
