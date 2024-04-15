#include "Func.h"
#include <fstream>
#include <iostream>
#include <string>

void Func::save(Game* arr, const int& n) {
    std::ofstream file("file.txt");
    if (!file.is_open()) {
        std::cout << "Error: could not open file.txt for saving" << std::endl;
        return;
    }
    file << n << std::endl;
    for (int i = 0; i < n; ++i) {
        file << arr[i] << std::endl;
    }
    file.close();
}

Game* Func::load(int& n) {
    std::ifstream file("file.txt");
    if (!file.is_open()) {
        std::cout << "Error: could not open file.txt for loading" << std::endl;
        return nullptr;
    }
    file >> n;
    Game* arr = new Game[n];
    for (int i = 0; i < n; ++i) {
        file >> arr[i];
    }
    file.close();
    return arr;
}

int Func::check(int* m) {
    if (std::cin >> *m)
        return 0;
    else {
        std::cout << "Error: please enter a number" << std::endl;
        while (getchar() != '\n');
        return 1;
    }
}

void Func::create(Game** arr, int* n) {
    std::cout << "Enter the number of games: ";
    if (check(n))
        return;
    if (*n <= 0)
        return;
    *arr = new Game[*n];
    for (int i = 0; i < *n; ++i) {
        std::cin >> (*arr)[i];
    }
}

void Func::find(Game* arr, int* n, int option) {
    switch (option) {
    case 1: {
        std::string name;
        std::cout << "Enter the name of the game: ";
        std::cin >> name;
        bool found = false;
        for (int i = 0; i < *n; ++i) {
            if (name == arr[i].getName()) {
                std::cout << "Found: " << arr[i] << std::endl;
                found = true;
            }
        }
        if (!found)
            std::cout << "Game not found." << std::endl;
        break;
    }
    case 2: {
        float price;
        std::cout << "Enter the maximum price: ";
        std::cin >> price;
        bool found = false;
        for (int i = 0; i < *n; ++i) {
            if (arr[i].getPrice() <= price) {
                std::cout << "Found: " << arr[i] << std::endl;
                found = true;
            }
        }
        if (!found)
            std::cout << "No games found within the specified price range." << std::endl;
        break;
    }
    case 3: {
        float rating;
        std::cout << "Enter the minimum rating: ";
        std::cin >> rating;
        bool found = false;
        for (int i = 0; i < *n; ++i) {
            if (arr[i].getRating() >= rating) {
                std::cout << "Found: " << arr[i] << std::endl;
                found = true;
            }
        }
        if (!found)
            std::cout << "No games found with the specified minimum rating." << std::endl;
        break;
    }
    default:
        std::cout << "Invalid option." << std::endl;
        break;
    }
}

void Func::edit(Game* arr) {
    std::cout << "Enter new game details:" << std::endl;
    std::cin >> *arr;
    std::cout << "Game edited successfully." << std::endl;
}
#include <fstream>

void Func::read(Game** arr, int* n) {
    std::ifstream file("file.txt");
    if (!file.is_open()) {
        std::cout << "Error: could not open file.txt for reading" << std::endl;
        return;
    }

    if (!(file >> *n) || *n <= 0) {
        std::cout << "Error: invalid number of records" << std::endl;
        file.close();
        return;
    }

    *arr = new Game[*n];

    for (int i = 0; i < *n; ++i) {
        std::string name;
        int price, rating;
        if (!(file >> name >> price >> rating)) {
            std::cout << "Error: failed to read game data" << std::endl;
            delete[] * arr;
            *arr = nullptr;
            file.close();
            return;
        }
        (*arr)[i].setName(name);
        (*arr)[i].setPrice(price);
        (*arr)[i].setRating(rating);
    }

    file.close();
}


void Func::removeElement(Game*& arr, int& n, int index) {
    if (index < 0 || index >= n) {
        std::cout << "index out of range" << std::endl;
        return;
    }

    Game* newArr = new Game[n - 1];
    int newArrIndex = 0;

    for (int i = 0; i < n; ++i) {
        if (i != index) {
            newArr[newArrIndex] = arr[i];
            ++newArrIndex;
        }
    }
    delete[] arr;
    arr = newArr;
    --n;
}