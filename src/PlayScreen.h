#ifndef PLAY_SCREEN_H
#define PLAY_SCREEN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "WelcomeScreen.h"

class PlayScreen {
private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text title;
    sf::Text backButtonText;
    sf::RectangleShape backButton;
    sf::Color backgroundColor;
    sf::Texture cursorTexture;
    sf::Sprite cursorSprite;

public:
    PlayScreen(sf::RenderWindow& win) : window(win) {
        if (!initializeResources()) {
            throw std::runtime_error("Failed to initialize resources for PlayScreen");
        }
        setupScene();
    }

    bool initializeResources() {
        bool success = true;
        // Inside PlayScreen's initializeResources method
        if (!cursorTexture.loadFromFile("Images/luma3.png")) {
            std::cerr << "Failed to load cursor image luma3.png" << std::endl;
            success = false;
        }
        cursorSprite.setTexture(cursorTexture);
        cursorSprite.setOrigin(cursorTexture.getSize().x / 2, cursorTexture.getSize().y / 2);


        if (!font.loadFromFile("Fonts/Carrots.otf")) {
            std::cerr << "Failed to load font Carrots.otf for PlayScreen" << std::endl;
            success = false;
        }

        backgroundColor = sf::Color(138, 127, 141); // Use the same initial background color as WelcomeScreen
        return success;
    }

    void setupScene() {
        title.setFont(font);
        title.setString("Game Play");
        title.setCharacterSize(46);
        title.setFillColor(sf::Color::White);
        title.setStyle(sf::Text::Bold);
        sf::FloatRect textRect = title.getLocalBounds();
        title.setOrigin(textRect.width / 2, textRect.height / 2);
        title.setPosition(400, 100);

        backButtonText.setFont(font);
        backButtonText.setString("< Back");
        backButtonText.setCharacterSize(24);
        backButtonText.setFillColor(sf::Color::White);
        sf::FloatRect backButtonRect = backButtonText.getLocalBounds();
        backButtonText.setOrigin(backButtonRect.left, backButtonRect.top);
        backButtonText.setPosition(10, 10);

        backButton.setSize(sf::Vector2f(backButtonRect.width + 20, backButtonRect.height + 20));
        backButton.setPosition(10, 10);
        backButton.setFillColor(sf::Color::Transparent);
    }
    bool shouldReturnToWelcome = false;
    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (backButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                        // Signal to go back to the welcome screen
                        std::cout << "Back button clicked!" << std::endl;
                        shouldReturnToWelcome = true; // Set the flag to return to the welcome screen

                    }
                }
            }
        }
    }

// In PlayScreen's draw method
    void draw() {
        window.clear(backgroundColor);
        cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))); // Update cursor position
        window.draw(title);
        window.draw(backButtonText);
        window.draw(cursorSprite);  // Ensure cursor is drawn last to be on top
        window.display();
    }


};

#endif // PLAY_SCREEN_H
