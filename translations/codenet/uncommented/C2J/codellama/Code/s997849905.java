
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
class Node{
  int key;
  Node next;
  Node prev;
};
 
class List{
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
      if ( snl == 0)  printf(" ");
      printf("%d", cur.key);
      cur = cur.next;
      snl = 0;
    }
    printf("\n");
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
    free(delnode);
  }
 
  void delete(int skey){
    int judge = 0;
    Node t;
    Node n; 
 
    for(n = N.next;n != N;n = n.next){
      if(n.key == skey){
        judge = 1;
      }
    }
 
    if(judge == 1){
      n = N.next;
      while(n != N){
        if(n.key == skey)
          break;
        n=n.next;
      }
      t = n.prev;
      t.next = n.next;
      t.next.prev = t;
      free(n);
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
 
  void main(){
    int key, n, i;
    String com;
    scanf("%d", &n);
    init();
    for ( i = 0; i < n; i++ ){
      scanf("%s",com);
      if(com.equals("insert")){
        scanf("%d",&key);
        insert(key);
      }
      else if(com.equals("deleteFirst"))
        deleteFirst();
      else if(com.equals("deleteLast"))
        deleteLast();
      else{
        scanf("%d",&key);
        delete(key);
      }
    }
    printList();
  }
}

