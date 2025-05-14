// kingdom.cpp
#include "game.h"

Kingdom::Kingdom(string playerName) {
    name = playerName;
    gold = 100; wood = 100; food = 100;
    houses = 1; population = 5;
    swords = bows = maces = 0;
    fruitFarms = grainFarms = 0;
    woodcutters = workshops = 0;
    goldMines = ironMines = 0;
    barracks = archers = swordsmen = macemen = 0;
}

int Kingdom::randomBetween(int low, int high) {
    return rand() % (high - low + 1) + low;
}

void Kingdom::log(string message) {
    ofstream logFile("score.txt", ios::app);
    logFile << name << ": " << message << endl;
    logFile.close();
}

void Kingdom::buildMenu() {
    cout << "                     \n    What action would you like to take, " << name << "?\n";
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "                                    1. Construct Barracks                                              2. Trade at Market\n";
    cout << "                                    3. Establish Farm                                                  4. Construct House\n";
    cout << "                                    5. Establish Mine                                                  6. Add Woodcutter\n";
    cout << "                                    7. Set up Workshop                                                 8. Train Warriors\n";
    cout << "                                    9. Display Status                                                  10. Save Progress\n";
    cout << "                                    11. Load Saved Game \n"    ;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}


void Kingdom::buildBarracks() {
    if (wood >= 20) {
        wood -= 20; barracks++;
        cout << "Barracks built!\n";
        log("Built Barracks.");
    }
    else cout << "Not enough wood.\n";
}

void Kingdom::buildFarm() {
    cout << "Choose farm type:\n1. Fruit Farm\n2. Grain Farm\n> ";
    int type; cin >> type;
    if (type == 1) { fruitFarms++; log("Built Fruit Farm."); }
    else { grainFarms++; log("Built Grain Farm."); }
    int gain = randomBetween(3, 5); food += gain;
    cout << "Gained " << gain << " food.\n";
    log("Farm produced " + to_string(gain) + " food.");
}

void Kingdom::buildHouse() {
    houses++; population = houses * 5;
    cout << "House built. Population now " << population << ".\n";
    log("Built House.");
}

void Kingdom::buildMine() {
    cout << "Choose mine type:\n1. Gold\n2. Iron\n> "; int type; cin >> type;
    if (type == 1) {
        goldMines++;
        int gain = randomBetween(5, 10);
        gold += gain;
        cout << "Gained " << gain << " gold.\n";
        log("Gold Mine built. Added " + to_string(gain) + " gold.");
    }
    else {
        ironMines++;
        cout << "Iron Mine built.\n";
        log("Iron Mine built.");
    }
}

void Kingdom::buildWoodcutter() {
    woodcutters++;
    int gain = randomBetween(5, 10);
    wood += gain;
    cout << "Gained " << gain << " wood.\n";
    log("Woodcutter added. Gained " + to_string(gain) + " wood.");
}

void Kingdom::buildWorkshop() {
    cout << "Choose weapon:\n1. Bow\n2. Sword\n3. Mace\n> ";
    int type; cin >> type;
    workshops++;
    if (type == 1) { bows++; log("Bow created."); }
    else if (type == 2) { swords++; log("Sword created."); }
    else { maces++; log("Mace created."); }
    cout << "Weapon created.\n";
}

void Kingdom::trainSoldiers() {
    if (barracks == 0) { cout << "No barracks.\n"; return; }
    cout << "Train:\n1. Archer\n2. Swordsman\n3. Maceman\n> ";
    int type; cin >> type;
    if (type == 1 && bows > 0 && gold >= 5) { bows--; gold -= 5; archers++; log("Trained Archer."); }
    else if (type == 2 && swords > 0 && gold >= 5) { swords--; gold -= 5; swordsmen++; log("Trained Swordsman."); }
    else if (type == 3 && maces > 0 && gold >= 5) { maces--; gold -= 5; macemen++; log("Trained Maceman."); }
    else cout << "Not enough resources.\n";
}

void Kingdom::trade() {
    cout << "Trade:\n1. Food (3g)\n2. Wood (2g)\n> ";
    int type, amt; cin >> type;
    cout << "Amount: "; cin >> amt;
    cout << "Trade legally? (1=Yes, 0=No - riskier but more profit): ";
    bool legal; cin >> legal;

    if (type == 1 && amt <= food) {
        food -= amt;
        gold += amt * (legal ? 3 : 5);
        log("Traded food " + string(legal ? "legally" : "illegally"));
    }
    else if (type == 2 && amt <= wood) {
        wood -= amt;
        gold += amt * (legal ? 2 : 4);
        log("Traded wood " + string(legal ? "legally" : "illegally"));
    }
    else cout << "Not enough resources.\n";
}

void Kingdom::status() {
    cout << "\n--- " << name << " Status ---\n";
    cout << "Gold: " << gold << ", Wood: " << wood << ", Food: " << food << endl;
    cout << "Population: " << population << ", Houses: " << houses << endl;
    cout << "Weapons - Swords: " << swords << ", Bows: " << bows << ", Maces: " << maces << endl;
    cout << "Farms - Fruit: " << fruitFarms << ", Grain: " << grainFarms << endl;
    cout << "Mines - Gold: " << goldMines << ", Iron: " << ironMines << endl;
    cout << "Barracks: " << barracks << ", Workshops: " << workshops << ", Woodcutters: " << woodcutters << endl;
    cout << "Soldiers - Archers: " << archers << ", Swordsmen: " << swordsmen << ", Macemen: " << macemen << endl;
}

void Kingdom::saveGame() {
    ofstream out(name + "_save.txt");
    out << gold << " " << wood << " " << food << " " << houses << " " << population << " "
        << swords << " " << bows << " " << maces << " " << fruitFarms << " " << grainFarms << " "
        << woodcutters << " " << workshops << " " << goldMines << " " << ironMines << " "
        << barracks << " " << archers << " " << swordsmen << " " << macemen << endl;
    out.close();
    log("Game saved.");
}

void Kingdom::loadGame() {
    ifstream in(name + "_save.txt");
    if (!in) { cout << "Save file not found.\n"; return; }
    in >> gold >> wood >> food >> houses >> population >> swords >> bows >> maces
        >> fruitFarms >> grainFarms >> woodcutters >> workshops >> goldMines >> ironMines
        >> barracks >> archers >> swordsmen >> macemen;
    in.close();
    log("Game loaded.");
}

void Kingdom::showTradeRecords() {
    ifstream in("market.txt");
    if (!in) { cout << "No trade records found.\n"; return; }
    cout << "\n--- Trade Records ---\n";
    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();
}