#pragma once
#include <iostream>
#include <string>

class Game {
private:
    std::string name;
    int price = 0;
    int rating = 0;
public:
    // Геттеры
    std::string getName() const;
    int getPrice() const;
    int getRating() const;

    // Сеттеры
    void setName(const std::string& newName);
    void setPrice(int newPrice);
    void setRating(int newRating);

    // Перегрузка операторов ввода и вывода
    friend std::istream& operator>>(std::istream& in, Game& game);
    friend std::ostream& operator<<(std::ostream& out, const Game& game);
};