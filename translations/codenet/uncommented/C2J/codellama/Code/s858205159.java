#include<stdio.h>
#include<stdlib.h>
#include<string.h>

class Node{
	int key;
	Node next;
	Node prev;
	public Node(int key){
		this.key = key;
		this.next = null;
		this.prev = null;
	}
}

class List{
	Node nil;
	public List(){
		nil = new Node(0);
		nil.next = nil;
		nil.prev = nil;
	}

	public Node listSearch(int key){
		Node cur = nil.next;
		while (cur != nil) {
			if (cur.key == key) break;
			cur = cur.next;
		}
		return cur;
	}

	public void printList(){
		Node cur = nil.next;
		int isf = 1;
		while (1){
			if (cur == nil) break;
			if (isf == 0)  System.out.print(" ");
			System.out.print(cur.key);
			cur = cur.next;
			isf = 0;
		}
		System.out.println();
	}

	public void deleteNode(Node t){
		if (t == nil) return;
		t.prev.next = t.next;
		t.next.prev = t.prev;
		t = null;
	}

	public void deleteFirst(){
		Node t = nil.next;
		if (t == nil) return;
		deleteNode(t);
	}

	public void deleteLast(){
		Node t = nil.prev;
		if (t == nil) return;
		deleteNode(t);
	}

	public void deleteKey(int key){
		Node t = listSearch(key);
		if (t != nil) deleteNode(t);
	}


	public void insert(int key){
		Node x;
		x = new Node(key);
		x.prev = nil;
		x.next = nil.next;
		x.next.prev = x;
		nil.next = x;
	}

	public static void main(String[] args){
		int key, n, i;
		int size = 0;
		String com;
		int np = 0, nd = 0;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		List list = new List();
		for (i = 0; i < n; i++){
			com = sc.next();
			key = sc.nextInt();
			if (com.equals("i")) { list.insert(key); np++; size++; }
			else if (com.equals("d")) {
				if (com.length() > 6){
					if (com.charAt(6) == 'F') list.deleteFirst();
					else if (com.charAt(6) == 'L') list.deleteLast();
				}
				else {
					list.deleteKey(key); nd++;
				}
				size--;
			}
		}

		list.printList();
	}
}

