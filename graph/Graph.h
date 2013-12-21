#pragma once
#include <list>
#include <algorithm>

enum State
{
    Unvisited, Visiting, Visited
};

template <typename T>
class Node
{
public:
    T data;
    State state;
    std::list<Node<T>*> adjacents;

    Node(const T &data)
        : data(data)
        , state(Unvisited)
    {}
};

template<typename T>
class Graph
{
public:
    std::list<Node<T>> nodes;

    void addNode(const T &node)
    {
        nodes.push_back(Node<T>(node));
    }

    void addLink(const T &p, const T &q)
    {
        find(p)->adjacents.push_back(find(q));
    }

    Node<T> *find(const T &data)
    {
        return &*std::find_if(begin(nodes), end(nodes), [&data](const Node<T> &n) { return n.data == data;  });
    }
};
