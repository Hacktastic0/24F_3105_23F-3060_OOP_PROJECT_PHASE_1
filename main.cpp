#include "game.h"
#include "multiplayer.h"
#include <iomanip>  // for alignment
#include <cstdlib>  // for system("cls") or "clear"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

// ANSI escape codes for colors
#define RESET_COLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define LIGHT_GRAY "\033[37;1m"

// Platform-specific clear screen function
void clearScreen() {
#ifdef _WIN32
    system("cls");  // Windows
#else
    system("clear");  // Linux/macOS
#endif
}

// Platform-specific console window maximization
void maximizeWindow() {
#ifdef _WIN32
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);  // Maximize the console window to full screen
#else
    // Linux/macOS: This will set the terminal window size to 120 columns by 40 rows
    printf("\033[8;40;120t");
#endif
}

void printHeader(const string& header) {
    cout << endl;
    cout << CYAN << std::setw(170) << std::setfill('=') << "=" << RESET_COLOR << endl;
    cout << endl;
    cout << CYAN << std::setw(90) << std::setfill(' ') << header << RESET_COLOR << endl;
    cout << endl;
    cout << CYAN << std::setw(170) << std::setfill('=') << "=" << RESET_COLOR << endl;
  
}

void printGameTitle() {
    // Display the game title with a banner
    cout << MAGENTA << std::setw(170) << std::setfill('=') << "=" << RESET_COLOR << endl;
    cout << endl;

    // STRONGHOLD banner (aligned to look like letters)
    cout << MAGENTA << std::setw(120) << std::setfill(' ') << "  SSSS  TTTTT  RRRR    OOO   N   N   GGGG   H   H   OOO   L       DDDD " << RESET_COLOR << endl;
    cout << MAGENTA << std::setw(120) << std::setfill(' ') << " S       T    R   R  O   O  NN  N  G       H   H  O   O  L       D   D" << RESET_COLOR << endl;
    cout << MAGENTA << std::setw(120) << std::setfill(' ') << "  SSS    T    RRRR   O   O  N N N  G  GG   HHHHH  O   O  L       D   D" << RESET_COLOR << endl;
    cout << MAGENTA << std::setw(120) << std::setfill(' ') << "     S   T    R  R   O   O  N  NN  G   G   H   H  O   O  L       D   D" << RESET_COLOR << endl;
    cout << MAGENTA << std::setw(120) << std::setfill(' ') << " SSSS    T    R   R   OOO   N   N   GGGG   H   H   OOO   LLLLL   DDDD " << RESET_COLOR << endl;
}


int main() {
    srand((unsigned int)time(0));

    // Maximize console window
    maximizeWindow();

    string playerNames[2] = { "Rabia", "Aima" };
    Kingdom k1(playerNames[0]), k2(playerNames[1]);
    MultiplayerEngine engine(playerNames, 2);

    int choice;
    bool endGame = false;
    int turn = 0;

    printGameTitle();  // Print the game title at the start

    while (!endGame) {
        clearScreen();  // Clear screen at the start of each turn
        printGameTitle();  // Print the Stronghold title every time a new turn begins
        Kingdom& current = (turn % 2 == 0) ? k1 : k2;
        printHeader(current.name + "'s Turn");

        // Display build menu with colorful options
        current.buildMenu();
        cout << YELLOW << "                                    12. Diplomacy/Warfare" << RESET_COLOR << endl;
        cout << BLUE << "    Enter choice: " << RESET_COLOR;
        cin >> choice;

        switch (choice) {
        case 1: current.buildBarracks(); break;
        case 2: current.trade(); break;
        case 3: current.buildFarm(); break;
        case 4: current.buildHouse(); break;
        case 5: current.buildMine(); break;
        case 6: current.buildWoodcutter(); break;
        case 7: current.buildWorkshop(); break;
        case 8: current.trainSoldiers(); break;
        case 9: current.status(); break;
        case 10: current.saveGame(); break;
        case 11: current.loadGame(); break;

        case 12: {
            cout << GREEN
                << "1. Send a Message         2. Form a Strategic Alliance\n"
                << "3. Dissolve an Alliance    4. Launch an Attack\n"
                << "5. Command Movement        6. View the Battlefield Map\n"
                << "7. Display Alliances\n"
                << RESET_COLOR << endl;

            int action; cin >> action;
            string target;
            switch (action) {
            case 1: {
                cout << BLUE << "Send message to: " << RESET_COLOR; cin >> target;
                engine.sendMessage(current.name, target);
                break;
            }
            case 2: {
                cout << BLUE << "Form alliance with: " << RESET_COLOR; cin >> target;
                engine.formAlliance(current.name, target);
                break;
            }
            case 3: {
                cout << BLUE << "Break alliance with: " << RESET_COLOR; cin >> target;
                engine.breakAlliance(current.name, target);
                break;
            }
            case 4: {
                cout << BLUE << "Attack whom? " << RESET_COLOR; cin >> target;
                int atk = current.archers + current.swordsmen + current.macemen;
                int def = (target == k1.name) ? (k1.archers + k1.swordsmen + k1.macemen) : (k2.archers + k2.swordsmen + k2.macemen);
                if (target == k1.name)
                    engine.attackKingdom(current.name, target, atk, def, current.gold, k1.gold, current.food);
                else
                    engine.attackKingdom(current.name, target, atk, def, current.gold, k2.gold, current.food);
                break;
            }
            case 5: {
                cout << BLUE << "Move X and Y direction (dx dy): " << RESET_COLOR;
                int dx, dy; cin >> dx >> dy;
                engine.moveKingdom(current.name, dx, dy);
                break;
            }
            case 6: {
                engine.showMap();
                break;
            }
            case 7: {
                engine.showAlliances();
                break;
            }
            default:
                cout << RED << "Invalid diplomacy option." << RESET_COLOR << endl;
                break;
            }
            break;
        }

        default:
            cout << RED << "Invalid option." << RESET_COLOR << endl;
            break;
        }

        turn++;
        cout << "\nContinue playing? (1 = Yes, 0 = No): ";
        cin >> endGame;
        endGame = !endGame;
    }

    clearScreen();  // Clear screen at the end of the game
    cout << GREEN << "Game over. Saving progress..." << RESET_COLOR << endl;
    k1.saveGame();
    k2.saveGame();
    return 0;
}