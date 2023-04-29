#pragma once
#include "chrono"
#include "clicker.h"
#include "player.h"


class Game { //класс игры
public:
    Game();

    [[noreturn]] void run();

private: //приватный класс, в котором содержатся используемые функции
    Clicker clicker;
    Player player;
    void displayInstructions();
    void processInput();
    void update();
    void draw();
    std::chrono::steady_clock::time_point lastUpdateTime;
    int updateInterval;
};
