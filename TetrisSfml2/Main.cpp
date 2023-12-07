#include <SFML/Graphics.hpp>
#include <iostream>
#include "Textbox.h"
#include "Button.h"
#include "TetrisGame.cpp"

int main() {
    sf::RenderWindow window;

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    window.create(sf::VideoMode(900, 900), "Tetris", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    sf::Font karla;
    karla.loadFromFile("karla.ttf");
    Textbox textbox1(15, sf::Color::Blue, false);
    textbox1.setFont(karla);
    textbox1.setPosition({ 100, 100 });
    textbox1.setLimit(true, 10);

    Textbox textbox2(15, sf::Color::Blue, false);
    textbox2.setFont(karla);
    textbox2.setPosition({ 100, 200 });
    textbox2.setLimit(true, 10);

    Button btn1("Play", { 200,50 }, 30, sf::Color::Green, sf::Color::Black);
    btn1.setPosition({ 100, 300 });
    btn1.setFont(karla);

    Button btn2("Help", { 200,50 }, 30, sf::Color::Green, sf::Color::Black);
    btn2.setPosition({ 100, 400 });
    btn2.setFont(karla);

    TetrisGame tetris(window);

    // Main Loop:
    while (window.isOpen()) {
        sf::Event Event;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            textbox1.setSelected(true);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            textbox1.setSelected(false);
        }

        // Event Loop:
        while (window.pollEvent(Event)) {
            switch (Event.type) {

            case sf::Event::Closed:
                window.close();
            case sf::Event::TextEntered:
                textbox1.typedOn(Event);
                textbox2.typedOn(Event);
                break;
            case sf::Event::MouseMoved:
                if (btn1.isMouseOver(window)) {
                    btn1.setBackColor(sf::Color::White);
                }
                else {
                    btn1.setBackColor(sf::Color::Cyan);
                }
                if (btn2.isMouseOver(window)) {
                    btn2.setBackColor(sf::Color::White);
                }
                else {
                    btn2.setBackColor(sf::Color::Green);
                }
                break;

            case sf::Event::MouseButtonPressed:
                if (btn1.isMouseOver(window)) {
                    std::cout << "Ai apasat butonul play\n";
                    
                }
                else if (btn2.isMouseOver(window)) {
                    std::cout << "Ai apasat butonul help\n";
                }
                break;
            }
        }

        window.clear(sf::Color::Black);
        textbox1.drawTo(window);
        textbox2.drawTo(window);
        btn1.drawTo(window);
        btn2.drawTo(window);
        window.display();
    }

    return 0;
}
