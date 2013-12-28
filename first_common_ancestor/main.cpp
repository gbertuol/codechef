#include <Tree.h>


template<typename T>
bool covers(Node<T> *root, Node<T> *node)
{
    if (!root) return false;
    if (root == node) return true;
    return covers(root->left, node) || covers(root->right, node);
}


template<typename T>
Node<T>* firstCommonAncestor(Node<T> *root, Node<T> *p, Node<T> *q)
{
    if (!root) false;
    if (root == p || root == q) return root;

    bool is_p_on_left = covers(root->left, p);
    bool is_q_on_left = covers(root->left, q);

    if (is_p_on_left != is_q_on_left)
        return root;

    Node<T> *side = is_p_on_left ? root->left : root->right;
    return firstCommonAncestor(side, p, q);
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

    std::cout << firstCommonAncestor(tree.root, tree.root->left->right, tree.root->left->left)->data;

    return 0;
}