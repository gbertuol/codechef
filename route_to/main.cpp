#include <Graph.h>
#include <queue>
#include <iostream>


template<typename T>
bool hasRouteTo(Graph<T> &graph, const T &source, const T &target)
{
    if (source == target)
        return true;

    Node<T> *source_node = graph.find(source);
    std::queue<Node<T>*> queue;
    queue.push(source_node);
    source_node->state = Visiting;

    while (!queue.empty())
    {
        Node<T> *node = queue.front();
        queue.pop();
        for (Node<T> *v : node->adjacents)
        {
            if (v->state == Unvisited)
            {
                if (v->data == target)
                    return true;
                else
                {
                    v->state = Visiting;
                    queue.push(v);
                }
            }
        }
        node->state = Visited;
    }
    return false;
}

int main()
{
    Graph<char> graph;
    graph.addNode('A');
    graph.addNode('B');
    graph.addNode('C');
    graph.addNode('D');

    graph.addLink('A', 'B');
    graph.addLink('B', 'C');
    graph.addLink('C', 'B');
    //graph.addLink('C', 'D');

    std::cout << hasRouteTo(graph, 'A', 'D');
}