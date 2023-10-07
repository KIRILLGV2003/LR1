// Cat.cpp
#include "Cat.h"

Cat::Cat() {
    std::cout << "Cat constructor called." << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::print() const {
    // Реализация вывода информации о рыбе
}

void Cat::save(std::ostream& os) const {
    // Реализация сохранения объекта рыбы в файл
}

void Cat::load(std::istream& is) {
    // Реализация загрузки объекта рыбы из файла
}
