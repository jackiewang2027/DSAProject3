#ifndef SORT_VISUALIZATION_SCREEN_H
#define SORT_VISUALIZATION_SCREEN_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "star.h"

class SortScreen {
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
    SortScreen(sf::RenderWindow& win) : window(win) {
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

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (backButton.getGlobalBounds().contains(mousePos)) {
                    shouldReturnToSelectScreen = true;
                    std::cout << "Back button clicked" << std::endl;

                }
            }
        }
    }


    void draw() {
        window.clear(backgroundColor);
        window.draw(headerText);
        window.draw(detailsText);
        window.draw(backButton);
        window.draw(backButtonText);
        cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        window.draw(cursorSprite);  // Add this line to draw the cursor sprite
        window.display();
    }
    bool shouldReturnToSelectScreen = false;

};

#endif // SORT_VISUALIZATION_SCREEN_H