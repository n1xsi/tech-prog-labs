#include "../include/Book.h"
#include <iostream>

Book::Book() : StoreItem(), year(0), pages(0) {
    std::cout << "Book: Default constructor called." << std::endl;
}

Book::Book(std::string t, std::string a, int y, std::string an, std::string g, int p, double price)
        : StoreItem(price), title(t), author(a), year(y), annotation(an), genre(g), pages(p) {
    std::cout << "Book: Parameterized constructor called." << std::endl;
}

Book::Book(const Book& other)
        : StoreItem(other), title(other.title), author(other.author), year(other.year),
          annotation(other.annotation), genre(other.genre), pages(other.pages) {
    std::cout << "Book: Copy constructor called." << std::endl;
}

Book::~Book() {
    std::cout << "Book: Destructor called." << std::endl;
}

void Book::print(std::ostream& os) const {
    os << "Книга" << std::endl;
    os << "Название: " << title << std::endl;
    os << "Автор: " << author << std::endl;
    os << "Год выпуска: " << year << std::endl;
    os << "Жанр: " << genre << std::endl;
    os << "Аннотация: " << annotation << std::endl;
    os << "Количество страниц: " << pages << std::endl;
    os << "Цена: " << price << " ₽" << std::endl;
}

StoreItem* Book::clone() const {
    return new Book(*this);
}

void Book::save(std::ofstream& fout) const {
    fout << title << std::endl;
    fout << author << std::endl;
    fout << year << std::endl;
    fout << annotation << std::endl;
    fout << genre << std::endl;
    fout << pages << std::endl;
    fout << price << std::endl;
}

void Book::load(std::ifstream& fin) {
    std::getline(fin, title);
    std::getline(fin, author);
    fin >> year;
    fin.ignore();
    std::getline(fin, annotation);
    std::getline(fin, genre);
    fin >> pages;
    fin >> price;
    fin.ignore();
}

void Book::input() {
    std::cout << "Введите название: "; std::getline(std::cin, title);
    std::cout << "Введите автора: "; std::getline(std::cin, author);
    std::cout << "Введите год выпуска: "; std::cin >> year; std::cin.ignore();
    std::cout << "Введите жанр: "; std::getline(std::cin, genre);
    std::cout << "Введите аннотацию: "; std::getline(std::cin, annotation);
    std::cout << "Введите кол-во страниц: "; std::cin >> pages;
    std::cout << "Введите цену: "; std::cin >> price;
    std::cin.ignore();
}