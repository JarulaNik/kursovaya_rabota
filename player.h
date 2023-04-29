#pragma once //следит, чтобы файл при компиляции подключался один раз

#include "clicker.h"

class Player {
public:
    Player(Clicker &clicker);
    void click();

private:
    Clicker &clicker;
};
