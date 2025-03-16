package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		BufferedWriter wtr = new BufferedWriter(new OutputStreamWriter(System.out));
		int N = sc.nextInt();
		int D = sc.nextInt();
		int A = sc.nextInt();
		Mon[] M = new Mon[N];
		for (int i = 0; i < N; i++) {
			M[i] = new Mon(sc.nextInt(), sc.nextInt());
		}
		Arrays.sort(M);
		Queue q = new Queue();
		int ans = 0;
		int total = 0;
		for (int i = 0; i < N; i++) {
			Mon m = M[i];
			while (!q.isEmpty() && q.first().x < m.x) {
				total -= q.pop().h;
			}
			if (total < m.h) {
				m.h -= total;
				int count = (m.h + A - 1) / A;
				ans += count;
				int damage = count * A;
				q.push(new Node(m.x + 2 * D, damage));
				total += damage;
			}
		}
		wtr.write(ans + "\n");
		wtr.close();
	}

	// I/O
	// Scanner struct to handle input reading
	static class Scanner {
		BufferedReader br;
		StringTokenizer st;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public String next() throws IOException {
			while (st == null ||!st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
	}

	// Arithmetic
	// max returns the maximum value from a list of integers
	static int max(int... nums) {
		int m = nums[0];
		for (int i : nums) {
			if (m < i) {
				m = i;
			}
		}
		return m;
	}

	// min returns the minimum value from a list of integers
	static int min(int... nums) {
		int m = nums[0];
		for (int i : nums) {
			if (m > i) {
				m = i;
			}
		}
		return m;
	}

	// abs returns the absolute value of an integer
	static int abs(int x) {
		if (x > 0) {
			return x;
		}
		return -x;
	}

	// pow calculates x raised to the power of y
	static int pow(int x, int y) {
		int res = 1;
		for (int i = 0; i < y; i++) {
			res *= x;
		}
		return res;
	}

	// ceil calculates the ceiling of a/b
	static int ceil(int a, int b) {
		if (a % b == 0) {
			return a / b;
		} else {
			return a / b + 1;
		}
	}

	// Sort
	// Mon represents a monster with position x and health h
	static class Mon implements Comparable<Mon> {
		int x, h;

		public Mon(int x, int h) {
			this.x = x;
			this.h = h;
		}

		@Override
		public int compareTo(Mon o) {
			return this.x - o.x;
		}
	}

	// Mons is a slice of Mon for sorting
	static class Mons extends Mon implements Comparable<Mons> {
		public Mons(int x, int h) {
			super(x, h);
		}
	}

	// Node represents a position and damage
	static class Node {
		int x, h;

		public Node(int x, int h) {
			this.x = x;
			this.h = h;
		}
	}

	// Queue is a simple queue implementation for Nodes
	static class Queue {
		Node[] arr;

		public Queue() {
			arr = new Node[100000];
		}

		// push adds a Node to the end of the queue
		public void push(Node v) {
			arr[arr.length - 1] = v;
		}

		// first returns the first Node in the queue without removing it
		public Node first() {
			return arr[0];
		}

		// pop removes and returns the first Node in the queue
		public Node pop() {
			Node res = arr[0];
			for (int i = 0; i < arr.length - 1; i++) {
				arr[i] = arr[i + 1];
			}
			return res;
		}

		// isEmpty checks if the queue is empty
		public boolean isEmpty() {
			return arr.length == 0;
		}
	}
}

