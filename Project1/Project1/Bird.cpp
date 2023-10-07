// Bird.cpp
#include "Bird.h"

Bird::Bird() {
    std::cout << "Bird constructor called." << std::endl;
}

Bird::~Bird() {
    std::cout << "Bird destructor called." << std::endl;
}

void Bird::print() const {
    // Реализация вывода информации о рыбе
}

void Bird::save(std::ostream& os) const {
    // Реализация сохранения объекта рыбы в файл
}

void Bird::load(std::istream& is) {
    // Реализация загрузки объекта рыбы из файла
}
