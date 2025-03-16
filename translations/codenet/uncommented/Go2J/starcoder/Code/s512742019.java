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
		Queue<Node> q = new LinkedList<>();
		int ans = 0;
		int total = 0;
		for (int i = 0; i < N; i++) {
			Mon m = M[i];
			while (!q.isEmpty() && q.peek().x < m.x) {
				total -= q.poll().h;
			}
			if (total < m.h) {
				m.h -= total;
				int count = (m.h + A - 1) / A;
				ans += count;
				int damage = count * A;
				q.offer(new Node(m.x + 2 * D, damage));
				total += damage;
			}
		}
		wtr.write(ans + "\n");
		wtr.close();
	}

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

	static class Node {
		int x, h;

		public Node(int x, int h) {
			this.x = x;
			this.h = h;
		}
	}
}

