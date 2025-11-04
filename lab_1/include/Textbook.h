#pragma once
#include "StoreItem.h"

class Textbook : public StoreItem {

private:
    std::string title;
    std::string author;
    int year;
    std::string institution;
    int grade;
    int pages;

public:
    Textbook();
    Textbook(std::string t, std::string a, int y, std::string inst, int g, int p, double price);
    Textbook(const Textbook& other);
    ~Textbook();

    // Реализация виртуальных функций базового класса
    void print(std::ostream& os) const override;
    void save(std::ofstream& fout) const override;
    void load(std::ifstream& fin) override;
    void input() override;
    StoreItem* clone() const override;

};