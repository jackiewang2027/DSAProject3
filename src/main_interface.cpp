#include "WelcomeScreen.h"
#include "SelectScreen.h"
#include "SortScreen.h"

int main() {
    // Setting up the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Star Sort Visualizer");
    window.setMouseCursorVisible(false);

    // Initialize
    WelcomeScreen welcomeScreen(window);
    SelectScreen selectScreen(window);
    SortScreen sortScreen(window);

    // Control flags
    bool onWelcomeScreen = true;
    bool onSelectScreen = false;
    bool onSortScreen = false;

    // For storing user's choice of attribute to sort
    std::string selectedAttribute;


    while (window.isOpen()) {
        if (onWelcomeScreen) {
            welcomeScreen.handleEvents();
            welcomeScreen.draw();
            // Transition to select screen
            if (welcomeScreen.shouldStartGame) {
                onWelcomeScreen = false;
                onSelectScreen = true;
            }
        }
        else if (onSelectScreen) {
            selectScreen.handleEvents();
            selectScreen.draw();
            // Go back to welcome screen
            if (selectScreen.shouldReturnToWelcome) {
                onWelcomeScreen = true;
                onSelectScreen = false;
            }
            // Proceed to sort screen with the selected attribute
            if (selectScreen.shouldStartPlaying) {
                onSortScreen = true;
                onSelectScreen = false;
                selectedAttribute = selectScreen.getSelectedAttribute();
                sortScreen.setAttribute(selectedAttribute);
            }
        }
        //sorting screen
        if (onSortScreen) {
            sortScreen.handleEvents();
            sortScreen.draw();
            //back to selection screen
            if (sortScreen.shouldReturnToSelectScreen) {
                onSelectScreen = true;
                onSortScreen = false;
            }
        }
    }

    return 0;
}
