#ifndef NODE
#define NODE

#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

class Node{
public:
    double x;
    double y;
    double z;

    Node();

    Node(double x, double y, double z);
    
    Node sub(Node node);

    Node add(Node node);

    Node neg();

    Node multiply(double num);

    Node divide(double num);

    double dotProd(Node node);
    
    double distance(Node node);

    Node getDirection(Node node);

    vector<double> getNode();

    bool equal(Node node);

    Node crossProduct(Node node);

    void print();

    void print(bool newLine);

};

#endif //Node