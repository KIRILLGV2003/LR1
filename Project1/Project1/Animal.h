// Animal.h
#include <iostream>
#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
public:
    Animal();
    virtual ~Animal();

    virtual void print() const = 0;
    virtual void save(std::ostream& os) const;
    virtual void load(std::istream& is);

    // Добавьте get и set функции по необходимости

protected:
    // Общие характеристики для всех животных
    std::string breed;
    std::string color;

private:
    // Дополнительные общие характеристики
};

#endif // ANIMAL_H
