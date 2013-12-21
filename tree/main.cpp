#include "Tree.h"


int main()
{
    Tree<int> tree;
    tree.insert(4);
    tree.insert(5);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    tree.insert(7);

    tree.remove(2);
    PreOrder<int> visitor;
    tree.depthFirst(visitor);

    //Visitor<int> bfs;
    //tree.breadthFirst(bfs);

    return 0;
}