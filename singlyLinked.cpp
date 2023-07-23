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
        return;
    }

    node *tmp = head;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = n;
}

void push(node *&head, int x)
{
    node *n = new node(x);

    if (head == NULL)
    {
        head = n;
        return;
    }

    n->next = head;
    head = n;
}

void Print(node *head)
{
    if (head == NULL)
    {
        return;
    }

    node *tmp = head;

    cout << "HEAD->";
    while (tmp != NULL)
    {
        cout << tmp->data << "->";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}

void deleteNode(node *&head, int x)
{
    if (x == head->data)
    {
        node *del = head;
        head = head->next;
        free(del);
        return;
    }

    node *tmp = head;

    while (tmp->next->data != x)
    {
        tmp = tmp->next;
    }

    node *del = tmp->next;
    tmp->next = tmp->next->next;

    free(del);
}

node *SearchNode(node *head, int x)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *tmp = head;

    while (tmp != NULL)
    {
        if (tmp->data == x)
        {
            return tmp;
        }
        tmp = tmp->next;
    }

    return NULL;
}

void InsertNodeAfter(node *&head, int x, int j)
{
    if (head == NULL)
    {
        return;
    }

    node *n = new node(x);

    node *tmp = head;

    while (tmp->data != j)
    {
        tmp = tmp->next;
    }

    n->next = tmp->next;
    tmp->next = n;
}

int main()
{
    system("clear");

    node *head = NULL;

    for (int i = 1; i <= 5; i++)
    {
        Append(head, i);
    }
    for (int i = 6; i <= 10; i++)
    {
        push(head, i);
    }

    Print(head);

    deleteNode(head, 1);
    deleteNode(head, 10);
    deleteNode(head, 5);
    Print(head);
    InsertNodeAfter(head, 5, 4);
    Print(head);

    // node *d = SearchNode(head, 2);
    // cout << d->data;
}