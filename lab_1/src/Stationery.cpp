#include "Stationery.h"
#include <iostream>

Stationery::Stationery() : StoreItem() {
    std::cout << "Stationery: Default constructor called." << std::endl;
}

Stationery::Stationery(std::string t, std::string c, std::string p, double price)
        : StoreItem(price), type(t), color(c), purpose(p) {
    std::cout << "Stationery: Parameterized constructor called." << std::endl;
}

Stationery::Stationery(const Stationery& other)
        : StoreItem(other), type(other.type), color(other.color), purpose(other.purpose) {
    std::cout << "Stationery: Copy constructor called." << std::endl;
}

Stationery::~Stationery() {
    std::cout << "Stationery: Destructor called." << std::endl;
}

void Stationery::display() const {
    std::cout << "\uD83D\uDCCC Канцелярия" << std::endl;
    std::cout << "Тип: " << type << std::endl;
    std::cout << "Цвет: " << color << std::endl;
    std::cout << "Назначение: " << purpose << std::endl;
    std::cout << "Цена: " << price << " ₽" << std::endl;
}

void Stationery::save(std::ofstream& fout) const {
    fout << type << std::endl;
    fout << color << std::endl;
    fout << purpose << std::endl;
    fout << price << std::endl;
}

void Stationery::load(std::ifstream& fin) {
    std::getline(fin, type);
    std::getline(fin, color);
    std::getline(fin, purpose);
    fin >> price;
    fin.ignore();
}

void Stationery::input() {
    std::cout << "Введите тип канцелярии: "; std::getline(std::cin, type);
    std::cout << "Введите цвет: "; std::getline(std::cin, color);
    std::cout << "Введите назначение: "; std::getline(std::cin, purpose);
    std::cout << "Введите цену: "; std::cin >> price;
    std::cin.ignore();
}