// Cat.cpp
#include "Cat.h"

Cat::Cat() {
    std::cout << "Cat constructor called." << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::print() const {
    // ���������� ������ ���������� � ����
}

void Cat::save(std::ostream& os) const {
    // ���������� ���������� ������� ���� � ����
}

void Cat::load(std::istream& is) {
    // ���������� �������� ������� ���� �� �����
}
