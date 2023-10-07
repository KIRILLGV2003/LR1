// Bird.h
#include "Animal.h"
#ifndef BIRD_H
#define BIRD_H

class Bird : public Animal {
public:
    Bird();
    ~Bird();

    void print() const override;
    void save(std::ostream& os) const override;
    void load(std::istream& is) override;

    // Добавьте get и set функции по необходимости

private:
    std::string feedingType;
};

#endif // Bird_H
