
import java.util.*;
import java.io.*;

class s108384974{
  static class Node{
    int key;
    Node p,l,r;
    Node(int key){
      this.key = key;
      p = l = r = null;
    }
  }

  static Node r,nil;

  static Node find(Node x,int k){
    while(x!= nil && k!= x.key){
      if(k < x.key){
        x = x.l;
      }else{
        x = x.r;
      }
    }
    return x;
  }

  static void insert(int k){
    Node y = nil;
    Node x = r;

    Node z = new Node(k);

    while(x!= nil){
      y = x;
      if(z.key < x.key){
        x = x.l;
      }else{
        x = x.r;
      }
    }
    z.p = y;

    if(y == nil){
      r = z;
    }else if(z.key < y.key){
      y.l = z;
    }else{
      y.r = z;
    }
  }

  static void inorder(Node u){
    if(u == nil){
      return;
    }
    inorder(u.l);
    System.out.print(" "+u.key);
    inorder(u.r);
  }

  static void preorder(Node u){
    if(u == nil){
      return;
    }
    System.out.print(" "+u.key);
    preorder(u.l);
    preorder(u.r);
  }

  static void print(){
    inorder(r);
    System.out.println("");
    preorder(r);
    System.out.println("");
  }

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    for(int i=0;i<n;i++){
      String[] s = br.readLine().split(" ");
      if(s[0].charAt(0) == 'f'){
        int x = Integer.parseInt(s[1]);
        Node t = find(r,x);
        if(t == nil)System.out.println("no");
        else System.out.println("yes");
      }else if(s[0].charAt(0) == 'i'){
        int z = Integer.parseInt(s[1]);
        insert(z);
      }else{
        print();
      }
    }
  }
}
