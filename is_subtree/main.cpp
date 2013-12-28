#include <Tree.h>


template <typename T>
bool matchTree(Node<T> *a, Node<T> *b)
{
    if (!a && !b)
        return true;

    if (!a || !b)
        return false;

    if (a->data != b->data)
        return false;

    return matchTree(a->left, b->left) && matchTree(a->right, b->right);
}

template <typename T>
bool subtree(Node<T> *a, Node<T> *b)
{
    if (!a)
        return false;

    if (a->data == b->data)
    {
        if (matchTree(a, b))
            return true;
    }
    return subtree(a->left, b) || subtree(a->right, b);
}

template <typename T>
bool isSubtree(Tree<T> &a, Tree<T> &b)
{
    if (!b.root)
        return true;

    return subtree(a.root, b.root);
}


int main()
{
    Tree<int> tree;
    tree.insert(50);
    tree.insert(17);
    tree.insert(12);
    tree.insert(9);
    tree.insert(14);
    tree.insert(23);
    tree.insert(19);
    tree.insert(72);
    tree.insert(54);
    tree.insert(67);
    tree.insert(76);

    Tree<int> subtree;
    subtree.insert(12);
    subtree.insert(9);
    subtree.insert(14);

    std::cout << isSubtree(tree, subtree);

    return 0;
}