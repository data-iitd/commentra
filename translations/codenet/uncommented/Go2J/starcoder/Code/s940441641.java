package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		int H = nextInt();
		int W = nextInt();
		int K = nextInt();
		int x1 = nextInt() - 1;
		int y1 = nextInt() - 1;
		int x2 = nextInt() - 1;
		int y2 = nextInt() - 1;
		char[][] c = new char[H][W];
		for (int y = 0; y < H; y++) {
			String s = next();
			for (int x = 0; x < W; x++) {
				c[y][x] = s.charAt(x);
			}
		}
		int[] dx = new int[]{1, 0, -1, 0};
		int[] dy = new int[]{0, 1, 0, -1};
		int[][] dist = new int[H * W * 4][W * H * 4];
		for (int i = 0; i < W * H * 4; i++) {
			Arrays.fill(dist[i], Integer.MAX_VALUE);
		}
		PriorityQueue<State> q = new PriorityQueue<State>();
		for (int i = 0; i < 4; i++) {
			q.offer(new State(0, toID(x1, y1, i)));
		}
		while (!q.isEmpty()) {
			State now = q.poll();
			int x = now.id / (H * W);
			int y = now.id / W % H;
			int dir = now.id % 4;
			if (c[y][x] == '@') {
				continue;
			}
			if (dist[now.id][now.id] <= now.cost) {
				continue;
			}
			dist[now.id][now.id] = now.cost;
			if (x == x2 && y == y2) {
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nCost = (now.cost + K - 1) / K * K;
				int nID = toID(x, y, i);
				if (dist[nID][nID] <= nCost) {
					continue;
				}
				q.offer(new State(nCost, nID));
			}
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (0 <= nx && nx < W && 0 <= ny && ny < H) {
				int nCost = now.cost + 1;
				int nID = toID(nx, ny, dir);
				if (dist[nID][nID] <= nCost) {
					continue;
				}
				q.offer(new State(nCost, nID));
			}
		}
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < 4; i++) {
			int id = toID(x2, y2, i);
			if (dist[id][id] < ans) {
				int d2 = (dist[id][id] + K - 1) / K;
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

	static int toID(int x, int y, int dir) {
		return 4 * (W * y + x) + dir;
	}

	static int[] splatID(int id) {
		int x = id / 4 % W;
		int y = id / 4 / W;
		int dir = id % 4;
		return new int[]{x, y, dir};
	}

	static class State implements Comparable<State> {
		int cost, id;

		public State(int cost, int id) {
			this.cost = cost;
			this.id = id;
		}

		@Override
		public int compareTo(State o) {
			return this.cost - o.cost;
		}
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static String next() throws IOException {
		while (st == null ||!st.hasMoreTokens())
			st = new StringTokenizer(reader.readLine());
		return st.nextToken();
	}

	static String readLine() throws IOException {
		return reader.readLine();
	}

	static String nextLine() throws IOException {
		st = null;
		return reader.readLine();
	}

	static String[] readLines() throws IOException {
		return reader.readLine().split(" ");
	}

	static String[] nextLineTokens() throws IOException {
		st = null;
		return reader.readLine().split(" ");
	}

	static int[] readInts() throws IOException {
		String[] line = readLines();
		int[] arr = new int[line.length];
		for (int i = 0; i < line.length; i++) {
			arr[i] = Integer.parseInt(line[i]);
		}
		return arr;
	}

	static int[] nextTokensInt() throws IOException {
		st = null;
		String[] line = nextLineTokens();
		int[] arr = new int[line.length];
		for (int i = 0; i < line.length; i++) {
			arr[i] = Integer.parseInt(line[i]);
		}
		return arr;
	}

	static char[] nextTokensChar() throws IOException {
		st = null;
		String[] line = nextLineTokens();
		char[] arr = new char[line.length];
		for (int i = 0; i < line.length; i++) {
			arr[i] = line[i].charAt(0);
		}
		return arr;
	}

	static char[] readChars() throws IOException {
		String[] line = readLines();
		char[] arr = new char[line.length];
		for (int i = 0; i < line.length; i++) {
			arr[i] = line[i].charAt(0);
		}
		return arr;
	}

	static int nextIntToken() throws IOException {
		return Integer.parseInt(next());
	}

	static BufferedReader reader;
	static StringTokenizer st;
	static int[] dx = new int[]{1, 0, -1, 0};
	static int[] dy = new int[]{0, 1, 0, -1};
	static int INF = Integer.MAX_VALUE;
	static int[][] dist;
	static int H, W, K;
	static int x1, y1, x2, y2;
	static char[][] c;
}

