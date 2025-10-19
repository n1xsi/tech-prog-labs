#include "StoreItem.h"

StoreItem::StoreItem() : price(0.0) {
    std::cout << "StoreItem: Default constructor called." << std::endl;
}

StoreItem::StoreItem(double price) : price(price) {
    std::cout << "StoreItem: Parameterized constructor called." << std::endl;
}

StoreItem::StoreItem(const StoreItem& other) : price(other.price) {
    std::cout << "StoreItem: Copy constructor called." << std::endl;
}

StoreItem::~StoreItem() {
    std::cout << "StoreItem: Destructor called." << std::endl;
}

void StoreItem::setPrice(double p) {
    if (p < 0) p = 0;
    this->price = p;
}

double StoreItem::getPrice() const {
    return price;
}