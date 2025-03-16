
#include<iostream>
#include<string>

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
void deleteKey(int);
void deleteFirst();
void deleteLast();

int main()
{
    int i, n, a;
    string op;
    node *x;
    
    head = madeNode(0);
    head->next = head;
    head->prev = head;
    
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> op;
        if(op == "insert")
        {
            cin >> a;
            insert(a);
        }
        else if(op == "delete")
        {
            cin >> a;
            deleteKey(a);
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
    while(x->next!= head)
    {
        cout << x->next->key << " ";
        x = x->next;
    }
    cout << endl;

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
    x = madeNode(a);
    x->next = head->next;
    head->next->prev = x;
    head->next = x;
    x->prev = head;
}
void deleteKey(int a)
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

