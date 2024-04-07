#include <iostream>
#include <fstream>
#include "Game.h"

using namespace std;

std::string Game::getName() const {
    return name;
}

int Game::getPrice() const {
    return price;
}

int Game::getRating() const {
    return rating;
}

void Game::setName(const string& newName) {
    name = newName;
}

void Game::setPrice(int newPrice) {
    price = newPrice;
}

void Game::setRating(int newRating) {
    rating = newRating;
}
std::istream& operator>>(std::istream& in, Game& game) {
    std::cout << "Enter game name: ";
    in >> game.name;
    std::cout << "Enter price: ";
    in >> game.price;
    std::cout << "Enter rating: ";
    in >> game.rating;
    return in;
}

// Перегрузка оператора вывода для класса Game
std::ostream& operator<<(std::ostream& out, const Game& game) {
    out << "Name: " << game.name << ", Price: " << game.price << ", Rating: " << game.rating;
    return out;
}
