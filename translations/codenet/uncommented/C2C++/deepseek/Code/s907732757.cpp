#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

struct node
{
    int key;
    node *next;
    node *prev;
};

node *head;

node *makenode(int);
void insert(int);
void deleteNode(int);
void deleteFirst();
void deleteLast();

int main()
{
    int i, n, a;
    std::string op;
    node *x;
    
    head = makenode(0);
    head->next = head;
    head->prev = head;
    
    std::cin >> n;
    for(i = 0; i < n; i++)
    {
        std::cin >> op;
        if(op == "insert")
        {
            std::cin >> a;
            insert(a);
        }
        else if(op == "delete")
        {
            std::cin >> a;
            deleteNode(a);
        }
        else if(op == "deleteFirst")
        {
            deleteFirst();
        }
        else if(op == "deleteLast")
        {
            deleteLast();
        }
    }
    
    x = head;
    while(x->next != head)
    {
        std::cout << x->next->key;
        x = x->next;
        if(x->next != head)
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

node *makenode(int a)
{
    node *x;
    x = new node;
    x->key = a;
    return x;
}
void insert(int a)
{
    node *x;
    x = makenode(a);
    x->next = head->next;
    head->next->prev = x;
    head->next = x;
    x->prev = head;
}
void deleteNode(int a)
{
    node *x;
    x = head;
    
    while(x->next != head)
    {
        x = x->next;
        if(x->key == a)
        {
            x->prev->next = x->next;
            x->next->prev = x->prev;
            delete x;
            break;
        }
    }
}
void deleteFirst()
{
    node *x;
    x = head->next;
    head->next = x->next;
    x->next->prev = head;
    delete x;
}
void deleteLast()
{
    node *x;
    x = head->prev;
    head->prev = x->prev;
    x->prev->next = head;
    delete x;
}

