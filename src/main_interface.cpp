#include "WelcomeScreen.h"
#include "PlayScreen.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Star Jump Visualizer");
    window.setMouseCursorVisible(false);

    WelcomeScreen welcomeScreen(window);
    PlayScreen playScreen(window);

    bool onWelcomeScreen = true;

    while (window.isOpen()) {
        if (onWelcomeScreen) {
            welcomeScreen.handleEvents();
            welcomeScreen.draw();
            if (welcomeScreen.shouldStartGame) {
                onWelcomeScreen = false;
                welcomeScreen.shouldStartGame = false; // Reset the flag
            }
        } else {
            playScreen.handleEvents();
            playScreen.draw();
            if (playScreen.shouldReturnToWelcome) {
                onWelcomeScreen = true;
                playScreen.shouldReturnToWelcome = false; // Reset the flag
            }
        }
    }

    return 0;
}
