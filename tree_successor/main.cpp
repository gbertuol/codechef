#pragma once

#include <queue>
#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node<T> *parent;
    Node<T> *left;
    Node<T> *right;

    Node()
        : parent(nullptr)
        , left(nullptr)
        , right(nullptr)
    {}

    Node(const T &data)
        : data(data)
        , parent(nullptr)
        , left(nullptr)
        , right(nullptr)
    {}

};

template<typename T>
class PrePostVisitor
{
public:
    virtual void preVisit(T &) {}
    virtual void inVisit(T &) {}
    virtual void postVisit(T &) {}
    virtual bool isDone() const { return false; }
};

template<typename T>
class Visitor
{
public:
    virtual void visit(T &data)
    {
        std::cout << data << ", ";
    }
    bool isDone() const { return false; }
};

template<typename T>
class PreOrder
    : public PrePostVisitor<T>
{
public:
    void preVisit(T &data)
    {
        std::cout << data << ", ";
    }

};

template<typename T>
class InOrder
    : public PrePostVisitor<T>
{
public:
    void inVisit(T &data)
    {
        std::cout << data << ", ";
    }

};

template<typename T>
class Tree
{
public:
    Node<T> *root;

    Tree()
        : root(nullptr)
    {}

    ~Tree()
    {
        purge(root);
    }

    void insert(const T &data)
    {
        if (!root)
        {
            root = new Node<T>;
            root->data = data;
        }
        else
        {
            insert(data, root);
        }
    }

    void remove(const T &data)
    {
        remove(data, root);
    }

    void depthFirst(PrePostVisitor<T> &visitor)
    {
        dfs(visitor, root);
    }

    void breadthFirst(Visitor<T> &visitor)
    {
        if (visitor.isDone())
            return;

        std::queue<Node<T>*> queue;
        queue.push(root);
        while (!queue.empty() && !visitor.isDone())
        {
            Node<T> *node = queue.front();
            queue.pop();
            if (node)
            {
                visitor.visit(node->data);
                queue.push(node->left);
                queue.push(node->right);
            }
        }
    }

protected:
    void dfs(PrePostVisitor<T> &visitor, Node<T> *node)
    {
        if (visitor.isDone())
            return;
        if (node)
        {
            visitor.preVisit(node->data);
            dfs(visitor, node->left);
            visitor.inVisit(node->data);
            dfs(visitor, node->right);
            visitor.postVisit(node->data);
        }
    }

    void insert(const T &data, Node<T> *node)
    {
        if (data < node->data)
        {
            if (node->left)
                insert(data, node->left);
            else
            {
                node->left = new Node<T>;
                node->left->parent = node;
                node->left->data = data;
            }
        }
        else if (data > node->data)
        {
            if (node->right)
                insert(data, node->right);
            else
            {
                node->right = new Node<T>;
                node->right->parent = node;
                node->right->data = data;
            }
        }
    }

    void remove(const T &data, Node<T> *node)
    {
        if (!node)
            return;

        if (node->data == data)
        {
            if (node->left)
            {
                T max = findMax(node->left);
                node->data = max;
                remove(max, node->left);
            }
            else if (node->right)
            {
                T min = findMin(node->right);
                node->data = min;
                remove(min, node->right);
            }
            else
            {
                detach(node);
            }
        }
        else if (data < node->data)
        {
            remove(data, node->left);
        }
        else
        {
            remove(data, node->right);
        }
    }

    T findMax(Node<T> *node)
    {
        if (!node->right)
            return node->data;
        return findMax(node->right);
    }

    T findMin(Node<T> *node)
    {
        if (!node->left)
            return node->data;
        return findMin(node->left);
    }

    void detach(Node<T> *node)
    {
        Node<T> *parent = node->parent;
        if (parent->left == node)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete node;
    }

    void purge(Node<T> *node)
    {
        if (node)
        {
            purge(node->left);
            purge(node->right);
            delete node;
        }
    }
};

template <typename T>
Node<T>* leftMost(Node<T> *node)
{
    if (!node)
        return node;

    while (node->left)
        node = node->left;
    return node;
}

template <typename T>
Node<T>* successor(Node<T> *node)
{
    if (!node)
        return nullptr;

    if (node->right)
    {
        return leftMost(node->right);
    }
    else
    {
        Node<T> *parent = node;
        Node<T> *grandParent = parent->parent;
        while (grandParent && grandParent->left != parent)
        {
            parent = grandParent;
            grandParent = parent->parent;
        }
        return grandParent;
    }
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

    //InOrder<int> visitor;
    //tree.depthFirst(visitor);

    std::cout << successor(tree.root->right)->data;

    return 0;
}
