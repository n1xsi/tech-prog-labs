#pragma once
#include "StoreItem.h"

class Textbook : public StoreItem {

private:
    std::string title;
    std::string author;
    int year;
    std::string institution;  // Для какого учебного заведения
    int grade;                // Год обучения
    int pages;

public:
    Textbook();
    Textbook(std::string t, std::string a, int y, std::string inst, int g, int p, double price);
    Textbook(const Textbook& other);
    ~Textbook();

    void display() const override;
    void save(std::ofstream& fout) const override;
    void load(std::ifstream& fin) override;
    void input() override;

};