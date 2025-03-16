#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

struct node
{
    int key;
    node *next;
    node *prev;
};

node *head;

node *makenode(int);
void insert(int);
void delete(int);
void deleteFirst();
void deleteLast();

int main()
{
    int i, n, a;
    char op[16];
    node *x;
    
    head = makenode(0);
    head->next = head;
    head->prev = head;
    
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> op;
        if(strcmp(op, "insert") == 0)
        {
            cin >> a;
            insert(a);
        }
        else if(strcmp(op, "delete") == 0)
        {
            cin >> a;
            delete(a);
        }
        else if(strcmp(op, "deleteFirst") == 0)
        {
            deleteFirst();
        }
        else if(strcmp(op, "deleteLast") == 0)
        {
            deleteLast();
        }
    }
    
    x = head;
    while(x->next!= head)
    {
        cout << x->next->key;
        x = x->next;
        if(x->next!= head)
        {
            cout << " ";
        }
    }
    cout << "\n";

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
void delete(int a)
{
    node *x;
    x = head;
    
    while(x->next!= head)
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

