#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>

class Clicker {
public:
    Clicker() : score(0) {}
    void increment() { score++; }
    [[nodiscard]] int getScore() const { return score; } //не удаляет предыдущее значение из памяти, позволит создать на этой базе турнирную таблицу

private:
    int score;
};

class Player {
public:
    explicit Player(Clicker &clicker) : clicker(clicker) {}
    void click() { clicker.increment(); }

private:
    Clicker &clicker;
};

class Game {
public:
    Game() : clicker(), player(clicker) {}

    [[noreturn]] void run();

private:
    Clicker clicker;
    Player player;
    static void displayInstructions();
    void processInput();
    void update();
    void draw();
    static bool kbhit();


};

 void Game::run() {
    displayInstructions();

    while (true) {
        if (kbhit()) {
            processInput();
        }
        update();
        draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Game::displayInstructions() {
    std::cout << "Welcome to the Clicker Game! It's my university project." << std::endl;
    std::cout << "Press 'Enter' to click and 'Q' to quit." << std::endl;
}

void Game::processInput() {
    int input = _getch(); //считывает один символ с клавиатуры

    if ((reinterpret_cast<const char *>(input) == "Enter" || reinterpret_cast<const char *>(input) == "c" )) {
        player.click();
    } else if (input == 'Q' || input == 'q') {
        exit(0);
    }
}

void Game::update() {
    //оставил возможность улучшения игры(добавления рекорда или 'бой с тенью'
}

void Game::draw() {
    system("cls");
    std::cout << "Score: " << clicker.getScore() << std::endl;
}

bool Game::kbhit() {
    return _kbhit() != 0;
}
