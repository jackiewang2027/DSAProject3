
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
using namespace std;

#ifndef CMAKESFMLPROJECT_INTERFACE_OBJECTS_H
#define CMAKESFMLPROJECT_INTERFACE_OBJECTS_H

//colors
//https://www.color-hex.com/color-palette/3339


//Luma sound effect
//https://www.youtube.com/watch?v=6_ezvKQSTTg

//Soundtrack (SMG OST: Star Festival)
//https://www.youtube.com/watch?v=XwM0lPS07Oc


void setupWelcomeText(sf::Text& text, sf::Font& font);
void setupStarJumpText(sf::Text& text, sf::Font& font);
void drawText(sf::RenderWindow& window, sf::Text& text);
void setupPlayButton(sf::Text& text, sf::RectangleShape& button, sf::Font& font);
void drawButton(sf::RenderWindow& window, sf::Text& text, sf::RectangleShape& button);

void setupWelcomeText(sf::Text& text, sf::Font& font) {
    text.setFont(font);
    text.setString("Welcome To The");
    text.setCharacterSize(42);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width / 2, textRect.height / 2);
    text.setPosition(400, 240);
}

void setupStarJumpText(sf::Text& text, sf::Font& font) {
    text.setFont(font);
    text.setString("Star Jump Visualizer");
    text.setCharacterSize(46);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width / 2, textRect.height / 2);
    text.setPosition(400, 280);
}

void drawText(sf::RenderWindow& window, sf::Text& text) {
    window.draw(text);
}

void setupPlayButton(sf::Text& text, sf::RectangleShape& button, sf::Font& font) {
    // Setup the button text
    text.setFont(font);
    text.setString("Play");
    text.setCharacterSize(30);  // Smaller size than title text
    text.setFillColor(sf::Color::White);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width / 2, textRect.height / 2);
    text.setPosition(400, 375);  // Positioned under the "Welcome To The"

    // Setup the button rectangle
    button.setSize(sf::Vector2f(textRect.width + 20, textRect.height + 20));
    button.setFillColor(sf::Color(128, 128, 128));  // Grey button
    button.setPosition(400 - button.getSize().x / 2, 360);  // Center the button horizontally
    button.setOutlineColor(sf::Color::White);
    button.setOutlineThickness(2);
}

void drawButton(sf::RenderWindow& window, sf::Text& text, sf::RectangleShape& button) {
    window.draw(button);
    window.draw(text);
}

#endif //CMAKESFMLPROJECT_INTERFACE_OBJECTS_H

