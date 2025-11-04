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

    // Виртуальный метод для полиморфного вывода
    virtual void print(std::ostream& os) const = 0;

    // Методы для сохранения, загрузки и ввода с консоли
    virtual void save(std::ofstream& fout) const = 0;
    virtual void load(std::ifstream& fin) = 0;
    virtual void input() = 0;

    // Виртуальный "конструктор копирования" для глубокого копирования в Keeper
    virtual StoreItem* clone() const = 0;
};

// Дружественная функция для переопределения оператора <<
std::ostream& operator<<(std::ostream& os, const StoreItem& item);