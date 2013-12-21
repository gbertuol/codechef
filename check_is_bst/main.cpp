#include <Tree.h>

#include <limits>

template<typename T>
bool isBST(Node<T> *node, T min, T max)
{
    if (!node)
        return true;
    
    if (node->data < min || node->data >= max)
        return false;

    if (!isBST(node->left, min, node->data))
        return false;
    if (!isBST(node->right, node->data, max))
        return false;
    return true;
}

template<typename T>
bool isBST(Tree<T> &tree)
{
    return isBST(tree.root, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
}


int main()
{
    Tree<int> tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(5);
    tree.insert(7);
    tree.insert(3);
    tree.insert(15);
    tree.insert(17);
    tree.insert(30);

    //InOrder<int> visitor;
    //tree.depthFirst(visitor);

    std::cout << isBST(tree);

    return 0;
}