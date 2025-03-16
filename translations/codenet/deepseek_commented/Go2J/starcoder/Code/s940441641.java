package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		int H = ReadInt();
		int W = ReadInt();
		int K = ReadInt();
		int x1 = ReadInt() - 1;
		int y1 = ReadInt() - 1;
		int x2 = ReadInt() - 1;
		int y2 = ReadInt() - 1;
		String[] c = new String[H];
		for (int y = 0; y < H; y++) {
			c[y] = ReadString();
		}
		int[] dx = new int[]{1, 0, -1, 0};
		int[] dy = new int[]{0, 1, 0, -1};
		int toID(int x, int y, int dir) {
			return 4 * (W * y + x) + dir;
		}
		int splatID(int id) {
			return id / 4 % W, id / 4 / W, id % 4;
		}
		int[] dist = new int[W * H * 4];
		for (int i = 0; i < W * H * 4; i++) {
			dist[i] = Integer.MAX_VALUE;
		}
		PriorityQueue<State> q = new PriorityQueue<State>(Comparator.comparingInt(a -> a.cost));
		for (int i = 0; i < 4; i++) {
			q.add(new State(0, toID(x1, y1, i)));
		}
		while (!q.isEmpty()) {
			State now = q.poll();
			int x = splatID(now.id)[0];
			int y = splatID(now.id)[1];
			int dir = splatID(now.id)[2];
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

	static class State {
		int cost, id;

		public State(int cost, int id) {
			this.cost = cost;
			this.id = id;
		}
	}

	static int ReadInt() throws IOException {
		return Integer.parseInt(next());
	}

	static String next() throws IOException {
		while (st == null ||!st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	static int[] ReadInts(int N) throws IOException {
		int[] a = new int[N];
		for (int i = 0; i < N; i++)
			a[i] = ReadInt();
		return a;
	}

	static String ReadString() throws IOException {
		return br.readLine();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
}

