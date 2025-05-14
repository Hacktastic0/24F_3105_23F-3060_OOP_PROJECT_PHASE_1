// multiplayer.cpp
#include "multiplayer.h"

MultiplayerEngine::MultiplayerEngine(string p[], int count) {
    playerCount = count;
    for (int i = 0; i < count; ++i) {
        players[i] = p[i];
        posX[i] = i % MAP_SIZE;
        posY[i] = i / MAP_SIZE;
        mapGrid[posX[i]][posY[i]] = p[i];
    }
}

void MultiplayerEngine::sendMessage(const string& from, const string& to) {
    string msg;
    cout << "Enter message to " << to << ": ";
    cin.ignore();
    getline(cin, msg);
    ofstream chat("chat.txt", ios::app);
    chat << from << " to " << to << ": " << msg << endl;
    chat.close();
}

void MultiplayerEngine::formAlliance(const string& a, const string& b) {
    if (allianceCount < MAX_ALLIANCES) {
        alliances[allianceCount][0] = a;
        alliances[allianceCount][1] = b;
        allianceCount++;
        logTreaty(a + " formed alliance with " + b);
    }
}

void MultiplayerEngine::breakAlliance(const string& a, const string& b) {
    for (int i = 0; i < allianceCount; ++i) {
        if ((alliances[i][0] == a && alliances[i][1] == b) ||
            (alliances[i][0] == b && alliances[i][1] == a)) {
            alliances[i][0] = "";
            alliances[i][1] = "";
            logTreaty(a + " broke alliance with " + b);
            break;
        }
    }
}

bool MultiplayerEngine::isAllied(const string& a, const string& b) {
    for (int i = 0; i < allianceCount; ++i) {
        if ((alliances[i][0] == a && alliances[i][1] == b) ||
            (alliances[i][0] == b && alliances[i][1] == a)) {
            return true;
        }
    }
    return false;
}

void MultiplayerEngine::tradeWithPlayer(const string& from, const string& to, const string& resource, int amount, bool smuggle) {
    ofstream market("market.txt", ios::app);
    if (smuggle && rand() % 5 == 0) {
        market << from << " tried to smuggle " << amount << " " << resource << " to " << to << " and got caught!\n";
    }
    else {
        market << from << " traded " << amount << " " << resource << " with " << to << (smuggle ? " (Smuggling)\n" : "\n");
    }
    market.close();
}

void MultiplayerEngine::attackKingdom(const string& attacker, const string& defender, int atkPower, int defPower, int& atkGold, int& defGold, int& atkFood) {
    ofstream battle("battle_log.txt", ios::app);
    if (isAllied(attacker, defender)) {
        atkFood -= 10;
        battle << attacker << " betrayed ally " << defender << " and lost 10 food.\n";
    }

    if (atkPower > defPower) {
        atkGold += 10;
        defGold = (defGold >= 10 ? defGold - 10 : 0);
        battle << attacker << " won battle against " << defender << ".\n";
    }
    else {
        atkFood = (atkFood >= 5 ? atkFood - 5 : 0);
        battle << attacker << " lost battle to " << defender << ".\n";
    }
    battle.close();
}

void MultiplayerEngine::moveKingdom(const string& player, int dx, int dy) {
    int i = getPlayerIndex(player);
    if (i == -1) return;
    int newX = max(0, min(MAP_SIZE - 1, posX[i] + dx));
    int newY = max(0, min(MAP_SIZE - 1, posY[i] + dy));
    mapGrid[posX[i]][posY[i]] = "";
    mapGrid[newX][newY] = player;
    posX[i] = newX;
    posY[i] = newY;
}

void MultiplayerEngine::showMap() {
    cout << "\n--- Map View ---\n";
    for (int y = 0; y < MAP_SIZE; ++y) {
        for (int x = 0; x < MAP_SIZE; ++x) {
            if (!mapGrid[x][y].empty())
                cout << "[" << mapGrid[x][y][0] << "] ";
            else
                cout << "[ ] ";
        }
        cout << endl;
    }
}

void MultiplayerEngine::showAlliances() {
    cout << "\n--- Alliances ---\n";
    if (allianceCount == 0) {
        cout << "No alliances formed yet.\n";
        return;
    }
    for (int i = 0; i < allianceCount; ++i) {
        if (!alliances[i][0].empty()) {
            cout << alliances[i][0] << " <-> " << alliances[i][1] << endl;
        }
    }
}

void MultiplayerEngine::logTreaty(const string& msg) {
    ofstream treaty("treaty.txt", ios::app);
    treaty << msg << endl;
    treaty.close();
}

int MultiplayerEngine::getPlayerIndex(const string& name) {
    for (int i = 0; i < playerCount; ++i) {
        if (players[i] == name) return i;
    }
    return -1;
}