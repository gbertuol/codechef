#include <Tree.h>
#include <LinkedList.h>

template<typename T>
void depths(Node<T> *root, std::vector<LinkedList<T>> &lists, int level)
{
    if (!root)
        return;

    LinkedList<T> *list;
    if (level == lists.size())
    {
        lists.push_back(LinkedList<T>());
        list = &lists.back();
    }
    else
        list = lists[level];

    list->appendToTail(root->data);
    depths(root->left, lists, level + 1);
    depths(root->right, lists, level + 1);
}

template<typename T>
void depths(Tree<T> &tree)
{
    std::vector<LinkedList<T>> lists;

    depths(tree.root, lists, 0);
}


int main()
{
    Tree<int> tree;
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(2);
    tree.insert(5);
    tree.insert(9);
    tree.insert(8);
    tree.insert(7);

    return 0;
}