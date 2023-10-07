// Fish.cpp
#include "Fish.h"

Fish::Fish() {
    std::cout << "Fish constructor called." << std::endl;
}

Fish::~Fish() {
    std::cout << "Fish destructor called." << std::endl;
}

void Fish::print() const {
    // Реализация вывода информации о рыбе
}

void Fish::save(std::ostream& os) const {
    // Реализация сохранения объекта рыбы в файл
}

void Fish::load(std::istream& is) {
    // Реализация загрузки объекта рыбы из файла
}
