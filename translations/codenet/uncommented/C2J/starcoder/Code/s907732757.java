
import java.util.*;

public class Main
{
    static node head;
    
    static class node
    {
        int key;
        node next;
        node prev;
    }
    
    static node makenode(int a)
    {
        node x;
        x = new node();
        x.key = a;
        return x;
    }
    static void insert(int a)
    {
        node x;
        x = makenode(a);
        x.next = head.next;
        head.next.prev = x;
        head.next = x;
        x.prev = head;
    }
    static void delete(int a)
    {
        node x;
        x = head;
        
        while(x.next!= head)
        {
            x = x.next;
            if(x.key == a)
            {
                x.prev.next = x.next;
                x.next.prev = x.prev;
                free(x);
                break;
            }
        }
    }
    static void deleteFirst()
    {
        node x;
        x = head.next;
        head.next = x.next;
        x.next.prev = head;
        free(x);
    }
    static void deleteLast()
    {
        node x;
        x = head.prev;
        head.prev = x.prev;
        x.prev.next = head;
        free(x);
    }
    
    public static void main(String[] args)
    {
        int i, n, a;
        String op;
        node x;
        
        head = makenode(0);
        head.next = head;
        head.prev = head;
        
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(i=0; i<n; i++)
        {
            op = sc.next();
            if(op.equals("insert"))
            {
                a = sc.nextInt();
                insert(a);
            }
            else if(op.equals("delete"))
            {
                a = sc.nextInt();
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
        while(x.next!= head)
        {
            System.out.print(x.next.key);
            x = x.next;
            if(x.next!= head)
            {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}

