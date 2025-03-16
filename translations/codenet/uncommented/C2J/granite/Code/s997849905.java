
import java.util.*;
import java.io.*;

class s997849905 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    Node head = new Node();
    head.next = head;
    head.prev = head;
    for (int i = 0; i < n; i++) {
      String[] com = br.readLine().split(" ");
      if (com[0].equals("insert")) {
        int key = Integer.parseInt(com[1]);
        insert(head, key);
      } else if (com[0].equals("deleteFirst")) {
        deleteFirst(head);
      } else if (com[0].equals("deleteLast")) {
        deleteLast(head);
      } else {
        int key = Integer.parseInt(com[1]);
        delete(head, key);
      }
    }
    printList(head);
  }

  static class Node {
    int key;
    Node next;
    Node prev;
  }

  static void init(Node head) {
    head.next = head;
    head.prev = head;
  }

  static void printList(Node head) {
    Node cur = head.next;
    boolean first = true;
    while (cur!= head) {
      if (!first) {
        System.out.print(" ");
      }
      System.out.print(cur.key);
      cur = cur.next;
      first = false;
    }
    System.out.println();
  }

  static void deleteFirst(Node head) {
    Node t = head.next;
    head.next = t.next;
    t.next.prev = head;
  }

  static void deleteLast(Node head) {
    Node delnode = head.prev;
    head.prev = delnode.prev;
    delnode.prev.next = head;
    delnode = null;
  }

  static void delete(Node head, int skey) {
    boolean judge = false;
    Node t = null;
    Node n = head.next;
    while (n!= head) {
      if (n.key == skey) {
        judge = true;
      }
      n = n.next;
    }
    if (judge) {
      n = head.next;
      while (n!= head) {
        if (n.key == skey) {
          break;
        }
        n = n.next;
      }
      t = n.prev;
      t.next = n.next;
      t.next.prev = t;
      n = null;
    }
  }

  static void insert(Node head, int skey) {
    Node newnode = new Node();
    newnode.key = skey;
    if (head.next == head) {
      newnode.next = head;
      head.next = newnode;
      newnode.prev = head;
      head.prev = newnode;
    } else {
      newnode.next = head.next;
      head.next.prev = newnode;
      head.next = newnode;
      newnode.prev = head;
    }
  }
}

