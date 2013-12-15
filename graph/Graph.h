#pragma once
#include <list>


enum State
{
    Unvisited, Visiting, Visited
};

class Node
{
public:
    State state;
    std::list<Node*> adjacents;
};


class Graph
{
public:
    std::list<Node> nodes;


};