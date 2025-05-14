#pragma once
// game.h
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Kingdom {
public:
    string name;
    int gold, wood, food;
    int houses, population;
    int swords, bows, maces;
    int fruitFarms, grainFarms;
    int woodcutters, workshops;
    int goldMines, ironMines;
    int barracks, archers, swordsmen, macemen;

    Kingdom(string playerName);
    void log(string message);
    int randomBetween(int low, int high);
    void buildMenu();
    void buildBarracks();
    void buildFarm();
    void buildHouse();
    void buildMine();
    void buildWoodcutter();
    void buildWorkshop();
    void trainSoldiers();
    void trade();
    void status();
    void saveGame();
    void loadGame();
    void showTradeRecords();
};

#endif