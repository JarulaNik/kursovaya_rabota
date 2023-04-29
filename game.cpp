#include <iostream>
#include <chrono> //библиотека для работы со временем; оставил задел для создания игры на платформе(пк/моб)
#include <thread>
#include "game.h"

Game::Game() : clicker(), player(clicker), lastUpdateTime(std::chrono::steady_clock::now()), updateInterval(100) {}


[[noreturn]] void Game::run() { //выводит заставку с приветствием
    displayInstructions();

    while (true) {
        processInput();
        update();
        draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); //устанавливает время между регистрацией нажатий
    }
}

void Game::displayInstructions() { //функция, в которой содержится выводимая инструкция
    std::cout << "Welcome to the Clicker Game! It's my university project." << std::endl;
    std::cout << "Press 'Enter' to click and 'Q' to quit." << std::endl;
}

void Game::processInput() {
    char input;
    std::cin.get(input);


}

void Game::update() {
    auto currentTime = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastUpdateTime).count() >= updateInterval) {
        player.click();
        lastUpdateTime = currentTime;
    }
}


void Game::draw() { //функция, выводящая текущее количество очков, которые 'накликал' игрок
    std::cout << "Score: " << clicker.getScore() << std::endl; //вывзывает метод getScore
}
