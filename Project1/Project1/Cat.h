// Cat.h
#include "Animal.h"
#ifndef CAT_H
#define CAT_H

class Cat : public Animal {
public:
    Cat();
    ~Cat();

    void print() const override;
    void save(std::ostream& os) const override;
    void load(std::istream& is) override;

    // Добавьте get и set функции по необходимости

private:
    std::string feedingType;
};

#endif // Cat_H
