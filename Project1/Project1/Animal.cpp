// Animal.cpp
#include "Animal.h"

Animal::Animal() {
    std::cout << "Animal constructor called." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called." << std::endl;
}

void Animal::save(std::ostream& os) const {
    // ���������� ���������� ������� � ����
}

void Animal::load(std::istream& is) {
    // ���������� �������� ������� �� �����
}
