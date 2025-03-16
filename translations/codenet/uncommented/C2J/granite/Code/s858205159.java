
import java.util.Scanner;

class Node{
	int key;
	Node next;
	Node prev;
};

class s858205159{
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
		Node x = new Node();
		x.key = key;
		x.prev = nil;
		x.next = nil.next;
		x.next.prev = x;
		nil.next = x;
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int key, n, i;
		int size = 0;
		String com;
		int np = 0, nd = 0;
		n = sc.nextInt();
		init();
		for (i = 0; i < n; i++){
			com = sc.next();
			if (com.equals("insert")) { key = sc.nextInt(); insert(key); np++; size++; }
			else if (com.equals("delete")) {
				com = sc.next();
				if (com.equals("First")) deleteFirst();
				else if (com.equals("Last")) deleteLast();
				else {
					key = sc.nextInt();
					deleteKey(key); nd++;
				}
				size--;
			}
		}

		printList();
	}
}
