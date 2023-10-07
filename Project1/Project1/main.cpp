// main.cpp
#include "Animal.h"
#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

int main() {
    Keeper keeper;

    while (true) {
        std::cout << "\n=== Menu ===\n";
        std::cout << "1. Add Fish\n";
        std::cout << "2. Add Bird\n";
        std::cout << "3. Add Cat\n";
        std::cout << "4. Remove Animal\n";
        std::cout << "5. Print All Animals\n";
        std::cout << "6. Save to File\n";
        std::cout << "7. Load from File\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Fish* fish = new Fish();
            fish->load(std::cin); // Пользователь вводит данные о рыбе
            keeper.addAnimal(fish);
            break;
        }
        case 2: {
            Bird* bird = new Bird();
            bird->load(std::cin); // Пользователь вводит данные о птице
            keeper.addAnimal(bird);
            break;
        }
        case 3: {
            Cat* cat = new Cat();
            cat->load(std::cin); // Пользователь вводит данные о кошке
            keeper.addAnimal(cat);
            break;
        }
        case 4: {
            std::cout << "Enter the index of the animal to remove: ";
            int index;
            std::cin >> index;
            keeper.removeAnimal(index);
            break;
        }
        case 5:
            keeper.printAllAnimals();
            break;
        case 6: {
            std::cout << "Enter the filename to save: ";
            std::string filename;
            std::cin >> filename;
            keeper.saveToFile(filename);
            break;
        }
        case 7: {
            std::cout << "Enter the filename to load: ";
            std::string filename;
            std::cin >> filename;
            keeper.loadFromFile(filename);
            break;
        }
        case 8:
            return 0; // Выход из программы
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
