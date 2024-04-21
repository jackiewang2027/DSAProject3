#ifndef SORT_VISUALIZATION_SCREEN_H
#define SORT_VISUALIZATION_SCREEN_H

#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "star.h"
#include "SelectScreen.h"
#include <chrono>
#include <iomanip>
#include <cmath>

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
    std::vector<star> shellSortedStars;
    std::vector<star> mergeSortedStars;
    std::string selectedAttributeString;
    double shellSortTime, mergeSortTime;
public:
    std::string getSelectedAttribute() const {
        return selectedAttributeString;
    }

    bool shouldReturnToSelectScreen = false;

    bool initializeResources() {
        bool success = true;
        if (!cursorTexture.loadFromFile("Images/luma3.png")) {
            std::cerr << "Failed to load cursor image luma3.png" << std::endl;
            success = false;
        }
        cursorSprite.setTexture(cursorTexture);
        cursorSprite.setOrigin(cursorTexture.getSize().x / 2, cursorTexture.getSize().y / 2);

            if (!font.loadFromFile("Fonts/CuteDino.ttf")) {
            std::cerr << "Failed to load font CuteDino.ttf for PlayScreen" << std::endl;
            success = false;
        }

        backgroundColor = sf::Color(138, 127, 141); // Use the same initial background color as WelcomeScreen
        return success;
    }
    SortScreen(sf::RenderWindow& win) : window(win) {
        if (!initializeResources()) {
            throw std::runtime_error("Failed to initialize resources for PlayScreen");
        }

    }

    void setAttribute(const std::string& attribute) {
        this->selectedAttributeString = attribute; // Store the attribute
        setupScene();  // You might want to call setupScene here to use the new attribute
    }




    void setupScene() {
        star s;
        std::vector<star> stars = s.readStarFile();
        std::string lowStarMessage;
        std::string highStarMessage;
        std::string shellMessage;
        std::string mergeMessage;
        shellSortedStars.resize(5000);
        mergeSortedStars.resize(5000);
        for(int i = 0; i < 5000; i++) {
            shellSortedStars[i] = stars[i];
            mergeSortedStars[i] = stars[i];
        }
        if(selectedAttributeString == "Distance" || selectedAttributeString == "distance"){
            // Perform and track time for shell sort
            auto shellStartTime = std::chrono::steady_clock::now();;
            shellSortedStars = s.shellSort(shellSortedStars, "dist");
            auto shellEndTime = std::chrono::steady_clock::now();
            auto timeToDoShell = shellEndTime - shellStartTime;
            double timeToDoShellSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoShell).count();
            double roundedShell = std::round(timeToDoShellSecs * 100) / 100.0;
            std::stringstream shellStream;
            shellStream << std::fixed << std::setprecision(2) << roundedShell;
            std::string shellString = shellStream.str();

            // Perform and track time for merge sort
            auto mergeStartTime = std::chrono::steady_clock::now();
            mergeSortedStars = s.mergeSort(mergeSortedStars,"dist");
            auto mergeEndTime = std::chrono::steady_clock::now();
            auto timeToDoMerge = mergeEndTime - mergeStartTime;
            double timeToDoMergeSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoMerge).count();
            double roundedMerge = std::round(timeToDoMergeSecs * 100);
            std::stringstream mergeStream;
            mergeStream << std::fixed << std::setprecision(2) << roundedMerge;
            std::string mergeString = mergeStream.str();

            // Gets the star with the lowest distance and also has a common name

            for(int i = 0; i < shellSortedStars.size(); i++){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::string lowName = shellSortedStars[i].getAttribute("commonName");
                    std::string lowDist = shellSortedStars[i].getAttribute("dist");
                    lowStarMessage = "Star " + lowName + " has the lowest distance of " + lowDist;
                    break;
                }
            }

            // Gets the star with the highest distance and also has a common name
            for(int i = 4999; i >= 0; i--){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::string highName = shellSortedStars[i].getAttribute("commonName");
                    std::string highDist = shellSortedStars[i].getAttribute("dist");
                    highStarMessage = "Star " + highName + " has the highest distance of " + highDist;
                    break;
                }
            }

            // Output time
            std::cout << lowStarMessage << std::endl;
            std::cout << highStarMessage << std::endl;
            std::cout << "" << std::endl;
            shellMessage = "Time to perform shell sort was " + shellString + " seconds.";
            std::cout << shellMessage << std::endl;
            mergeMessage = "Time to perform merge sort was " + mergeString + " seconds.";
            std::cout << mergeMessage << std::endl;
        }

        headerText.setFont(font);
        headerText.setString("Sorting Results: " + selectedAttributeString);
        headerText.setCharacterSize(30);
        headerText.setFillColor(sf::Color::White);
        headerText.setPosition(50, 50);

        detailsText.setFont(font);
        detailsText.setString(
                lowStarMessage + "\n" +
                highStarMessage + + "\n" +
                shellMessage + + "\n" +
                mergeMessage);
        detailsText.setCharacterSize(24);
        detailsText.setFillColor(sf::Color::White);
        detailsText.setPosition(50, 100);
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

};

#endif // SORT_VISUALIZATION_SCREEN_H