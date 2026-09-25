#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <cstddef>
#include <stdexcept>
#include <random>

template <class T>
class CircularLinkedList
{
public:
    CircularLinkedList();
    CircularLinkedList(size_t n, T val);
    void insertBefore(size_t index, T val);
    void insertAtEnd(T val);
    size_t size();
    void erase(size_t index);
    T& operator[](size_t index);
    ~CircularLinkedList();
    void step();
    void rollTheDice();
    T& getCurrentSpace();

private:
    typedef struct Node {
        T data;
        Node* next;
    } Node;

    Node* start;
    size_t currentSpace;
};

template <class T>
CircularLinkedList<T>::CircularLinkedList()
{
    start = nullptr;
    currentSpace = 0;
}

template <class T>
CircularLinkedList<T>::CircularLinkedList(size_t n, T val)
{
    start = nullptr;
    currentSpace = 0;
    for (size_t i = 0; i < n; i++)
    {
        insertAtEnd(val);
    }
}

template<class T>
CircularLinkedList<T>::~CircularLinkedList()
{
    while (size() != 0)
        erase(0);
}

template<class T>
void CircularLinkedList<T>::rollTheDice()
{
    std::random_device rd;
    std::mt19937_64 g(rd());
    size_t die1 = 1 + (g() % 6);
    size_t die2 = 1 + (g() % 6);
    currentSpace += die1 + die2;
}

template <class T>
T& CircularLinkedList<T>::getCurrentSpace()
{
    return (*this)[currentSpace];
}

template <class T>
void CircularLinkedList<T>::step()
{
    currentSpace++;
}

template <class T>
T& CircularLinkedList<T>::operator[](size_t index)
{
    while (index >= size())
    {
        index -= size();
    }
    if (index == 0) return start->data;
    size_t i = 1;
    Node* n = start->next;
    while (i < index)
    {
        n = n->next;
        i++;
    }
    return n->data;
}

template <class T>
void CircularLinkedList<T>::erase(size_t index)
{
    while (index >= size())
    {
        index -= size();
    }
    if (size() == 1)
    {
        delete start;
        start = nullptr;
        return;
    }
    if (index == 0)
    {
        Node* n = start;
        while (n->next != start)
        {
            n = n->next;
        }
        Node* toDelete = start;
        start = start->next;
        n->next = start;
        delete toDelete;
    }
    else
    {
        size_t i = 1;
        Node* n = start;
        while (i < index)
        {
            n = n->next;
            i++;
        }
        Node* toDelete = n->next;
        n->next = toDelete->next;
        delete toDelete;
    }
}

template <class T>
size_t CircularLinkedList<T>::size()
{
    if (start == nullptr) return 0;
    size_t result = 1;
    Node* n = start->next;
    while (n != start)
    {
        n = n->next;
        result++;
    }
    return result;
}

template <class T>
void CircularLinkedList<T>::insertAtEnd(T val)
{
    if (start == nullptr)
    {
        start = new Node;
        start->data = val;
        start->next = start;
    }
    else
    {
        Node* n = start;
        while (n->next != start)
        {
            n = n->next;
        }
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = n->next;
        n->next = newNode;
    }
}

template <class T>
void CircularLinkedList<T>::insertBefore(size_t index, T val)
{
    while (index >= size())
    {
        index -= size();
    }
    if (index == 0)
    {
        Node* n = start;
        while (n->next != start)
        {
            n = n->next;
        }
        Node* newNode = new Node;
        newNode->data = val;
        n->next = newNode;
        newNode->next = start;
        start = newNode;
    }
    else
    {
        size_t i = 1;
        Node* n = start;
        while (i < index)
        {
            n = n->next;
            i++;
        }
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = n->next;
        n->next = newNode;
    }
}

#endif // CIRCULARLINKEDLIST_H
