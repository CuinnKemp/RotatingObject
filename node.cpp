#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

#include "node.h"

Node::Node(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Node::Node(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
};

Node Node::sub(Node node){
    return Node(this->x + -node.x, this->y + -node.y, this->z + -node.z);
}
Node Node::add(Node node){
    return Node(this->x + node.x, this->y + node.y, this->z + node.z);
}

Node Node::neg(){
    return Node(0,0,0).sub(*this);
}

Node Node::multiply(double num){
    return Node(this->x * num, this->y * num, this->z * num);
}

Node Node::divide(double num){
    return multiply(1/num);
}

double Node::dotProd(Node node){
    return this->x * node.x + this->y * node.y + this->z * node.z;
}

double Node::distance(Node node){
    Node added = node.add(*this);
    return sqrt(pow(added.x,2) + pow(added.y,2) + pow(added.z,2));
}

Node Node::getDirection(Node node){
    Node rawDirection =(this->neg().add(node));
    return rawDirection.divide(this->distance(node));
}

vector<double> Node::getNode(){
    return {this->x, this->y, this->z};
}

bool Node::equal(Node node){
    if ((int)this->x == (int)node.x && (int)this->y == (int)node.y && (int)this->z == (int)node.z){
        return true;
    }
    return false;
}

Node Node::crossProduct(Node node){
    return Node(this->y * node.z - this->z * node.y,
                this->z * node.x - this->x * node.z,
                this->x * node.y - this->y * node.x);
}

void Node::print(){
    cout << "(" << this->x << "," << this->y << "," << this->z << ")";
}
void Node::print(bool newLine){
    cout << "(" << this->x << "," << this->y << "," << this->z << ")";
    if (newLine){
        cout << endl;
    }
}