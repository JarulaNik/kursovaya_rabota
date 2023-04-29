include "clicker.h"



Clicker::Clicker() : score(0) {}

void Clicker::increment() { // использовал инкремент для увеличения количества очков на единицу
    score++;
}

int Clicker::getScore() const {
    return score; //возвращает значение очков
}
