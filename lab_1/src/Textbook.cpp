#include "Textbook.h"
#include <iostream>

Textbook::Textbook() : StoreItem(), year(0), grade(0), pages(0) {
    std::cout << "Textbook: Default constructor called." << std::endl;
}

Textbook::Textbook(std::string t, std::string a, int y, std::string inst, int g, int p, double price)
        : StoreItem(price), title(t), author(a), year(y), institution(inst), grade(g), pages(p) {
    std::cout << "Textbook: Parameterized constructor called." << std::endl;
}

Textbook::Textbook(const Textbook& other)
        : StoreItem(other), title(other.title), author(other.author), year(other.year),
          institution(other.institution), grade(other.grade), pages(other.pages) {
    std::cout << "Textbook: Copy constructor called." << std::endl;
}

Textbook::~Textbook() {
    std::cout << "Textbook: Destructor called." << std::endl;
}

void Textbook::print(std::ostream& os) const {
    os << "Учебник" << std::endl;
    os << "Название: " << title << std::endl;
    os << "Автор: " << author << std::endl;
    os << "Год выпуска: " << year << std::endl;
    os << "Учебное заведение: " << institution << std::endl;
    os << "Год обучения (класс): " << grade << std::endl;
    os << "Количество страниц: " << pages << std::endl;
    os << "Цена: " << price << " ₽" << std::endl;
}

void Textbook::save(std::ofstream& fout) const {
    fout << title << std::endl;
    fout << author << std::endl;
    fout << year << std::endl;
    fout << institution << std::endl;
    fout << grade << std::endl;
    fout << pages << std::endl;
    fout << price << std::endl;
}

void Textbook::load(std::ifstream& fin) {
    std::getline(fin, title);
    std::getline(fin, author);
    fin >> year;
    fin.ignore();
    std::getline(fin, institution);
    fin >> grade;
    fin >> pages;
    fin >> price;
    fin.ignore();
}

void Textbook::input() {
    std::cout << "Введите название: "; std::getline(std::cin, title);
    std::cout << "Введите автора: "; std::getline(std::cin, author);
    std::cout << "Введите год выпуска: "; std::cin >> year; std::cin.ignore();
    std::cout << "Для какого учебного заведения: "; std::getline(std::cin, institution);
    std::cout << "Введите год обучения (класс): "; std::cin >> grade;
    std::cout << "Введите кол-во страниц: "; std::cin >> pages;
    std::cout << "Введите цену: "; std::cin >> price;
    std::cin.ignore();
}