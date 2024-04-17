#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Star Jump Visualizer");

    // Load a font
    sf::Font font;
    if (!font.loadFromFile("Magic Retro.ttf")) {
        return -1; // Exit if the font file is not loaded successfully
    }

    // Set up the welcome text
    sf::Text text;
    text.setFont(font);
    text.setString("Welcome to the Star Jump Visualizer");
    text.setCharacterSize(36); // in pixels
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width / 2, textRect.height / 2);
    text.setPosition(400, 300); // Center the text in the window

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
        window.clear(sf::Color(204, 210, 253)); // Light blue color

        // Draw the text
        window.draw(text);

        // Update the window
        window.display();
    }

    return 0;
}
