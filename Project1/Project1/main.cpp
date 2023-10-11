#include <iostream>
#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

int main() {
    Keeper keeper;

    while (true) {
        std::cout << "\nMenu:\n"
            "1. Add Fish\n"
            "2. Add Bird\n"
            "3. Add Cat\n"
            "4. Remove Animal\n"
            "5. Print All Animals\n"
            "6. Save to File\n"
            "7. Load from File\n"
            "8. Exit\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            char breed[100], color[100], diet[100];
            std::cout << "Enter Fish details:\n";
            std::cout << "Breed: ";
            std::cin >> breed;
            std::cout << "Color: ";
            std::cin >> color;
            std::cout << "Diet: ";
            std::cin >> diet;
            keeper.addAnimal(new Fish(breed, color, diet));
            break;
        }
        case 2: {
            char breed[100], color[100], diet[100], habitat[100];
            std::cout << "Enter Bird details:\n";
            std::cout << "Breed: ";
            std::cin >> breed;
            std::cout << "Color: ";
            std::cin >> color;
            std::cout << "Diet: ";
            std::cin >> diet;
            std::cout << "Habitat: ";
            std::cin >> habitat;
            keeper.addAnimal(new Bird(breed, color, diet, habitat));
            break;
        }
        case 3: {
            char breed[100], color[100], ownerName[100], petName[100];
            std::cout << "Enter Cat details:\n";
            std::cout << "Breed: ";
            std::cin >> breed;
            std::cout << "Color: ";
            std::cin >> color;
            std::cout << "Owner's Name: ";
            std::cin >> ownerName;
            std::cout << "Pet Name: ";
            std::cin >> petName;
            keeper.addAnimal(new Cat(breed, color, ownerName, petName));
            break;
        }
        case 4: {
            int index;
            std::cout << "Enter the index of the animal to remove: ";
            std::cin >> index;
            keeper.removeAnimal(index);
            break;
        }
        case 5:
            std::cout << "All Animals:\n";
            keeper.printAllAnimals();
            break;
        case 6: {
            char filename[100];
            std::cout << "Enter the filename to save to: ";
            std::cin >> filename;
            keeper.saveToFile(filename);
            break;
        }
        case 7: {
            char filename[100];
            std::cout << "Enter the filename to load from: ";
            std::cin >> filename;
            keeper.loadFromFile(filename);
            break;
        }
        case 8:
            std::cout << "Exiting program.\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please enter a number from 1 to 8.\n";
        }
    }

    return 0;
}
