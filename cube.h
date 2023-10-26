#ifndef CUBE
#define CUBE

#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

#include "node.h"

class Cube{
private:
    vector<Node> outline;

    vector<Node> getFace(Node center, Node dir1, Node dir2, Node dir3);

    void generateLines(vector<vector<Node>> faces);

    void getLine(Node node1, Node node2);

public:
    Cube(Node center, double sideLength, Node directionFront, Node directionTop);

    // Cube(Node center, double sideLength, Node directionFront, double angle);

    vector<Node> getOutlineNodes();
};

#endif //CUBE