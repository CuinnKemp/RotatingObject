#include <vector>
#include <tuple>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace std;


#include "cube.h"
#include "node.h"
#include "axis.h"



Axis::Axis(Node normalVector, Node center, sf::RenderWindow* window, double width, double height){
    this->normalVector = normalVector.add(Node(0,0,0));
    this->center = center.add(Node(0,0,0));
    this->planeVector1 = Node(0,0,1);
    this->planeVector2 = planeVector1.crossProduct(normalVector);
    this->window = window;
    this->width = width;
    this->height = height;
}

void Axis::drawNodes(vector<Node> nodes){
    for (auto node : nodes){
        Node nodeOnPlane = node.sub(normalVector.multiply(node.dotProd(normalVector)/pow(normalVector.distance(Node(0,0,0)),2)));
        nodeOnPlane = nodeOnPlane.sub(center);

        double up = nodeOnPlane.z;
        double right;
        if (nodeOnPlane.x != 0){
            right = nodeOnPlane.x/planeVector2.x;
        } else{
            right = nodeOnPlane.y/planeVector2.y;
        }
        
        

        
        sf::CircleShape circle;
        circle.setPosition(up,right);
        circle.setFillColor(sf::Color::Black);
        circle.setRadius(2);
        window->draw(circle);

        
    }
}
