// Bird.cpp
#include "Bird.h"

Bird::Bird() {
    std::cout << "Bird constructor called." << std::endl;
}

Bird::~Bird() {
    std::cout << "Bird destructor called." << std::endl;
}

void Bird::print() const {
    // ���������� ������ ���������� � ����
}

void Bird::save(std::ostream& os) const {
    // ���������� ���������� ������� ���� � ����
}

void Bird::load(std::istream& is) {
    // ���������� �������� ������� ���� �� �����
}
