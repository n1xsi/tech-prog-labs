#pragma once
#include "StoreItem.h"
#include <string>

class Keeper {

private:
    StoreItem** items;
    int size;

public:
    Keeper();
    Keeper(const Keeper& other);             // Конструктор копирования
    Keeper& operator=(const Keeper& other);  // Оператор присваивания
    ~Keeper();

    void add(StoreItem* newItem);
    void remove(int index);
    void displayAll() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    int getSize() const;
};