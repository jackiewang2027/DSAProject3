#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "interface_objects.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Star Jump Visualizer");

    // Load fonts
    sf::Font font, secondaryFont;
    if (!font.loadFromFile("Carrots.otf") || !secondaryFont.loadFromFile("Stars.ttf")) {
        return -1; // Exit if fonts are not loaded successfully
    }

    // Initialize text objects
    sf::Text welcometothe, starjump;
    setupWelcomeText(welcometothe, secondaryFont);
    setupStarJumpText(starjump, font);

    // Load and play background music
    sf::Music music;
    if (!music.openFromFile("background.ogg")) {
        return -1;
    }
    music.setLoop(true);
    music.play();

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the screen with a light color
        window.clear(sf::Color(138, 127, 141));

        // Draw text
        drawText(window, welcometothe);
        drawText(window, starjump);

        // Update the window
        window.display();
    }

    return 0;
}
