#include <iostream>
#include <windows.h>
#include "TrainSchedule.h"
#include "CustomException.h"

void showMenu() {
    std::cout << "\n===== Меню управления расписанием =====\n"
              << "1. Показать все поезда\n"
              << "2. Добавить поезд\n"
              << "3. Редактировать поезд по индексу\n"
              << "4. Удалить поезд по индексу\n"
              << "5. Найти поезда по пункту назначения\n"
              << "0. Выход\n"
              << "=======================================\n"
              << "Ваш выбор: ";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    TrainSchedule schedule;

    // Заполнение для примера
    schedule.addTrain(Train("Москва", 101, "09:30"));
    schedule.addTrain(Train("Моршанск", 25, "08:15"));
    schedule.addTrain(Train("Санкт-Петербург", 7, "14:00"));
    schedule.addTrain(Train("Туймазы", 105, "11:00"));

    int choice;
    do {
        showMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Ошибка: введено не число. Попробуйте снова." << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n');  // Очистка буфера ввода
            choice = -1;                     // Чтобы цикл продолжился
            continue;
        }

        try {
            switch (choice) {
                case 1:
                    schedule.displayAll();
                    break;
                case 2:
                    schedule.addTrain();
                    break;
                case 3: {
                    if (schedule.getSize() == 0) {
                        std::cout << "Расписание пусто - нечего редактировать." << std::endl;
                        break;
                    }
                    int index;
                    std::cout << "Введите индекс поезда для редактирования (0-" << schedule.getSize() - 1 << "): ";
                    std::cin >> index;
                    schedule.editTrain(index);
                    break;
                }
                case 4: {
                    if (schedule.getSize() == 0) {
                        std::cout << "Расписание пусто - нечего удалять." << std::endl;
                        break;
                    }
                    int index;
                    std::cout << "Введите индекс поезда для удаления (0-" << schedule.getSize() - 1 << "): ";
                    std::cin >> index;
                    schedule.deleteTrain(index);
                    break;
                }
                case 5:
                    schedule.findByDestination();
                    break;
                case 0:
                    std::cout << "Завершение программы." << std::endl;
                    break;
                default:
                    std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
                    break;
            }
        } catch(const CustomException& e) {
            std::cerr << "Произошла ошибка: " << e.what() << std::endl;
        }
    } while (choice != 0);

    return 0;
}