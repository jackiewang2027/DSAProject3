#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Star Jump Visualizer");

    // Load a font
    sf::Font font;
    sf::Font secondaryFont;
    if (!font.loadFromFile("Carrots.otf")) {
        return -1; // Exit if the font file is not loaded successfully
    }
    if (!secondaryFont.loadFromFile("Stars.ttf")) {
        return -1; // Exit if the font file is not loaded successfully
    }

    // Set up the welcome text
    sf::Text starjump;

    sf::Text welcometothe;
    welcometothe.setFont(secondaryFont);
    welcometothe.setString("Welcome To The");
    welcometothe.setCharacterSize(42);
    welcometothe.setFillColor(sf::Color::White);
    welcometothe.setStyle(sf::Text::Bold);
    sf::FloatRect textRect2 = welcometothe.getLocalBounds();
    welcometothe.setOrigin(textRect2.width / 2, textRect2.height / 2);
    welcometothe.setPosition(400, 240); // Center the text in the window

    starjump.setFont(font);
    starjump.setString("Star Jump Visualizer");


    starjump.setCharacterSize(46); // in pixels
    starjump.setFillColor(sf::Color::White);
    starjump.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = starjump.getLocalBounds();


    starjump.setOrigin(textRect.width / 2, textRect.height / 2);
    starjump.setPosition(400, 280); // Center the text in the window

    // Load and play background music
    sf::Music music;
    if (!music.openFromFile("background.ogg")) {
        return -1;
    }
    music.setLoop(true); // Set the music to loop
    music.play(); // Start playing the music

    // Main loop that runs as long as the window is open
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the screen with a light color
        window.clear(sf::Color(138, 127, 141)); // Light blue color

        window.draw(welcometothe);
        window.draw(starjump);

        // Update the window
        window.display();
    }

    return 0;
}
