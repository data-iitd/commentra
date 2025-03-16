package main;

import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int K = sc.nextInt();
		int x1 = sc.nextInt() - 1;
		int y1 = sc.nextInt() - 1;
		int x2 = sc.nextInt() - 1;
		int y2 = sc.nextInt() - 1;
		sc.nextLine();
		String[] c = new String[H];
		for (int y = 0; y < H; y++) {
			c[y] = sc.nextLine();
		}
		int[] dx = new int[] { 1, 0, -1, 0 };
		int[] dy = new int[] { 0, 1, 0, -1 };
		int[] dist = new int[W * H * 4];
		Arrays.fill(dist, Integer.MAX_VALUE);
		PriorityQueue<State> q = new PriorityQueue<State>();
		for (int i = 0; i < 4; i++) {
			q.add(new State(0, toID(x1, y1, i)));
		}
		while (!q.isEmpty()) {
			State now = q.poll();
			int x = now.x;
			int y = now.y;
			int dir = now.dir;
			if (c[y].charAt(x) == '@') {
				continue;
			}
			if (dist[now.id] <= now.cost) {
				continue;
			}
			dist[now.id] = now.cost;
			if (x == x2 && y == y2) {
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nCost = (now.cost + K - 1) / K * K;
				int nID = toID(x, y, i);
				if (dist[nID] <= nCost) {
					continue;
				}
				q.add(new State(nCost, nID));
			}
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (0 <= nx && nx < W && 0 <= ny && ny < H) {
				int nCost = now.cost + 1;
				int nID = toID(nx, ny, dir);
				if (dist[nID] <= nCost) {
					continue;
				}
				q.add(new State(nCost, nID));
			}
		}
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < 4; i++) {
			int id = toID(x2, y2, i);
			if (dist[id] < ans) {
				int d2 = (dist[id] + K - 1) / K;
				if (d2 < ans) {
					ans = d2;
				}
			}
		}
		if (ans < Integer.MAX_VALUE) {
			System.out.println(ans);
		} else {
			System.out.println(-1);
		}
	}

	static class State implements Comparable<State> {
		int cost;
		int id;
		int x;
		int y;
		int dir;

		public State(int cost, int id) {
			this.cost = cost;
			this.id = id;
			this.x = id / 4 % 4;
			this.y = id / 4 / 4;
			this.dir = id % 4;
		}

		@Override
		public int compareTo(State o) {
			return cost - o.cost;
		}
	}

	static int toID(int x, int y, int dir) {
		return 4 * (4 * y + x) + dir;
	}
}

