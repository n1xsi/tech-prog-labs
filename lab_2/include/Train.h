#pragma once
#include <iostream>

class Train {

private:
    char* destination;
    int trainNumber;
    char* departureTime;  // Формат "ЧЧ:ММ"

    void copy(const Train& other);

public:
    // Конструкторы и деструктор
    Train();
    Train(const char* dest, int num, const char* time);
    Train(const Train& other);
    ~Train();

    // Оператор присваивания
    Train& operator=(const Train& other);

    // Методы доступа (getters и setters)
    const char* getDestination() const;
    int getTrainNumber() const;
    const char* getDepartureTime() const;

    void setDestination(const char* dest);
    void setTrainNumber(int num);
    void setDepartureTime(const char* time);

    // Дружественные функции для перегрузки операторов ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Train& train);
    friend std::istream& operator>>(std::istream& is, Train& train);

};