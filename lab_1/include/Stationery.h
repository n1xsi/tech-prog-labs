#pragma once
#include "StoreItem.h"

class Stationery : public StoreItem {
private:
    std::string type;
    std::string color;
    std::string purpose;
public:
    Stationery();
    Stationery(std::string t, std::string c, std::string p, double price);
    Stationery(const Stationery& other);
    ~Stationery();

    // Реализация виртуальныж функций базового класса
    void print(std::ostream& os) const override;
    void save(std::ofstream& fout) const override;
    void load(std::ifstream& fin) override;
    void input() override;
    StoreItem* clone() const override;
};