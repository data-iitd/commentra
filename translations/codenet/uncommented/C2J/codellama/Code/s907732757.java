#include<stdio.h>
#include<stdlib.h>
#include<string.h>

class Node
{
    int key;
    Node next;
    Node prev;
    
    Node(int a)
    {
        key = a;
    }
}

Node head;

Node makenode(int a)
{
    Node x = new Node(a);
    return x;
}
void insert(int a)
{
    Node x = makenode(a);
    x.next = head.next;
    head.next.prev = x;
    head.next = x;
    x.prev = head;
}
void delete(int a)
{
    Node x = head;
    
    while(x.next != head)
    {
        x = x.next;
        if(x.key == a)
        {
            x.prev.next = x.next;
            x.next.prev = x.prev;
            break;
        }
    }
}
void deleteFirst()
{
    Node x = head.next;
    head.next = x.next;
    x.next.prev = head;
}
void deleteLast()
{
    Node x = head.prev;
    head.prev = x.prev;
    x.prev.next = head;
}

int main()
{
    int i, n, a;
    String op;
    Node x;
    
    head = makenode(0);
    head.next = head;
    head.prev = head;
    
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s", op);
        if(op.equals("insert"))
        {
            scanf("%d", &a);
            insert(a);
        }
        else if(op.equals("delete"))
        {
            scanf("%d", &a);
            delete(a);
        }
        else if(op.equals("deleteFirst"))
        {
            deleteFirst();
        }
        else if(op.equals("deleteLast"))
        {
            deleteLast();
        }
    }
    
    x = head;
    while(x.next != head)
    {
        System.out.print(x.next.key);
        x = x.next;
        if(x.next != head)
        {
            System.out.print(" ");
        }
    }
    System.out.println();

    return 0;
}

