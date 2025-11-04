#define _CRT_SECURE_NO_WARNINGS

#include "Train.h"
#include <cstring>
#include "CustomException.h"

// Приватный метод для копирования данных (избегание DRY)
void Train::copy(const Train& other) {
    this->destination = new char[strlen(other.destination) + 1];
    strcpy(this->destination, other.destination);

    this->trainNumber = other.trainNumber;

    this->departureTime = new char[strlen(other.departureTime) + 1];
    strcpy(this->departureTime, other.departureTime);
}

Train::Train() : destination(nullptr), trainNumber(0), departureTime(nullptr) {
    std::cout << "  [DEBUG] Вызван конструктор по умолчанию Train" << std::endl;
    destination = new char[8];
    strcpy(destination, "Unknown");
    departureTime = new char[6];
    strcpy(departureTime, "00:00");
}

Train::Train(const char* dest, int num, const char* time) {
    std::cout << "  [DEBUG] Вызван конструктор с параметрами Train для поезда N" << num << std::endl;
    destination = new char[strlen(dest) + 1];
    strcpy(destination, dest);
    trainNumber = num;
    departureTime = new char[strlen(time) + 1];
    strcpy(departureTime, time);
}

Train::Train(const Train& other) {
    std::cout << "  [DEBUG] Вызван конструктор копирования Train для поезда N" << other.trainNumber << std::endl;
    copy(other);
}

Train::~Train() {
    std::cout << "  [DEBUG] Вызван деструктор Train для поезда N" << trainNumber << std::endl;
    delete[] destination;
    delete[] departureTime;
}

Train& Train::operator=(const Train& other) {
    std::cout << "  [DEBUG] Вызван оператор присваивания Train для поезда N" << other.trainNumber << std::endl;
    if (this != &other) {
        delete[] destination;
        delete[] departureTime;
        copy(other);
    }
    return *this;
}

const char* Train::getDestination() const { return destination; }
int Train::getTrainNumber() const { return trainNumber; }
const char* Train::getDepartureTime() const { return departureTime; }

void Train::setDestination(const char* dest) {
    delete[] destination;
    destination = new char[strlen(dest) + 1];
    strcpy(destination, dest);
}

void Train::setTrainNumber(int num) {
    trainNumber = num;
}

void Train::setDepartureTime(const char* time) {
    if (strlen(time) != 5 || time[2] != ':') {
        throw CustomException("Неверный формат времени, ожидалось ЧЧ:ММ");
    }
    delete[] departureTime;
    departureTime = new char[strlen(time) + 1];
    strcpy(departureTime, time);
}

std::ostream& operator<<(std::ostream& os, const Train& train) {
    os << "Поезд N" << train.trainNumber << " | Пункт назначения: " << train.destination
       << " | Время отправления: " << train.departureTime;
    return os;
}

std::istream& operator>>(std::istream& is, Train& train) {
    char dest_buf[100];
    char time_buf[6];

    std::cout << "Введите пункт назначения: ";
    is >> dest_buf;
    std::cout << "Введите номер поезда: ";
    is >> train.trainNumber;
    std::cout << "Введите время отправления (ЧЧ:ММ): ";
    is >> time_buf;

    train.setDestination(dest_buf);
    train.setDepartureTime(time_buf);  // Сеттер для валидации

    return is;
}