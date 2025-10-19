#pragma once
#include <iostream>
#include <fstream>
#include <string>

class StoreItem {
protected:
    double price;
public:
    StoreItem();
    StoreItem(double price);
    StoreItem(const StoreItem& other);
    virtual ~StoreItem();

    void setPrice(double p);
    double getPrice() const;

    // Чисто виртуальные функции для полиморфизма
    virtual void display() const = 0;
    virtual void save(std::ofstream& fout) const = 0;
    virtual void load(std::ifstream& fin) = 0;

    // Виртуальные функции для ввода с консоли
    virtual void input() = 0;
};