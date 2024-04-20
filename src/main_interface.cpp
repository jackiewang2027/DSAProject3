#include "WelcomeScreen.h"
#include "PlayScreen.h"
#include "SortVisualizationScreen.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Star Jump Visualizer");
    window.setMouseCursorVisible(false);

    WelcomeScreen welcomeScreen(window);
    PlayScreen playScreen(window);
    SortVisualizationScreen sortVisualizationScreen(window);  // Assuming this screen is properly implemented

    bool onWelcomeScreen = true;
    bool onPlayScreen = false;
    bool onSortVisualizationScreen = false;

    while (window.isOpen()) {
        // Handle events and drawing for the Welcome Screen
        if (onWelcomeScreen) {
            welcomeScreen.handleEvents();
            welcomeScreen.draw();
            if (welcomeScreen.shouldStartGame) {
                onWelcomeScreen = false;
                onPlayScreen = true;  // Transition to PlayScreen
            }
        }

        // Handle events and drawing for the Play Screen
        if (onPlayScreen) {
            playScreen.handleEvents();
            playScreen.draw();
            if (playScreen.shouldReturnToWelcome) {
                onPlayScreen = false;
                onWelcomeScreen = true;  // Transition back to WelcomeScreen
            }
            if (playScreen.isReadyForSortVisualization()) {
                onPlayScreen = false;
                onSortVisualizationScreen = true;  // Transition to SortVisualizationScreen
                playScreen.resetSortVisualizationFlag();  // Reset the transition flag
                // Assume method exists to initialize sort visualization with required data
                sortVisualizationScreen.initializeWithAttribute(playScreen.getSelectedAttribute());
            }
        }

        // Handle events and drawing for the Sort Visualization Screen
        if (onSortVisualizationScreen) {
            sortVisualizationScreen.handleEvents();
            sortVisualizationScreen.draw();
            if (sortVisualizationScreen.shouldReturnToPlayScreen()) {
                onSortVisualizationScreen = false;
                onPlayScreen = true;  // Transition back to PlayScreen
                sortVisualizationScreen.resetReturnFlag();  // Reset the return flag
            }
        }
    }

    return 0;
}
