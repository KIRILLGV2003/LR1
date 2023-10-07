// Animal.cpp
#include "Animal.h"

Animal::Animal() {
    std::cout << "Animal constructor called." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called." << std::endl;
}

void Animal::save(std::ostream& os) const {
    // Реализация сохранения объекта в файл
}

void Animal::load(std::istream& is) {
    // Реализация загрузки объекта из файла
}
