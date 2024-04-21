#include "WelcomeScreen.h"
#include "SelectScreen.h"
#include "SortScreen.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Star Sort Visualizer");
    window.setMouseCursorVisible(false);

    WelcomeScreen welcomeScreen(window);
    SelectScreen SelectScreen(window);
    SortScreen SortScreen(window);

    bool onWelcomeScreen = true;
    bool onSelectScreen = false;
    bool onSortScreen = false;

    while (window.isOpen()) {
        if (onWelcomeScreen) {
            welcomeScreen.handleEvents();
            welcomeScreen.draw();
            if (welcomeScreen.shouldStartGame) {
                onWelcomeScreen = false;
                onSelectScreen = true;
                welcomeScreen.shouldStartGame = false;  // Reset the flag
            }
        }

        // Handle events and drawing for the Play Screen
        if (onSelectScreen) {
            SelectScreen.handleEvents();
            SelectScreen.draw();
            if (SelectScreen.shouldReturnToWelcome) {
                onSelectScreen = false;
                onWelcomeScreen = true;
                SelectScreen.shouldReturnToWelcome = false;  // Reset the flag here to prevent flickering
            }

            if (SelectScreen.shouldStartPlaying) {
                onSortScreen = true;
            }

        }
        if (onSortScreen) {
            SortScreen.handleEvents();
            SortScreen.draw();
        }
    }

    return 0;
}
