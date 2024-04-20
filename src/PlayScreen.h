#ifndef PLAY_SCREEN_H
#define PLAY_SCREEN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "WelcomeScreen.h"

class PlayScreen {
private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text title, backButtonText, attributeOption1, attributeOption2, attributeOption3, attributeOption4, attributeOption5, confirmButtonText;
    sf::RectangleShape backButton, confirmButton;
    sf::Color backgroundColor;
    sf::Texture cursorTexture;
    sf::Sprite cursorSprite;
    int selectedAttribute = -1;  // -1 means none selected

public:
    bool shouldTransitionToSortVisualization = false;
    // Method to be called from the main application to check if it should transition
    bool isReadyForSortVisualization() const {
        return shouldTransitionToSortVisualization;
    }

    // Method to reset transition flag
    void resetSortVisualizationFlag() {
        shouldTransitionToSortVisualization = false;
    }
    PlayScreen(sf::RenderWindow& win) : window(win) {
        if (!initializeResources()) {
            throw std::runtime_error("Failed to initialize resources for PlayScreen");
        }
        setupScene();
    }

    bool initializeResources() {
        bool success = true;
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
        title.setString("Pick a Star Attribute");
        title.setCharacterSize(36);
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

        // Initialize attribute options
        attributeOption1.setFont(font);
        attributeOption1.setString("Distance");
        attributeOption1.setCharacterSize(30);
        attributeOption1.setFillColor(sf::Color::White);
        attributeOption1.setPosition(300, 150);

        attributeOption2.setFont(font);
        attributeOption2.setString("Radial Velocity");
        attributeOption2.setCharacterSize(30);
        attributeOption2.setFillColor(sf::Color::White);
        attributeOption2.setPosition(300, 200);

        attributeOption3.setFont(font);
        attributeOption3.setString("Luminosity");
        attributeOption3.setCharacterSize(30);
        attributeOption3.setFillColor(sf::Color::White);
        attributeOption3.setPosition(300, 250);

        attributeOption4.setFont(font);
        attributeOption4.setString("Color Index");
        attributeOption4.setCharacterSize(30);
        attributeOption4.setFillColor(sf::Color::White);
        attributeOption4.setPosition(300, 300);

        attributeOption5.setFont(font);
        attributeOption5.setString("Visual Magnitude");
        attributeOption5.setCharacterSize(30);
        attributeOption5.setFillColor(sf::Color::White);
        attributeOption5.setPosition(300, 350);

        // Setup Confirm Button
        confirmButton.setSize(sf::Vector2f(200, 50));
        confirmButton.setPosition(300, 450);
        confirmButton.setFillColor(sf::Color::Transparent);
        confirmButtonText.setFont(font);
        confirmButtonText.setString("Confirm");
        confirmButtonText.setCharacterSize(30);
        confirmButtonText.setPosition(340, 455);
        confirmButtonText.setFillColor(sf::Color::Transparent);
    }

    void toggleSelection(const sf::Vector2f& mousePos) {
        // Handling attribute option clicks
        handleAttributeSelection(mousePos);
    }

    void handleAttributeSelection(const sf::Vector2f& mousePos) {
        if (backButton.getGlobalBounds().contains(mousePos)) {
            shouldReturnToWelcome = true;
            std::cout << "Back button clicked" << std::endl;
        }
        if (confirmButton.getGlobalBounds().contains(mousePos)){
            std::cout << "Confirm button clicked" << std::endl;
        }
        sf::Text* attributeOptions[5] = {&attributeOption1, &attributeOption2, &attributeOption3, &attributeOption4, &attributeOption5};
        for (int i = 0; i < 5; i++) {
            if (attributeOptions[i]->getGlobalBounds().contains(mousePos)) {
                if (selectedAttribute != i + 1) {
                    selectedAttribute = i + 1;
                    for (int j = 0; j < 5; j++) {
                        attributeOptions[j]->setFillColor(sf::Color::White);
                    }
                    attributeOptions[i]->setFillColor(sf::Color(204, 210, 253));
                } else {
                    attributeOptions[i]->setFillColor(sf::Color::White);
                    selectedAttribute = -1;
                }
                break;
            }
        }
    }

    void checkConfirmButton() {
        if (selectedAttribute != -1) {
            confirmButtonText.setFillColor(sf::Color::Green);  // Green when active
        } else {
            confirmButtonText.setFillColor(sf::Color::Transparent);  // Not clickable
        }
    }

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                toggleSelection(mousePos);
                checkConfirmButton();
                if (confirmButton.getGlobalBounds().contains(mousePos) && selectedAttribute != -1) {
                    shouldTransitionToSortVisualization = true;
                }
            }
        }
    }

    void draw() {
        window.clear(backgroundColor);
        window.draw(title);
        window.draw(backButtonText);
        window.draw(backButton);
        window.draw(attributeOption1);
        window.draw(attributeOption2);
        window.draw(attributeOption3);
        window.draw(attributeOption4);
        window.draw(attributeOption5);
        window.draw(confirmButton);
        window.draw(confirmButtonText);
        cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        window.draw(cursorSprite);
        window.display();
    }

    bool shouldReturnToWelcome = false;
};

#endif // PLAY_SCREEN_H
