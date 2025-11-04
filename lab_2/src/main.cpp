#include <iostream>
#include <windows.h>
#include "tasks.h"

void showMainMenu() {
    std::cout << "\n############ Главное меню ############\n"
              << "1. Запустить Задание 1 (Расписание поездов)\n"
              << "2. Запустить Задание 2 (Поиск цитат в файле)\n"
              << "0. Выход из программы\n"
              << "######################################\n"
              << "Ваш выбор: ";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int choice;
    do {
        showMainMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Ошибка: введено не число. Попробуйте снова." << std::endl;
            std::cin.clear();
            // Очистка буфера ввода до следующего символа новой строки
            while (std::cin.get() != '\n');
            choice = -1;  // Чтобы цикл продолжился
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "\n--1-- Запуск Задания 1 --1--\n";
                runTask1();
                std::cout << "\n--1-- Задание 1 завершено --1--\n";
                break;
            case 2:
                std::cout << "\n--2-- Запуск Задания 2 --2--\n";
                runTask2();
                std::cout << "\n--2-- Задание 2 завершено --2--\n";
                break;
            case 0:
                std::cout << "Завершение программы. До свидания!" << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
                break;
        }
    } while (choice != 0);

    return 0;
}