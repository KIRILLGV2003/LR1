// Keeper.cpp
#include "Keeper.h"

Keeper::Keeper() {
    std::cout << "Keeper constructor called." << std::endl;
}

Keeper::~Keeper() {
    std::cout << "Keeper destructor called." << std::endl;
    // ������������ ������ ��� ���� �������� � ���������
    for (auto& animal : animals) {
        delete animal;
    }
}

void Keeper::addAnimal(Animal* animal) {
    animals.push_back(animal);
}

void Keeper::removeAnimal(int index) {
    if (index >= 0 && index < animals.size()) {
        delete animals[index];
        animals.erase(animals.begin() + index);
    }
}

void Keeper::printAllAnimals() const {
    for (const auto& animal : animals) {
        animal->print();
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& animal : animals) {
            animal->save(file);
        }
        file.close();
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        while (!file.eof()) {
            // ������ ��� ������� �� ����� � ������� ��������������� ������
            // (Fish, Bird ��� Cat)
            // ����� �������� ����� load ��� �������������� ��������� ������� �� �����
        }
        file.close();
    }
}
