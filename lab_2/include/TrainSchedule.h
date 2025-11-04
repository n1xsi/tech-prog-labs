#pragma once
#include "Train.h"

class TrainSchedule {

private:
    Train* trains;
    int size;
    int capacity;

    void resize();

public:
    TrainSchedule();
    ~TrainSchedule();

    void addTrain();
    void addTrain(const Train& train);
    void deleteTrain(int index);
    void editTrain(int index);
    void displayAll() const;
    void findByDestination() const;
    int getSize() const;

};