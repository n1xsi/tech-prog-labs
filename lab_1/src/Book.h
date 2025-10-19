#pragma once
#include "StoreItem.h"

class Book : public StoreItem {

private:
    std::string title;
    std::string author;
    std::string annotation;
    std::string genre;
    int year;
    int pages;

public:
    Book();
    Book(std::string t, std::string a, int y, std::string an, std::string g, int p, double price);
    Book(const Book& other);
    ~Book();

    void display() const override;
    void save(std::ofstream& fout) const override;
    void load(std::ifstream& fin) override;
    void input() override;

};