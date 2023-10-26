
#ifndef AXIS
#define AXIS

#include <vector>
#include <tuple>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace std;


#include "cube.h"
#include "node.h"


class Axis{
    public:
    Node normalVector;
    Node planeVector1;
    Node planeVector2;
    Node center;
    sf::RenderWindow* window;
    double width; 
    double height;

    Axis(Node normalVector, Node center, sf::RenderWindow* window, double width, double height);

    void drawNodes(vector<Node> nodes);
};

#endif //AXIS