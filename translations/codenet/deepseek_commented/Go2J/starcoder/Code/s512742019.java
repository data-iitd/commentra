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

	// Arithmetic functions including max, min, absolute value, power, and ceiling.
	static int max(int... nums) {
		int m = nums[0];
		for (int i : nums) {
			if (m < i) {
				m = i;
			}
		}
		return m;
	}

	static int min(int... nums) {
		int m = nums[0];
		for (int i : nums) {
			if (m > i) {
				m = i;
			}
		}
		return m;
	}

	static int abs(int x) {
		if (x > 0) {
			return x;
		}
		return -x;
	}

	static int pow(int x, int y) {
		int res = 1;
		for (int i = 0; i < y; i++) {
			res *= x;
		}
		return res;
	}

	static int ceil(int a, int b) {
		if (a % b == 0) {
			return a / b;
		} else {
			return a / b + 1;
		}
	}

	// Custom type Mon to implement Comparable for sorting monsters.
	static class Mon implements Comparable<Mon> {
		int x, h;

		Mon(int x, int h) {
			this.x = x;
			this.h = h;
		}

		@Override
		public int compareTo(Mon o) {
			return this.x - o.x;
		}
	}

	// Custom type Node to implement Comparable for sorting nodes.
	static class Node implements Comparable<Node> {
		int x, h;

		Node(int x, int h) {
			this.x = x;
			this.h = h;
		}

		@Override
		public int compareTo(Node o) {
			return this.x - o.x;
		}
	}

	// Custom type Queue to manage a queue of nodes.
	// Methods include pushing, popping, and checking if the queue is empty.
	static class Queue {
		Node[] arr;

		Queue() {
			arr = new Node[0];
		}

		void push(Node v) {
			arr = Arrays.copyOf(arr, arr.length + 1);
			arr[arr.length - 1] = v;
		}

		Node first() {
			return arr[0];
		}

		Node pop() {
			Node res = arr[0];
			arr = Arrays.copyOfRange(arr, 1, arr.length);
			return res;
		}

		boolean isEmpty() {
			return arr.length == 0;
		}
	}
}

