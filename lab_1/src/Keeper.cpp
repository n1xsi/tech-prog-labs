#include "Keeper.h"
#include "Book.h"
#include "Textbook.h"
#include "Stationery.h"
#include "CustomException.h"
#include <iostream>
#include <fstream>

Keeper::Keeper() : items(nullptr), size(0) {
    std::cout << "Keeper: Default constructor called." << std::endl;
}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete items[i];
    }
    delete[] items;
    std::cout << "Keeper: Destructor called." << std::endl;
}

void Keeper::add(StoreItem* newItem) {
    StoreItem** temp = new StoreItem*[size + 1];
    for (int i = 0; i < size; ++i) {
        temp[i] = items[i];
    }
    temp[size] = newItem;
    delete[] items;
    items = temp;
    size++;
}

void Keeper::remove(int index) {
    if (index < 0 || index >= size) {
        throw CustomException("Error: Invalid index for removal.");
    }

    delete items[index];

    StoreItem** temp = new StoreItem*[size - 1];
    for (int i = 0, j = 0; i < size; ++i) {
        if (i != index) {
            temp[j++] = items[i];
        }
    }
    delete[] items;
    items = temp;
    size--;
}

void Keeper::displayAll() const {
    if (size == 0) {
        std::cout << "Каталог пуст." << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << "\n--- Элемент #" << i + 1 << " ---" << std::endl;
        items[i]->display();
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        throw CustomException("Error: Could not open file for writing.");
    }
    fout << size << std::endl;
    for (int i = 0; i < size; ++i) {
        if (dynamic_cast<Book*>(items[i])) {
            fout << 1 << std::endl; // 1 для Book
        } else if (dynamic_cast<Textbook*>(items[i])) {
            fout << 2 << std::endl; // 2 для Textbook
        } else if (dynamic_cast<Stationery*>(items[i])) {
            fout << 3 << std::endl; // 3 для Stationery
        }
        items[i]->save(fout);
    }
    fout.close();
    std::cout << "Данные успешно сохранены в файл " << filename << std::endl;
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        throw CustomException("Error: Could not open file for reading.");
    }

    // Очистка текущих данных
    for (int i = 0; i < size; ++i) {
        delete items[i];
    }
    delete[] items;
    items = nullptr;
    size = 0;

    int count;
    fin >> count;
    fin.ignore();

    for (int i = 0; i < count; ++i) {
        int type;
        fin >> type;
        fin.ignore();
        StoreItem* newItem = nullptr;
        switch (type) {
            case 1: newItem = new Book(); break;
            case 2: newItem = new Textbook(); break;
            case 3: newItem = new Stationery(); break;
            default:
                throw CustomException("Error: Unknown object type in file.");
        }
        newItem->load(fin);
        add(newItem);
    }
    fin.close();
    std::cout << "Данные успешно загружены из файла " << filename << std::endl;
}

int Keeper::getSize() const {
    return size;
}