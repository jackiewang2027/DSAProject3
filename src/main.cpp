#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "interface_objects.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Star Jump Visualizer");
    sf::Font font, secondaryFont;
    if (!font.loadFromFile("Carrots.otf") || !secondaryFont.loadFromFile("Stars.ttf")) {
        std::cerr << "Failed to load fonts" << std::endl;
        return -1; // Exit if fonts are not loaded successfully
    }

    sf::Text welcometothe, starjump, playText;
    sf::RectangleShape playButton;
    setupWelcomeText(welcometothe, secondaryFont);
    setupStarJumpText(starjump, font);
    setupPlayButton(playText, playButton, font);

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Luma Sound Effect.wav")) {
        std::cerr << "Failed to load sound effect" << std::endl;
        return -1; // Exit if the sound effect is not loaded successfully
    }
    sf::Music music;
    if (!music.openFromFile("background.ogg")) {
        return -1;
    }
    music.setVolume(8);
    music.setLoop(true);
    music.play();
    sf::Sound clickSound;
    clickSound.setBuffer(buffer);
    clickSound.setVolume(5);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                        clickSound.play();  // Play sound effect when the Play button is clicked
                }
                if (playButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    std::cout << "Play button clicked!" << std::endl;
                }
            }
        }

        window.clear(sf::Color(138, 127, 141));  // Clear screen with light color
        drawText(window, welcometothe);          // Draw "Welcome to the"
        drawText(window, starjump);              // Draw "Star Jump Visualizer"
        drawButton(window, playText, playButton);// Draw the Play button
        window.display();
    }

    return 0;
}
