#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int x)
    {
        data = x;
        prev = NULL;
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
    n->prev = tmp;
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
    head->prev = n;

    head = n;
}

void Print(node *head)
{
    node *tmp = head;

    cout << "HEAD->";
    while (tmp != NULL)
    {
        cout << tmp->data << "->";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}

void DeleteNode(node *&head, int x)
{
    if (head->data == x)
    {
        node *del = head;
        head = head->next;
        head->prev = NULL;
        free(del);
        return;
    }

    node *tmp = head;

    while (tmp->data != x)
    {
        tmp = tmp->next;
    }

    if (tmp->next == NULL)
    {
        tmp->prev->next = NULL;
        free(tmp);
        return;
    }

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;

    free(tmp);
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
    DeleteNode(head, 10);
    DeleteNode(head, 1);
    DeleteNode(head, 5);
    Print(head);
    node *s = SearchNode(head, 2);
    cout << s->data;
}