
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int key;
    node *next;
    node *prev;
};

node *head;

node *makenode(int a)
{
    node *x;
    x = new node;
    x->key = a;
    return x;
}

void init()
{
    if(head == NULL)
    {
        head = makenode(0);
        head->next = head;
        head->prev = head;
    }
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
    node *x, *prev;
    x = head;
    
    while(x->next!= head)
    {
        x = x->next;
        if(x->key == a)
        {
            prev = x->prev;
            prev->next = x->next;
            x->next->prev = prev;
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
    node *x, *prev;
    x = head;
    
    while(x->next!= head)
    {
        x = x->next;
    }
    
    prev = x->prev;
    
    prev->next = NULL;
    head->prev = prev;
    
    delete x;
}

int main()
{
    int i, n, a;
    char op[16];
    node *x;
    
    init();
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++)
    {
        scanf("%s", op);
        
        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &a);
            insert(a);
        }
        else if(strcmp(op, "delete") == 0)
        {
            scanf("%d", &a);
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
        printf("%d ", x->next->key);
        x = x->next;
    }
    
    printf("\n");

    return 0;
}

