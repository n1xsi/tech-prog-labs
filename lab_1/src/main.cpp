#include <iostream>
#include <limits>
#include <windows.h>

#include "Keeper.h"
#include "Book.h"
#include "Textbook.h"
#include "Stationery.h"
#include "CustomException.h"

void showMenu() {
    std::cout << "\n======== Меню ========\n";
    std::cout << "1. Добавить книгу\n";
    std::cout << "2. Добавить учебник\n";
    std::cout << "3. Добавить канцелярию\n";
    std::cout << "4. Показать все товары\n";
    std::cout << "5. Удалить товар по номеру\n";
    std::cout << "6. Сохранить в файл\n";
    std::cout << "7. Загрузить из файла\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите опцию: ";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Keeper keeper;
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Ошибка: введено не число. Попробуйте снова.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        try {
            switch (choice) {
                case 1: {
                    StoreItem* book = new Book();
                    book->input();
                    keeper.add(book);
                    break;
                }
                case 2: {
                    StoreItem* textbook = new Textbook();
                    textbook->input();
                    keeper.add(textbook);
                    break;
                }
                case 3: {
                    StoreItem* stationery = new Stationery();
                    stationery->input();
                    keeper.add(stationery);
                    break;
                }
                case 4:
                    keeper.displayAll();
                    break;
                case 5: {
                    if (keeper.getSize() == 0) {
                        std::cout << "Каталог пуст, удалять нечего.\n";
                        break;
                    }
                    std::cout << "Введите номер товара для удаления (1-" << keeper.getSize() << "): ";
                    int index;
                    std::cin >> index;
                    keeper.remove(index - 1);
                    std::cout << "Товар #" << index << " удален.\n";
                    break;
                }
                case 6:
                    keeper.saveToFile("data.txt");
                    break;
                case 7:
                    keeper.loadFromFile("data.txt");
                    break;
                case 0:
                    std::cout << "Выход из программы...\n";
                    break;
                default:
                    std::cout << "Неверная опция. Попробуйте снова.\n";
                    break;
            }
        } catch (const CustomException& e) {
            std::cerr << "Произошла ошибка: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Произошла неизвестная ошибка." << std::endl;
        }

    } while (choice != 0);

    return 0;
}
