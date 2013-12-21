#pragma once
#include <cstdlib>
#include <ostream>

template <typename T>
class Node
{
public:
    Node *next;
    T data;

    Node(const T &data)
        : next(NULL)
        , data(data)
    {}
};

template <typename T>
class LinkedList
{
public:
    Node<T> *head;

    LinkedList()
        : head(NULL)
    {}

    ~LinkedList()
    {
        removeAll();
    }

    LinkedList<T>(const LinkedList<T> &o)
    {
        copyFrom(o);
    }

    LinkedList<T> operator=(const LinkedList<T> &o)
    {
        if (this != &o)
        {
            copyFrom(o);
        }

        return *this;
    }

    const Node<T>* tail() const
    {
        Node<T> *tail = head;
        while (tail)
            tail = tail->next;
        return tail;
    }

    Node<T>* appendToTail(const T &data)
    {
        Node<T> *end = new Node<T>(data);
        if (!head)
        {
            head = end;
            return end;
        }

        Node<T> *tail = head;
        while (tail->next)
            tail = tail->next;
        tail->next = end;

        return end;
    }

    Node<T>* appendToHead(const T &data)
    {
        Node<T> *new_head = new Node<T>(data);
        new_head->next = head;
        head = new_head;

        return new_head;
    }

    Node<T>* insertAfter(const T &data, const Node<T> *node)
    {
        Node<T> *curr = head;
        while (curr != node)
            curr = curr->next;

        Node<T> *new_node = new Node<T>(data);
        new_node->next = curr->next;
        curr->next = new_node;

        return new_node;
    }

    Node<T>* insertBefore(const T &data, const Node<T> *node)
    {
        Node<T> *curr = head;
        while (curr->next != node)
            curr = curr->next;

        Node<T> *new_node = new Node<T>(data);
        new_node->next = curr->next;
        curr->next = new_node;
    }

    void remove(const Node<T> *node)
    {
        Node<T> *curr = head;
        while (curr->next != node)
            curr = curr->next;

        Node<T> *to_remove = curr->next;
        curr->next = curr->next->next;
        delete to_remove;
    }

    void print(std::ostream &ostream) const
    {
        auto curr = head;
        while (curr)
        {
            ostream << curr->data << ", ";
            curr = curr->next;
        }
        ostream << std::endl;
    }

    void copyFrom(const LinkedList<T> &other)
    {
        removeAll();
        const Node<T> *ptr = other.head;

        while (ptr)
        {
            appendToTail(ptr->data);
            ptr = ptr->next;
        }
    }

    void removeAll()
    {
        while (head)
        {
            Node<T> *next = head->next;
            delete head;
            head = next;
        }
    }

    size_t size() const
    {
        size_t size = 0;
        for (const Node<T> *ptr = head; ptr; ++size, ptr = ptr->next);
        return size;
    }
};