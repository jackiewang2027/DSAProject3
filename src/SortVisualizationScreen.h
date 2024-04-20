#ifndef SORT_VISUALIZATION_SCREEN_H
#define SORT_VISUALIZATION_SCREEN_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "star.h"

class SortVisualizationScreen {
private:

    sf::Color backgroundColor;
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text headerText;
    sf::Text detailsText;
    sf::RectangleShape backButton;
    sf::Text backButtonText;
    sf::Texture cursorTexture;
    sf::Sprite cursorSprite;
    std::vector<star> stars;  // This vector will hold the sorted stars data
    std::string attribute;
    float shellSortTime, mergeSortTime;

public:
    bool shouldReturnToPlayScreen = true;

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
    SortVisualizationScreen(sf::RenderWindow& win) : window(win) {
            if (!initializeResources()) {
                throw std::runtime_error("Failed to initialize resources for PlayScreen");
            }
            setupScene();
    }

    void setupScene() {
        // Setup header text
        headerText.setFont(font);
        headerText.setString("Sorting Results: " + attribute);
        headerText.setCharacterSize(30);
        headerText.setFillColor(sf::Color::White);
        headerText.setPosition(50, 50);

        // Setup detailed results text
        std::string details = "Lowest " + attribute + ": " + stars.front().getAttribute(attribute) + "\n" +
                              "Highest " + attribute + ": " + stars.back().getAttribute(attribute) + "\n" +
                              "Shell Sort Time: " + std::to_string(shellSortTime) + " seconds\n" +
                              "Merge Sort Time: " + std::to_string(mergeSortTime) + " seconds";
        detailsText.setFont(font);
        detailsText.setString(details);
        detailsText.setCharacterSize(24);
        detailsText.setFillColor(sf::Color::White);
        detailsText.setPosition(50, 100);

        // Setup back button
        backButton.setSize(sf::Vector2f(100, 50));
        backButton.setFillColor(sf::Color::White);
        backButton.setPosition(50, 300);
        backButtonText.setFont(font);
        backButtonText.setString("Back");
        backButtonText.setCharacterSize(24);
        backButtonText.setFillColor(sf::Color::White);
        backButtonText.setPosition(60, 310);
    }

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (backButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    shouldReturnToPlayScreen = true;
                }
            }
        }
    }

    void draw() {
        window.clear(sf::Color(0, 0, 0));  // Black background for clarity
        window.draw(headerText);
        window.draw(detailsText);
        window.draw(backButton);
        window.draw(backButtonText);
        window.display();
    }
};

#endif // SORT_VISUALIZATION_SCREEN_H
