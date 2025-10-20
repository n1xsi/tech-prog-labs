#pragma once
#include "StoreItem.h"

class Keeper {

private:
    StoreItem** items;
    int size;

public:
    Keeper();
    ~Keeper();

    void add(StoreItem* newItem);
    void remove(int index);
    void displayAll() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    int getSize() const;

};