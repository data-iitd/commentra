
import java.util.Scanner;

class Node{
  int key;
  Node next;
  Node prev;
}

public class s719593355{
  static Node nil;
  static int np = 0, nd = 0;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    init();
    for (int i = 0;i < n;i++){
      String com = sc.next();
      int key = sc.nextInt();
      if (com.equals("insert")) {
	insert(key); np++;
      }
      else if (com.equals("delete")) {
	delete(key); nd++;
      }
    }
    printList();
  }

  public static Node listSearch(int key){
    Node cur = nil.next;
    while (cur!= nil && cur.key!= key)
      cur = cur.next;
    return cur;
  }

  public static void init(){
    nil = new Node();
    nil.next = nil;
    nil.prev = nil;
  }

  public static void printList(){
    Node cur = nil.next;
    boolean isf = true;
    while(1){
      if ( cur == nil ) break;
      if ( isf == false)  System.out.print(" ");
      System.out.print(cur.key);
      cur = cur.next;
      isf = false;
    }
    System.out.println();
  }

  public static void deleteNode(Node t){
    t.prev.next = t.next;
    t.next.prev = t.prev;
  }

  public static void deleteFirst(){
    Node t = nil.next;
    if ( t == nil )
      return;
    deleteNode(t);
  }

  public static void deleteLast(){
    Node t = nil.prev;
    if (t == nil)
      return;
    deleteNode(t);
  }

  public static void delete(int key){
    Node t = listSearch(key);
    if (t == nil)
      return;
    deleteNode(t);
  }

  public static void insert(int key){
    Node x = new Node();
    x.key = key;
    x.next = nil.next;
    nil.next.prev = x;
    nil.next = x;
    x.prev = nil;
  }
}
