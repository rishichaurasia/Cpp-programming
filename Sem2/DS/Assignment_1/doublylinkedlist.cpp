#include <iostream>
using namespace std;
template <typename T>
class D_LinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node *next, *previous;
        Node(T val)
        {
            data = val;
        }
    };
    Node *start, *end;
    int size;

public:
    D_LinkedList()
    {
        start = end = NULL;
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
            start = end = temp;
            return;
        }
        if (pos == -1)
        {
            end->next = temp;
            temp->previous = end;
            temp->next = NULL;
            end = temp;
        }
        else if (pos == 0)
        {
            temp->next = start;
            start->previous = temp;
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
            current->next->previous = temp;
            current->next = temp;
            temp->next = current->next;
            temp->previous = current;
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
        if (size == 0)
        {
            temp = start->data;
            delete start;
            start = end = NULL;
        }
        else if (pos == -1 || pos == size)
        {
            temp = end->data;
            Node *ref = end;
            end = end->previous;
            end->next = NULL;
            delete ref;
            return temp;
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
            if (current->next->next != NULL)
            {
                current->next->next->previous = current;
            }
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
        Node *last = end;
        for (int i = 0; i < size / 2; i++)
        {
            T temp = first->data;
            first->data = last->data;
            last->data = temp;
            first = first->next;
            last = last->previous;
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
    void printend()
    {
        cout << end->data << "\n";
    }
};
int main()
{
    D_LinkedList<double> l;
    l.insert(1.8);
    l.insert(2.4);
    l.insert(3.2);
    l.insert(4.9);
    l.insert(5.1);
    l.insert(5.7);
    l.print(); // 1.8 -> 2.4 -> 3.2 -> 4.9 -> 5.1 -> 5.7 -> NULL
    l.remove();
    l.print(); // 1.8 -> 2.4 -> 3.2 -> 4.9 -> 5.1 -> NULL
    l.reverse();
    l.print(); // 5.1 -> 4.9 -> 3.2 -> 2.4 -> 1.8 -> NULL
    return 0;
}