#include <cmath>
#include <iostream>
#include <algorithm>

class Node
{
public:
    Node *left;
    Node *right;

    Node()
        : left(nullptr)
        , right(nullptr)
    {}
};


int height(Node *root)
{
    if (!root)
        return 0;
    return std::max(height(root->left), height(root->right)) + 1;
}

int check_height(Node *root)
{
    if (!root)
        return 0;

    int left_height = check_height(root->left);
    if (left_height == -1)
        return -1;

    int right_height = check_height(root->right);
    if (right_height == -1)
        return -1;

    int diff = left_height - right_height;
    if (std::abs(diff) > 1)
        return -1;
    else
        return std::max(left_height, right_height) + 1;
}

bool is_balanced(Node *root)
{
    return check_height(root) != -1;
}


int main()
{
    Node root, a, b, c, d, e, f, g, h;
    root.left = &a;
    a.left = &b;
    //b.left = &c;
    //b.right = &g;
    //g.right = &h;

    root.right = &d;
    //d.left = &e;
    //e.left = &f;

    std::cout << is_balanced(&root) << std::endl;
}