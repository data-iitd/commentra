
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Node head = new Node();
        Node tail = new Node();
        head.next = tail;
        tail.prev = head;
        for(int i = 0; i < n; i++){
            String com = in.next();
            if(com.equals("insert")){
                int key = in.nextInt();
                insert(head, tail, key);
            }
            else if(com.equals("deleteFirst"))
                deleteFirst(head, tail);
            else if(com.equals("deleteLast"))
                deleteLast(head, tail);
            else{
                int key = in.nextInt();
                delete(head, tail, key);
            }
        }
        printList(head, tail);
    }
    static void insert(Node head, Node tail, int key){
        Node new = new Node();
        new.key = key;
        if(head.next == tail){
            new.next = tail;
            tail.prev = new;
            new.prev = head;
            head.next = new;
        }
        else{
            new.next = head.next;
            head.next.prev = new;
            new.prev = head;
            head.next = new;
        }
    }
    static void deleteFirst(Node head, Node tail){
        Node delnode = head.next;
        head.next = delnode.next;
        delnode.next.prev = head;
        delnode.next = null;
        delnode.prev = null;
        delnode = null;
    }
    static void deleteLast(Node head, Node tail){
        Node delnode = tail.prev;
        tail.prev = delnode.prev;
        delnode.prev.next = tail;
        delnode.next = null;
        delnode.prev = null;
        delnode = null;
    }
    static void delete(Node head, Node tail, int key){
        Node n = head.next;
        while(n!= tail){
            if(n.key == key){
                break;
            }
            n = n.next;
        }
        if(n!= tail){
            Node t = n.prev;
            t.next = n.next;
            t.next.prev = t;
            n.next = null;
            n.prev = null;
            n = null;
        }
    }
    static void printList(Node head, Node tail){
        Node n = head.next;
        while(n!= tail){
            System.out.print(n.key + " ");
            n = n.next;
        }
        System.out.println();
    }
}
class Node{
    int key;
    Node next;
    Node prev;
}
