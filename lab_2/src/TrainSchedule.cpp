#include "TrainSchedule.h"
#include "CustomException.h"
#include <iostream>
#include <cstring>

TrainSchedule::TrainSchedule() : trains(nullptr), size(0), capacity(2) {
    std::cout << "  [DEBUG] Создание объекта TrainSchedule" << std::endl;
    trains = new Train[capacity];
}

TrainSchedule::~TrainSchedule() {
    std::cout << "  [DEBUG] Уничтожение объекта TrainSchedule" << std::endl;
    delete[] trains;
}

void TrainSchedule::resize() {
    capacity *= 2;
    std::cout << "  [DEBUG] Увеличение вместимости массива до " << capacity << std::endl;
    Train* newTrains = new Train[capacity];
    for (int i = 0; i < size; ++i) {
        newTrains[i] = trains[i];
    }
    delete[] trains;
    trains = newTrains;
}

void TrainSchedule::addTrain() {
    Train newTrain;
    try {
        std::cin >> newTrain;
        addTrain(newTrain);
    }
    catch (const CustomException& e) {
        std::cerr << "Ошибка добавления: " << e.what() << std::endl;
    }
}

void TrainSchedule::addTrain(const Train& newTrain) {
    if (size == capacity) {
        resize();
    }

    // Поиск позиции для вставки для сохранения сортировки по времени
    int insert_pos = 0;
    while (insert_pos < size && strcmp(trains[insert_pos].getDepartureTime(), newTrain.getDepartureTime()) < 0) {
        insert_pos++;
    }

    for (int i = size; i > insert_pos; --i) {
        trains[i] = trains[i - 1];
    }

    trains[insert_pos] = newTrain;
    size++;
    std::cout << "Поезд успешно добавлен в расписание." << std::endl;
}

void TrainSchedule::deleteTrain(int index) {
    if (index < 0 || index >= size) {
        throw CustomException("Неверный индекс для удаления!");
    }

    for (int i = index; i < size - 1; ++i) {
        trains[i] = trains[i + 1];
    }
    size--;
    std::cout << "Запись по индексу " << index << " успешно удалена." << std::endl;
}

void TrainSchedule::editTrain(int index) {
    if (index < 0 || index >= size) {
        throw CustomException("Неверный индекс для редактирования!");
    }
    std::cout << "==== Ввод новых данных для поезда (индекс " << index << ") ====" << std::endl;
    Train editedTrain;
    try {
        std::cin >> editedTrain;
        // Удаляем старую запись и добавляем новую, чтобы сохранить сортировку
        deleteTrain(index);
        addTrain(editedTrain);
        std::cout << "Запись успешно отредактирована." << std::endl;
    }
    catch (const CustomException& e) {
        std::cerr << "Ошибка редактирования: " << e.what() << std::endl;
    }
}

void TrainSchedule::displayAll() const {
    std::cout << "\n----> Текущее расписание поездов <----" << std::endl;
    if (size == 0) {
        std::cout << "Расписание пусто." << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << "  [" << i << "] " << trains[i] << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
}

void TrainSchedule::findByDestination() const {
    char dest_buf[100];
    std::cout << "\nВведите пункт назначения для поиска: ";
    std::cin >> dest_buf;

    std::cout << "<---> Поезда, следующие в г. " << dest_buf << " <--->" << std::endl;
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(trains[i].getDestination(), dest_buf) == 0) {
            std::cout << "  " << trains[i] << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Поездов в данном направлении не найдено." << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
}

int TrainSchedule::getSize() const { return size; }