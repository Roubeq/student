#include <iostream>
#include "Game.h"
#include "func.h"

using namespace std;



int main() {
    Game* arr = nullptr;
    int n = 0;
    int stop = 0;

    while (stop != 1) {
        int key = 0;
        std::cout << "1-create, 2-read, 3-print, 4-find, 5-clear file, 6-edit, 7-exit" << std::endl;
        Func::check(&key);

        switch (key) {
        case 1:
            Func::create(&arr, &n);
            if (arr)
                Func::save(arr, n);
            break;
        case 2:
            Func::read(&arr, &n);
            if (!arr) {
                std::cout << "read error" << std::endl;
            }
            else {
                std::cout << "loaded " << n << " games" << std::endl;
            }
            break;
        case 3:
            for (int i = 0; i < n; i++)
                std::cout << "Name: " << arr[i].getName() << ", Price: " << arr[i].getPrice() << ", Rating: " << arr[i].getRating() << std::endl;
            break;
        case 4:
            std::cout << "1-search by name, 2-search by price, 3-search by rating" << std::endl;
            int x;
            std::cin >> x;
            Func::find(arr, &n, x);
            break;
        case 5: {
            std::cout << "Enter the index for delete element: ";
            int index;
            std::cin >> index;
            Func::removeElement(arr, n, index);
            break;
        }
        case 6: {
            std::cout << "Enter the index of the game you want to edit: ";
            int index;
            std::cin >> index;

            if (index >= 0 && index < n) {
                Func::edit(&arr[index]);
                Func::save(arr, n); // Save changes after editing
            }
            else {
                std::cout << "Invalid index." << std::endl;
            }
            break;
        }
        case 7:
            stop = 1;
            break;
        default:
            std::cout << "Invalid option." << std::endl;
            break;
        }
    }

    delete[] arr;
    return 0;
}
