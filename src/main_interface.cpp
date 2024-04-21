#include "WelcomeScreen.h"
#include "SelectScreen.h"
#include "SortScreen.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Star Sort Visualizer");
    window.setMouseCursorVisible(false);

    WelcomeScreen welcomeScreen(window);
    SelectScreen selectScreen(window);
    SortScreen sortScreen(window);

    bool onWelcomeScreen = true;
    bool onSelectScreen = false;
    bool onSortScreen = false;

    std::string selectedAttribute;  // Variable to store the selected attribute

    while (window.isOpen()) {
        if (onWelcomeScreen) {
            welcomeScreen.handleEvents();
            welcomeScreen.draw();
            if (welcomeScreen.shouldStartGame) {
                onWelcomeScreen = false;
                onSelectScreen = true;
                welcomeScreen.shouldStartGame = false;
            }
        }

        if (onSelectScreen) {
            selectScreen.handleEvents();
            selectScreen.draw();
            if (selectScreen.shouldReturnToWelcome) {
                onSelectScreen = false;
                onWelcomeScreen = true;
                selectScreen.shouldReturnToWelcome = false;
            }

            if (selectScreen.shouldStartPlaying) {
                onSelectScreen = false;
                onWelcomeScreen = false;
                onSortScreen = true;
                selectedAttribute = selectScreen.getSelectedAttribute();  // Retrieve the selected attribute
                sortScreen.setAttribute(selectedAttribute);  // Set the attribute in SortScreen
            }
        }

        if (onSortScreen) {
            sortScreen.handleEvents();
            sortScreen.draw();
            if (sortScreen.shouldReturnToSelectScreen) {
                onSortScreen = false;
                onSelectScreen = true;
                sortScreen.shouldReturnToSelectScreen = false;
            }
        }
    }

    return 0;
}
