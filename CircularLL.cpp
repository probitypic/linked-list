#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void Append(node *&head, int x)
{
    node *n = new node(x);

    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }

    node *tmp = head;

    while (tmp->next != head)
    {
        tmp = tmp->next;
    }

    n->next = head;
    tmp->next = n;
}

void Push(node *&head, int x)
{
    node *n = new node(x);

    if (head == NULL)
    {
        head = n;
        n->next = n;
        return;
    }

    node *tmp = head;

    while (tmp->next != head)
    {
        tmp = tmp->next;
    }

    tmp->next = n;
    n->next = head;
    head = n;
}

void DeleteNode(node *&head, int x)
{
    node *tmp = head;
    if (head->data == x)
    {
        while (tmp->next != head)
        {
            tmp = tmp->next;
        }

        tmp->next = head->next;
        node *del = head;
        head = head->next;

        free(del);
        return;
    }

    while (tmp->next->data != x)
    {
        tmp = tmp->next;
    }

    node *del = tmp->next;

    tmp->next = tmp->next->next;

    free(del);
}

void Print(node *head)
{
    node *tmp = head;

    cout << "HEAD->";
    do
    {
        cout << tmp->data << "->";
        tmp = tmp->next;
    } while (tmp != head);
    cout << "HEAD" << endl;
}

int main()
{
    system("clear");

    node *head = NULL;
    for (int i = 1; i <= 5; i++)
    {
        Append(head, i);
    }
    Print(head);
    for (int i = 6; i <= 10; i++)
    {
        Push(head, i);
    }
    Print(head);
    DeleteNode(head, 10);
    DeleteNode(head, 1);
    DeleteNode(head, 5);
    Print(head);
}