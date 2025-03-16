
package main

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());

		int[] rs = new int[R];
		for (int i = 0; i < R; i++) {
			rs[i] = Integer.parseInt(br.readLine()) - 1;
		}

		int[][] costs = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(costs[i], Integer.MAX_VALUE);
			costs[i][i] = 0;
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			int c = Integer.parseInt(st.nextToken());
			costs[a][b] = c;
			costs[b][a] = c;
		}

		// ワーシャルフロイド法で最短経路を算出
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					costs[i][j] = Math.min(costs[i][j], costs[i][k] + costs[k][j]);
				}
			}
		}

		// 順列で訪問先の順序をすべて試す
		// これでは重複して訪問する町がでてしまうか。。
		List<List<Integer>> perms = permutations(rs);
		int ans = Integer.MAX_VALUE;
		for (List<Integer> perm : perms) {
			int tmp = 0;
			for (int j = 1; j < perm.size(); j++) {
				int from = perm.get(j - 1);
				int to = perm.get(j);
				tmp += costs[from][to];
			}
			ans = Math.min(ans, tmp);
		}
		System.out.println(ans);
	}

	// permutations
	public static List<List<Integer>> permutations(int[] arr) {
		List<List<Integer>> res = new ArrayList<>();

		permutation(arr, 0, res);

		return res;
	}

	public static void permutation(int[] arr, int depth, List<List<Integer>> res) {
		if (depth == arr.length) {
			List<Integer> tmp = new ArrayList<>();
			for (int i : arr) {
				tmp.add(i);
			}
			res.add(tmp);
			return;
		}

		for (int i = depth; i < arr.length; i++) {
			swap(arr, i, depth);
			permutation(arr, depth + 1, res);
			swap(arr, i, depth);
		}
	}

	public static void swap(int[] arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	// Union-Find
	public static class UnionFind {
		private int[] d;

		public UnionFind(int n) {
			d = new int[n];
			for (int i = 0; i < n; i++) {
				d[i] = -1;
			}
		}

		public int find(int x) {
			if (d[x] < 0) {
				return x;
			}
			d[x] = find(d[x]);
			return d[x];
		}

		public boolean unite(int x, int y) {
			int rootX = find(x);
			int rootY = find(y);
			if (rootX == rootY) {
				return false;
			}

			if (d[rootX] < d[rootY]) {
				d[rootX] += d[rootY];
				d[rootY] = rootX;
			} else {
				d[rootY] += d[rootX];
				d[rootX] = rootY;
			}

			return true;
		}

		public boolean same(int x, int y) {
			return find(x) == find(y);
		}

		public int size(int x) {
			return -d[find(x)];
		}
	}

	// mod
	public static int modpow(int a, int n, int mod) {
		int res = 1;
		for (int i = 0; i < n; i++) {
			res = res * a % mod;
		}
		return res;
	}

	public static int modinv(int n, int mod) {
		return modpow(n, mod - 2, mod);
	}

	public static int modcomb(int n, int a, int mod) {
		int x = 1;
		int y = 1;
		for (int i = 0; i < a; i++) {
			x = x * (n - i) % mod;
			y = y * (i + 1) % mod;
		}
		return x * modpow(y, mod - 2, mod) % mod;
	}

	public static int modfactorial(int n, int mod) {
		int result = 1;
		for (int i = 1; i <= n; i++) {
			result = (result * i) % mod;
		}
		return result;
	}

	// Combination
	public static class Combination {
		private int[] facts;
		private int[] invs;
		private int mod;

		public Combination(int n, int mod) {
			facts = new int[n + 1];
			invs = new int[n + 1];
			this.mod = mod;
		}

		public int calc(int n, int k) {
			int ret = facts[n] * invs[k];
			ret %= mod;
			ret = ret * invs[n - k] % mod;
			return ret;
		}

		public void init(int n) {
			facts[0] = 1;
			// 階乗を算出
			for (int i = 1; i <= n; i++) {
				facts[i] = (facts[i - 1] * i) % mod;
			}
			// 逆元を算出
			invs[n] = modinv(facts[n], mod);
			for (int i = n - 1; i >= 0; i--) {
				invs[i] = (invs[i + 1] * (i + 1)) % mod;
			}
		}
	}

	// Utility
	public static int min(int x, int y) {
		if (x < y) {
			return x;
		}
		return y;
	}

	public static int max(int x, int y) {
		if (x > y) {
			return x;
		}
		return y;
	}

	public static int abs(int x) {
		if (x < 0) {
			return -x;
		}
		return x;
	}

	public static Map<Integer, Integer> primeFactor(int x) {
		Map<Integer, Integer> res = new HashMap<>();
		for (int i = 2; i * i <= x; i++) {
			while (x % i == 0) {
				res.put(i, res.getOrDefault(i, 0) + 1);
				x /= i;
			}
		}
		if (x != 1) {
			res.put(x, 1);
		}
		return res;
	}

	public static List<Integer> divisor(int x) {
		List<Integer> res = new ArrayList<>();
		for (int i = 1; i * i <= x; i++) {
			if (x % i == 0) {
				res.add(i);
				if (i != x / i) {
					res.add(x / i);
				}
			}
		}
		return res;
	}

	public static int gcd(int x, int y) {
		if (y == 0) {
			return x;
		}
		return gcd(y, x % y);
	}

	public static int lcm(int x, int y) {
		return x / gcd(x, y) * y;
	}

	public static String reverseString(String s) {
		char[] r = s.toCharArray();
		for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
			r[i] = s.charAt(j);
			r[j] = s.charAt(i);
		}
		return new String(r);
	}

	public static int pow(int a, int n) {
		int ret = 1;
		for (int i = 0; i < n; i++) {
			ret *= a;
		}
		return ret;
	}

	// Queue
	public static class Queue {
		private List<Integer> q = new ArrayList<>();

		public boolean empty() {
			return q.isEmpty();
		}

		public void push(int i) {
			q.add(i);
		}

		public int pop() {
			if (empty()) {
				return -1;
			} else {
				int res = q.get(0);
				q.remove(0);
				return res;
			}
		}
	}

	// Stack
	public static class Stack {
		private List<Integer> s = new ArrayList<>();

		public boolean empty() {
			return s.isEmpty();
		}

		public void push(int i) {
			s.add(i);
		}

		public int pop() {
			if (empty()) {
				return -1;
			} else {
				int res = s.get(s.size() - 1);
				s.remove(s.size() - 1);
				return res;
			}
		}
	}

	// priority_queue
	public static class IntHeap implements Comparable<IntHeap> {
		private int[] h;

		public IntHeap(int[] h) {
			this.h = h;
		}

		public int size() {
			return h.length;
		}

		public int get(int i) {
			return h[i];
		}

		public void set(int i, int v) {
			h[i] = v;
		}

		public void swap(int i, int j) {
			int tmp = h[i];
			h[i] = h[j];
			h[j] = tmp;
		}

		public void push(int v) {
			h = Arrays.copyOf(h, h.length + 1);
			h[h.length - 1] = v;
		}

		public int pop() {
			int res = h[0];
			h = Arrays.copyOf(h, h.length - 1);
			return res;
		}

		@Override
		public int compareTo(IntHeap o) {
			return o.get(0) - get(0);
		}
	}

	// sortable points
	public static class Point implements Comparable<Point> {
		private int x;
		private int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public int getX() {
			return x;
		}

		public int getY() {
			return y;
		}

		@Override
		public int compareTo(Point o) {
			return x - o.x;
		}
	}

	public static class Points implements Comparable<Points> {
		private List<Point> points;

		public Points(List<Point> points) {
			this.points = points;
		}

		public int size() {
			return points.size();
		}

		public Point get(int i) {
			return points.get(i);
		}

		public void set(int i, Point v) {
			points.set(i, v);
		}

		public void swap(int i, int j) {
			Point tmp = points.get(i);
			points.set(i, points.get(j));
			points.set(j, tmp);
		}

		public void push(Point v) {
			points.add(v);
		}

		public Point pop() {
			if (points.isEmpty()) {
				return null;
			} else {
				Point res = points.get(0);
				points.remove(0);
				return res;
			}
		}

		@Override
		public int compareTo(Points o) {
			return get(0).compareTo(o.get(0));
		}
	}

	// END-OF-CODE
}