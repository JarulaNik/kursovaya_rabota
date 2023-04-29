#pragma once

class Clicker { //класс самого кликера
public:
    Clicker();
    void increment();
    int getScore() const;

private:
    int score;
};
