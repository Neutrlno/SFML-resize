#include <SFML/Graphics.hpp>

class RenderCallbacks : public sf::WindowCallbacks
{
public:
    RenderCallbacks(sf::RenderWindow& mainWindow)
        : window(mainWindow)
    {
        rectShape.setSize({ 200, 200 });
        rectShape.setOrigin({ 100, 100 });
        rectShape.setFillColor({ 100, 180, 100 });
    }

    void asyncRender(const sf::Event* optionalResizedEvent) override
    {
        window.clear(sf::Color::Black);

        sf::FloatRect visibleArea(0.f, 0.f, float(window.getSize().x), float(window.getSize().y));
        window.setView(sf::View(visibleArea));
        const sf::Time& timeNow = clock.getElapsedTime();
        const sf::Time& timeDiff = timeNow - timePrev;

        rectShape.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
        rectShape.rotate(360 * timeDiff.asSeconds() / 5);

        window.draw(rectShape);
        window.display();
        timePrev = timeNow;
    }

private:
    sf::RenderWindow& window;
    sf::RectangleShape rectShape;
    sf::Clock clock;
    sf::Time timePrev = clock.getElapsedTime();
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Window");

    RenderCallbacks windowCallbacks(window);
    window.setWindowCallbacks(&windowCallbacks);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        windowCallbacks.asyncRender(nullptr);
    }

    return 0;
}