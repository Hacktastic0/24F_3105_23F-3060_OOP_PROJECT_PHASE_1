#pragma once
// multiplayer.h
#ifndef MULTIPLAYER_ENGINE_H
#define MULTIPLAYER_ENGINE_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

const int MAP_SIZE = 5;
const int MAX_ALLIANCES = 10;
const int MAX_PLAYERS = 5;

class MultiplayerEngine {
public:
    string alliances[MAX_ALLIANCES][2];
    int allianceCount = 0;
    string players[MAX_PLAYERS];
    int playerCount;
    string mapGrid[MAP_SIZE][MAP_SIZE];
    int posX[MAX_PLAYERS], posY[MAX_PLAYERS];

    MultiplayerEngine(string p[], int count);
    void sendMessage(const string& from, const string& to);
    void formAlliance(const string& a, const string& b);
    void breakAlliance(const string& a, const string& b);
    bool isAllied(const string& a, const string& b);
    void tradeWithPlayer(const string& from, const string& to, const string& resource, int amount, bool smuggle);
    void attackKingdom(const string& attacker, const string& defender, int atkPower, int defPower, int& atkGold, int& defGold, int& atkFood);
    void moveKingdom(const string& player, int dx, int dy);
    void showMap();
    void showAlliances();

private:
    void logTreaty(const string& msg);
    int getPlayerIndex(const string& name);
};

#endif