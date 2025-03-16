import java.io.*;
import java.util.*;

// Include headers for input/output operations.

class FastReader {
	BufferedReader br;
	StringTokenizer st;

	public FastReader() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	String next() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(next());
	}

	long nextLong() {
		return Long.parseLong(next());
	}

	double nextDouble() {
		return Double.parseDouble(next());
	}

	String nextLine() {
		String str = "";
		try {
			str = br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return str;
	}
}

// FastReader class to read input efficiently.

class Node {
	int data;
	Node next;

	public Node(int data) {
		this.data = data;
		this.next = null;
	}
}

// Node class to store data in a linked list.

class LinkedList {
	Node head;
	Node tail;
	int size;

	public LinkedList() {
		this.head = null;
		this.tail = null;
		this.size = 0;
	}

	public int size() {
		return this.size;
	}

	public void addLast(int data) {
		Node node = new Node(data);
		if (this.size == 0) {
			this.head = node;
			this.tail = node;
		} else {
			this.tail.next = node;
			this.tail = node;
		}
		this.size++;
	}

	public int removeFirst() {
		if (this.size == 0) {
			return -1;
		}
		int data = this.head.data;
		this.head = this.head.next;
		this.size--;
		return data;
	}
}

// LinkedList class to store data in a linked list.

class UnionFind {
	int[] fa;
	int[] v;

	public UnionFind(int n) {
		this.fa = new int[n + 1];
		this.v = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			this.fa[i] = i;
		}
	}

	public int get(int x) {
		if (this.fa[x] == x) {
			return x;
		}
		int f = get(this.fa[x]);
		this.v[x] += this.v[this.fa[x]];
		this.fa[x] = f;
		return f;
	}

	public void union(int l, int r, int vi) {
		int li = get(l);
		int ri = get(r);
		if (li != ri) {
			this.v[ri] = vi - this.v[r] + this.v[l];
			this.fa[ri] = li;
		} else {
			if (this.v[r] - this.v[l] != vi) {
				System.out.println("No");
				System.exit(0);
			}
		}
	}
}

// UnionFind class to implement union-find structure and value updates.

public class Main {
	public static void main(String[] args) {
		FastReader sc = new FastReader();
		int n = sc.nextInt();
		int m = sc.nextInt();
		UnionFind uf = new UnionFind(n);
		for (int i = 1; i <= m; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			int vi = sc.nextInt();
			uf.union(l, r, vi);
		}
		System.out.println("Yes");
	}
}

// Main class to execute the union-find structure and value updates.

