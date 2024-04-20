//colors
//https://www.color-hex.com/color-palette/3339


//Luma sound effect
//https://www.youtube.com/watch?v=6_ezvKQSTTg

//Soundtrack (Super Mario Galaxy OST: File Select)
//https://www.youtube.com/watch?v=XwM0lPS07Oc
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

#ifndef CMAKESFMLPROJECT_INTERFACE_OBJECTS_H
#define CMAKESFMLPROJECT_INTERFACE_OBJECTS_H



void setupWelcomeText(sf::Text& text, sf::Font& font);
void setupStarJumpText(sf::Text& text, sf::Font& font);
void drawText(sf::RenderWindow& window, sf::Text& text);
void setupPlayButton(sf::Text& text, sf::RectangleShape& button, sf::Font& font);
void drawButton(sf::RenderWindow& window, sf::Text& text, sf::RectangleShape& button);


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

bool initializeResources(sf::Font& font, sf::Font& secondaryFont, sf::Texture& cursorTexture, sf::SoundBuffer& buffer, sf::Music& music) {
    bool success = true;

    // Load fonts
    if (!font.loadFromFile("Fonts/Carrots.otf")) {
        std::cerr << "Failed to load font Carrots.otf" << std::endl;
        success = false;
    }
    if (!secondaryFont.loadFromFile("Fonts/Stars.ttf")) {
        std::cerr << "Failed to load font Stars.ttf" << std::endl;
        success = false;
    }

    // Load cursor texture
    if (!cursorTexture.loadFromFile("luma2.png")) {
        std::cerr << "Failed to load cursor image luma2.png" << std::endl;
        success = false;
    }

    // Load sound effects
    if (!buffer.loadFromFile("Music/Luma Sound Effect.wav")) {
        std::cerr << "Failed to load sound effect Luma Sound Effect.wav" << std::endl;
        success = false;
    }

    // Load background music
    if (!music.openFromFile("Music/background.ogg")) {
        std::cerr << "Failed to open background music file" << std::endl;
        success = false;
    }

    return success;
}

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

