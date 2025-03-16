
import java.util.Scanner;

class Node{
  int key;
  Node next;
  Node prev;
}

class LinkedList{
  Node N;

  void init(){
    N = new Node();
    N.next = N;
    N.prev = N;
  }

  void printList(){
    Node cur = N.next;
    int snl = 1;
    while(cur != N){
      if ( snl == 0)
        System.out.print(" ");
      System.out.print(cur.key);
      cur = cur.next;
      snl = 0;
    }
    System.out.println();
  }

  void deleteFirst(){
    Node t = N.next;
    N.next = t.next;
    t.next.prev = N;
  }

  void deleteLast(){
    Node delnode = N.prev;
    N.prev = delnode.prev;
    delnode.prev.next = N;
  }

  void delete(int skey){
    int judge = 0;
    Node t, n;

    for(n = N.next;n != N;n = n.next){
      if(n.key == skey){
        judge = 1;
        break;
      }
    }

    if(judge == 1){
      n = N.next;
      t = n.prev;
      t.next = n.next;
      t.next.prev = t;
    }
  }

  void insert(int skey){
    Node new;
    static int count = 0;

    new = new Node();
    new.key = skey;

    if(count == 0){
      new.next = N;
      N.next = new;
      new.prev = N;
      N.prev = new;
      count++;
    }

    else{
      new.next = N.next;
      N.next.prev = new;
      N.next = new;
      new.prev = N;
      count++;
    }
  }

  public static void main(String[] args){
    int key, n, i;
    String com;

    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    LinkedList ll = new LinkedList();
    ll.init();

    for ( i = 0; i < n; i++ ){
      com = sc.next();
      if(com.equals("insert")){
        key = sc.nextInt();
        ll.insert(key);
      }
      else if(com.equals("deleteFirst"))
        ll.deleteFirst();
      else if(com.equals("deleteLast"))
        ll.deleteLast();
      else{
        key = sc.nextInt();
        ll.delete(key);
      }
    }
    ll.printList();
  }
}

