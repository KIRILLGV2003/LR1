// Fish.h
#include "Animal.h"
#ifndef FISH_H
#define FISH_H

class Fish : public Animal {
public:
    Fish();
    ~Fish();

    void print() const override;
    void save(std::ostream& os) const override;
    void load(std::istream& is) override;

    // Добавьте get и set функции по необходимости

private:
    std::string feedingType;
};

#endif // FISH_H
