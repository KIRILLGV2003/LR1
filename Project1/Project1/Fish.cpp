// Fish.cpp
#include "Fish.h"

Fish::Fish() {
    std::cout << "Fish constructor called." << std::endl;
}

Fish::~Fish() {
    std::cout << "Fish destructor called." << std::endl;
}

void Fish::print() const {
    // ���������� ������ ���������� � ����
}

void Fish::save(std::ostream& os) const {
    // ���������� ���������� ������� ���� � ����
}

void Fish::load(std::istream& is) {
    // ���������� �������� ������� ���� �� �����
}
