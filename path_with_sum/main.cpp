#include <Tree.h>
#include <vector>


template<typename T>
int depth(Node<T> *node)
{
    if (!node)
        return 0;
    return 1 + std::max(depth(node->left), depth(node->right));
}

template<typename T>
void print(std::vector<T> &path, int level)
{
    for (int i = 0; i <= level; ++i)
        std::cout << path[i] << ", ";
    std::cout << std::endl;
}

template<typename T>
void print(std::vector<T> &path, int start, int end)
{
    for (int i = start; i <= end; ++i)
        std::cout << path[i] << ", ";
    std::cout << std::endl;
}

template<typename T>
void pathWithSumFromRoot(Node<T> *node, T sum, std::vector<T> &path, int level)
{
    if (!node)
        return;

    path[level] = node->data;

    T soFar = 0;
    for (int i = 0; i <= level; ++i)
        soFar += path[i];

    if (soFar == sum)
        print(path, level);

    pathWithSumFromRoot(node->left, sum, path, level + 1);
    pathWithSumFromRoot(node->right, sum, path, level + 1);
}

template<typename T>
void pathWithSumFromRoot(Node<T> *root, T sum)
{
    int maxPath = depth(root);
    std::vector<T> path(maxPath);
    pathWithSumFromRoot(root, sum, path, 0);
}

template<typename T>
void pathWithSum(Node<T> *node, T sum, std::vector<T> &path, int level)
{
    if (!node)
        return;

    path[level] = node->data;
    T soFar = 0;
    for (int i = level; i >= 0; --i)
    {
        soFar += path[i];
        if (soFar == sum)
            print(path, i, level);
    }

    pathWithSum(node->left, sum, path, level + 1);
    pathWithSum(node->right, sum, path, level + 1);
}

template<typename T>
void pathWithSum(Node<T> *node, T sum)
{
    int maxPath = depth(node);
    std::vector<T> path(maxPath);
    pathWithSum(node, sum, path, 0);
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

    pathWithSumFromRoot(tree.root, 198);
    pathWithSum(tree.root, 26);

    return 0;
}