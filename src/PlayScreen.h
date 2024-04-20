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
    sf::Text sortOption1, sortOption2;  // For sorting algorithms
    sf::Text attributeOption1, attributeOption2, attributeOption3, attributeOption4, attributeOption5;  // For attributes

public:
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
        title.setString("Pick a Sort Type and Star Attribute");
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

        // Initialize sorting algorithm options
        sortOption1.setFont(font);
        sortOption1.setString("Shell Sort");
        sortOption1.setCharacterSize(30);
        sortOption1.setFillColor(sf::Color::White);
        sortOption1.setPosition(100, 150);

        sortOption2.setFont(font);
        sortOption2.setString("Merge Sort");
        sortOption2.setCharacterSize(30);
        sortOption2.setFillColor(sf::Color::White);
        sortOption2.setPosition(100, 200);

        // Initialize attribute options
        attributeOption1.setFont(font);
        attributeOption1.setString("Distance");
        attributeOption1.setCharacterSize(30);
        attributeOption1.setFillColor(sf::Color::White);
        attributeOption1.setPosition(400, 150);

        attributeOption2.setFont(font);
        attributeOption2.setString("Radial Velocity");
        attributeOption2.setCharacterSize(30);
        attributeOption2.setFillColor(sf::Color::White);
        attributeOption2.setPosition(400, 200);

        attributeOption3.setFont(font);
        attributeOption3.setString("Luminosity");
        attributeOption3.setCharacterSize(30);
        attributeOption3.setFillColor(sf::Color::White);
        attributeOption3.setPosition(400, 250);

        attributeOption4.setFont(font);
        attributeOption4.setString("Color Index");
        attributeOption4.setCharacterSize(30);
        attributeOption4.setFillColor(sf::Color::White);
        attributeOption4.setPosition(400, 300);

        attributeOption5.setFont(font);
        attributeOption5.setString("Visual Magnitude");
        attributeOption5.setCharacterSize(30);
        attributeOption5.setFillColor(sf::Color::White);
        attributeOption5.setPosition(400, 350);
    }

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (backButton.getGlobalBounds().contains(mousePos)) {
                    std::cout << "Back button clicked!" << std::endl;
                    shouldReturnToWelcome = true;
                }
                // Handling sorting option clicks
                if (sortOption1.getGlobalBounds().contains(mousePos)) {
                    std::cout << "Shell Sort selected" << std::endl;
                    // Implement action for selecting Shell Sort
                }
                if (sortOption2.getGlobalBounds().contains(mousePos)) {
                    std::cout << "Merge Sort selected" << std::endl;
                    // Implement action for selecting Merge Sort
                }
                // Handling attribute option clicks
                if (attributeOption1.getGlobalBounds().contains(mousePos)) {
                    std::cout << "Distance attribute selected" << std::endl;
                    // Implement action for selecting Distance attribute
                }
                if (attributeOption2.getGlobalBounds().contains(mousePos)) {
                    std::cout << "Radial Velocity attribute selected" << std::endl;
                    // Implement action for selecting Radial Velocity attribute
                }
                if (attributeOption3.getGlobalBounds().contains(mousePos)) {
                    std::cout << "Luminosity attribute selected" << std::endl;
                    // Implement action for selecting Luminosity attribute
                }
                if (attributeOption4.getGlobalBounds().contains(mousePos)) {
                    std::cout << "Color Index attribute selected" << std::endl;
                    // Implement action for selecting Color Index attribute
                }
                if (attributeOption5.getGlobalBounds().contains(mousePos)) {
                    std::cout << "Visual Magnitude attribute selected" << std::endl;
                    // Implement action for selecting Visual Magnitude attribute
                }
            }
        }
    }

    void draw() {
        window.clear(backgroundColor);
        cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        window.draw(title);
        window.draw(backButtonText);
        window.draw(sortOption1);
        window.draw(sortOption2);
        window.draw(attributeOption1);
        window.draw(attributeOption2);
        window.draw(attributeOption3);
        window.draw(attributeOption4);
        window.draw(attributeOption5);
        window.draw(cursorSprite);  // Ensure cursor is drawn last to be on top
        window.display();
    }

    bool shouldReturnToWelcome = false;
};

#endif // PLAY_SCREEN_H
