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

    // �������� get � set ������� �� �������������

protected:
    // ����� �������������� ��� ���� ��������
    std::string breed;
    std::string color;

private:
    // �������������� ����� ��������������
};

#endif // ANIMAL_H
