#include <vector>
#include <tuple>
#include <cmath>
using namespace std;


#include "cube.h"
#include "node.h"


vector<Node> Cube::getFace(Node center, Node dir1, Node dir2, Node dir3){
    vector<Node> face;
    vector<int> compVals = {-1,1};
    for (auto i : compVals){
        for (auto j : compVals){
            face.push_back(center.add(dir1).add(dir2.multiply(i)).add(dir3.multiply(j)));
        }
    }
    return face;

}

void Cube::generateLines(vector<vector<Node>> faces){
    
    for (auto face : faces){
        for (int i = 0; i < face.size(); i++){
            if (i+1 == face.size()){
                getLine(face[i], face[0]);
            } else{
                getLine(face[i], face[i+1]);
            }
        }

    }
}

void Cube::getLine(Node node1, Node node2){
    Node dirVector = node1.getDirection(node2);   
    for (Node i = node1; !i.equal(node2); i = i.add(dirVector)){
        outline.push_back(i);
    }
    return;
}

Cube::Cube(Node center, double sideLength, Node directionFront, Node directionTop){
    vector<vector<Node>> faces;
    vector<Node> directions = {directionFront.multiply(sideLength/2), directionTop.multiply(sideLength/2)};
    Node directionLeft = directionFront.crossProduct(directionTop);
    directions.push_back(directionLeft.divide(directionLeft.distance(Node(0,0,0))).multiply(sideLength/2));

    vector<int> compVals = {-1,1};
    for (auto i :compVals){
        for (auto j :compVals){
            for (auto k :compVals){
                faces.push_back(this->getFace(center,directions[0].multiply(i), directions[1].multiply(j), directions[2].multiply(k)));
            }
        }
    }
    generateLines(faces);

}

vector<Node> Cube::getOutlineNodes(){
    return this->outline;
}