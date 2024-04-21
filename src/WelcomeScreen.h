#ifndef WELCOME_SCREEN_H
#define WELCOME_SCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

//colors
//https://www.color-hex.com/color-palette/3339

//Luma sound effect
//https://www.youtube.com/watch?v=6_ezvKQSTTg

//Soundtrack (Super Mario Galaxy OST: File Select)
//https://www.youtube.com/watch?v=XwM0lPS07Oc
// Helper functions to be included directly in the WelcomeScreen class or as standalone in this file.

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
    text.setString("Star Sort Visualizer");
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
    text.setFont(font);
    text.setString("Play");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width / 2, textRect.height / 2);
    text.setPosition(400, 375);

    button.setSize(sf::Vector2f(textRect.width + 20, textRect.height + 20));
    button.setFillColor(sf::Color(128, 128, 128));
    button.setPosition(400 - button.getSize().x / 2, 360);
    button.setOutlineColor(sf::Color::White);
    button.setOutlineThickness(2);
}

void drawButton(sf::RenderWindow& window, sf::Text& text, sf::RectangleShape& button) {
    window.draw(button);
    window.draw(text);
}

class WelcomeScreen {
private:
    sf::RenderWindow& window;
    sf::Font font, secondaryFont;
    sf::Texture cursorTexture;
    sf::Sprite cursorSprite;
    sf::SoundBuffer buffer;
    sf::Music music;
    sf::Sound clickSound;
    sf::Text welcometothe, starjump, playText;
    sf::RectangleShape playButton;

public:
    bool shouldStartGame = false;
    WelcomeScreen(sf::RenderWindow& win) : window(win) {
        if (!initializeResources()) {
            throw std::runtime_error("Failed to initialize resources");
        }
        setupScene();
    }

    bool initializeResources() {
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


        if (!cursorTexture.loadFromFile("Images/luma3.png")) {
            std::cerr << "Failed to load cursor image luma2.png" << std::endl;
            success = false;
        }
        cursorSprite.setTexture(cursorTexture);
        cursorSprite.setOrigin(cursorTexture.getSize().x / 2, cursorTexture.getSize().y / 2);


        if (!buffer.loadFromFile("Music/Luma Sound Effect.wav")) {
            std::cerr << "Failed to load sound effect Luma Sound Effect.wav" << std::endl;
            success = false;
        }
        clickSound.setBuffer(buffer);
        clickSound.setVolume(5);


        if (!music.openFromFile("Music/background.ogg")) {
            std::cerr << "Failed to open background music file" << std::endl;
            success = false;
        }
        music.setVolume(8);
        music.setLoop(true);
        music.play();

        return success;
    }

    void setupScene() {
        setupWelcomeText(welcometothe, secondaryFont);
        setupStarJumpText(starjump, font);
        setupPlayButton(playText, playButton, font);
    }

    void draw() {
        window.clear(sf::Color(138, 127, 141));
        cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

        drawText(window, welcometothe);
        drawText(window, starjump);
        drawButton(window, playText, playButton);
        window.draw(cursorSprite);
        window.display();
    }

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    clickSound.play();  // Play sound effect
                    if (playButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                        shouldStartGame = true; // Set the flag to transition to the play scene
                    }
                }
            }
        }
    }
};

#endif // WELCOME_SCREEN_H