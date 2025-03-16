
import java.util.*;

public class Main {

	static class Node{
		int key;
		Node next;
		Node prev;
	}

	static Node nil;

	static Node listSearch(int key){
		Node cur = nil.next;
		while (cur!= nil) {
			if (cur.key == key) break;
			cur = cur.next;
		}
		return cur;
	}

	static void init(){
		nil = new Node();
		nil.next = nil;
		nil.prev = nil;
	}

	static void printList(){
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

	static void deleteNode(Node t){
		if (t == nil) return;
		t.prev.next = t.next;
		t.next.prev = t.prev;
		t = null;
	}

	static void deleteFirst(){
		Node t = nil.next;
		if (t == nil) return;
		deleteNode(t);
	}

	static void deleteLast(){
		Node t = nil.prev;
		if (t == nil) return;
		deleteNode(t);
	}

	static void deleteKey(int key){
		Node t = listSearch(key);
		if (t!= nil) deleteNode(t);
	}

	static void insert(int key){
		Node x;
		x = new Node();
		x.key = key;
		x.prev = nil;
		x.next = nil.next;
		x.next.prev = x;
		nil.next = x;
	}

	public static void main(String[] args) {
		int key, n, i;
		int size = 0;
		String com;
		int np = 0, nd = 0;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		init();
		for (i = 0; i < n; i++){
			com = sc.next();
			key = sc.nextInt();
			if (com.charAt(0) == 'i') { insert(key); np++; size++; }
			else if (com.charAt(0) == 'd') {
				if (com.length() > 6){
					if (com.charAt(6) == 'F') deleteFirst();
					else if (com.charAt(6) == 'L') deleteLast();
				}
				else {
					deleteKey(key); nd++;
				}
				size--;
			}
		}

		printList();
	}
}

