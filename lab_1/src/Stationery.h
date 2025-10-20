#pragma once
#include "StoreItem.h"

class Stationery : public StoreItem {

private:
    std::string type;     // Тип канцелярии
    std::string color;
    std::string purpose;  // Назначение

public:
    Stationery();
    Stationery(std::string t, std::string c, std::string p, double price);
    Stationery(const Stationery& other);
    ~Stationery();

    void display() const override;
    void save(std::ofstream& fout) const override;
    void load(std::ifstream& fin) override;
    void input() override;

};