#include <vector>
#include <SFML/Graphics.hpp>

class ColorFader {
private:
    std::vector<sf::Color> colors;
    int currentColorIndex = 0;
    float transitionTime = 3.0; // Transition time in seconds
    float timeSinceLastChange = 0.0;
    sf::Color currentColor;
    sf::Color targetColor;

public:
    ColorFader() {
        // Initialize colors
        colors.push_back(sf::Color(229, 229, 229));
        colors.push_back(sf::Color(220, 220, 220));
        colors.push_back(sf::Color(201, 201, 201));
        colors.push_back(sf::Color(138, 127, 141));
        colors.push_back(sf::Color(145, 163, 176));

        // Set initial and target colors
        currentColor = colors[0];
        targetColor = colors[1];
    }

    void update(float deltaTime) {
        timeSinceLastChange += deltaTime;
        if (timeSinceLastChange >= transitionTime) {
            // Move to the next color in the cycle
            timeSinceLastChange = 0.0f;
            currentColorIndex = (currentColorIndex + 1) % colors.size();
            currentColor = targetColor;
            targetColor = colors[(currentColorIndex + 1) % colors.size()];
        }

        // Calculate the interpolation factor
        float t = timeSinceLastChange / transitionTime;
        // Interpolate between currentColor and targetColor
        sf::Color interpolatedColor = interpolate(currentColor, targetColor, t);
        currentColor = interpolatedColor;  // Update current color to the interpolated color
    }

    sf::Color getCurrentColor() const {
        return currentColor;
    }

private:
    sf::Color interpolate(const sf::Color& start, const sf::Color& end, float t) {
        return sf::Color(
                static_cast<sf::Uint8>(start.r + t * (end.r - start.r)),
                static_cast<sf::Uint8>(start.g + t * (end.g - start.g)),
                static_cast<sf::Uint8>(start.b + t * (end.b - start.b))
        );
    }
};
