#include <iostream>
using namespace std;
template <typename T>
class S_LinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
        Node(T val)
        {
            data = val;
        }
    };
    Node *start;
    int size;

public:
    S_LinkedList()
    {
        start = NULL;
        size = 0;
    }
    void insert(T val, int pos = -1)
    {
        if (pos < -1 || pos > size)
        {
            return;
        }
        size++;
        Node *temp = new Node(val);
        if (start == NULL)
        {
            start = temp;
            return;
        }
        if (pos == -1)
        {
            pos = size - 1;
        }
        if (pos == 0)
        {
            temp->next = start;
            start = temp;
        }
        else
        {
            pos--;
            Node *current = start;
            while (pos > 0)
            {
                current = current->next;
                pos--;
            }
            temp->next = current->next;
            current->next = temp;
        }
    }
    T remove(int pos = -1)
    {
        if (size == 0 || pos < -1 || pos >= size)
        {
            return false;
        }
        size--;
        T temp;
        if (pos == -1)
        {
            pos = size;
        }
        if (size == 0)
        {
            temp = start->data;
            delete start;
            start = NULL;
        }
        else if (pos == 0)
        {
            Node *ref = start;
            temp = start->data;
            start = start->next;
            delete ref;
        }
        else
        {
            pos--;
            Node *current = start;
            while (pos > 0)
            {
                current = current->next;
                pos--;
            }
            Node *ref = current->next;
            temp = current->next->data;
            current->next = current->next->next;
            delete ref;
        }
        return temp;
    }
    void reverse()
    {
        if (size <= 1)
        {
            return;
        }
        Node *first = start;
        Node *middle = first->next;
        Node *last = middle->next;
        int count = size - 1;
        while (count--)
        {
            middle->next = first;
            first = middle;
            middle = last;
            if (last != NULL)
            {
                last = last->next;
            }
        }
        start->next = NULL;
        start = first;
    }
    void swap(T V)
    {
        Node *current = start;
        while (current->next != NULL)
        {
            if (current->next->data == V)
            {
                current->next->data = current->data;
                current->data = V;
                return;
            }
            current = current->next;
        }
    }
    void print()
    {
        Node *current = start;
        while (current != NULL)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
};
int main()
{
    S_LinkedList<double> l;
    l.insert(1.8);
    l.insert(2.4);
    l.insert(3.2);
    l.insert(4.9);
    l.insert(5.1);
    l.insert(7.5);
    l.print(); // 1.8 -> 2.4 -> 3.2 -> 4.9 -> 5.1 -> 7.5 -> NULL
    l.remove(0);
    l.print(); // 2.4 -> 3.2 -> 4.9 -> 5.1 -> 7.5 -> NULL
    l.reverse();
    l.print(); // 7.5 -> 5.1 -> 4.9 -> 3.2 -> 2.4 -> NULL
    l.swap(4.9);
    l.print(); // 7.5 -> 4.9 -> 5.1 -> 3.2 -> 2.4 -> NULL
    return 0;
}