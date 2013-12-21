#include <Tree.h>
#include <vector>


void append(Node<int> *&root, int left, int right, const std::vector<int> &array)
{
    if (right < left)
        return;

    int root_pos = (right + left) / 2;
    root = new Node<int>(array[root_pos]);

    append(root->left, left, root_pos - 1, array);
    append(root->right, root_pos + 1, right, array);
}

void toBST(Tree<int> &bst, const std::vector<int> &array)
{
    int size = array.size();
    append(bst.root, 0, size - 1, array);
}

int main()
{
    std::vector<int> array;
    for (int i = 0; i < 40; ++i)
        array.push_back(i + 1);

    Tree<int> tree;
    toBST(tree, array);

    InOrder<int> visitor;
    tree.depthFirst(visitor);

    return 0;
}