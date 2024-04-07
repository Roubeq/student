#pragma once
#include "Game.h"

namespace Func {
    void save(Game* arr, const int& n);
    Game* load(int& n);
    int check(int* m);
    void create(Game** arr, int* n);
    void find(Game* arr, int* n, int nn);
    void edit(Game* arr);
    void read(Game** arr, int* n);
    void removeElement(Game* arr, int& n, int index);
}