#include <iostream>
using namespace std;
template <typename T>
class C_LinkedList
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
    Node *start, *end;
    int size;

public:
    C_LinkedList()
    {
        start = NULL;
        size = 0;
    }
    T front()
    {
        if (size == 0)
        {
            return false;
        }
        return start->data;
    }
    T back()
    {
        if (size == 0)
        {
            return false;
        }
        return end->data;
    }
    void advance()
    {
        if (size == 0)
        {
            return;
        }
        start = start->next;
        end = end->next;
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
            start->next = end;
            end->next = start;
            return;
        }
        if (pos == -1)
        {
            end->next = temp;
            end = temp;
            end->next = start;
            return;
        }
        if (pos == 0)
        {
            temp->next = start;
            start = temp;
            end->next = temp;
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
            start = end = NULL;
        }
        else if (pos == 0)
        {
            Node *ref = start;
            temp = start->data;
            end->next = start = start->next;
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
            if (ref == end)
            {
                end = current;
            }
            temp = current->next->data;
            current->next = current->next->next;
            delete ref;
        }
        return temp;
    }
    void print()
    {
        Node *current = start;
        int count = 2 * size;
        while (count--)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "START\n";
    }
};
int main()
{
    C_LinkedList<double> l;
    l.insert(1.8);
    l.insert(2.4);
    l.insert(3.2);
    l.insert(4.9);
    l.insert(5.1);
    l.insert(7.5);
    l.print(); // 1.8 -> 2.4 -> 3.2 -> 4.9 -> 5.1 -> 7.5 -> 1.8 -> 2.4 -> 3.2 -> 4.9 -> 5.1 -> 7.5 -> START
    l.remove();
    l.print();                 // 1.8 -> 2.4 -> 3.2 -> 4.9 -> 5.1 -> 1.8 -> 2.4 -> 3.2 -> 4.9 -> 5.1 -> START
    cout << l.front() << "\n"; // 1.8
    cout << l.back() << "\n";  // 5.1
    l.advance();
    l.print();                 // 2.4 -> 3.2 -> 4.9 -> 5.1 -> 1.8 -> 2.4 -> 3.2 -> 4.9 -> 5.1 -> 1.8 -> START
    cout << l.front() << "\n"; // 2.4
    cout << l.back() << "\n";  // 1.8
    return 0;
}