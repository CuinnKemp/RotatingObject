#include <iostream>
#include<vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace std;

#include "node.h"
#include "cube.h"
#include "axis.h"

int main(){
    double width = sf::VideoMode::getDesktopMode().width;
    double height = sf::VideoMode::getDesktopMode().height;
    sf::RenderWindow window(sf::VideoMode(width, height), "Axis");


    Node center(20,0,0);

    Cube c1(center, 60, Node(1,0,0), Node(0,1,1));
    Axis axis(Node(1,0,0), Node(0,0,0),  &window, width, height);
    window.clear(sf::Color::White);
    sf::View view;
    view.setCenter(0,0);
    window.setView(view);

    int counter = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
            window.close();
            }
        }
        axis.drawNodes(c1.getOutlineNodes());
        window.display();
        window.clear(sf::Color::White);
    }
}
