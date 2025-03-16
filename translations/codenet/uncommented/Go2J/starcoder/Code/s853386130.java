package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		int R = Integer.parseInt(br.readLine());
		int[] rs = new int[R];
		for (int i = 0; i < R; i++) {
			rs[i] = Integer.parseInt(br.readLine()) - 1;
		}
		int[][] costs = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				costs[i][j] = Integer.MAX_VALUE;
			}
			costs[i][i] = 0;
		}
		int a, b, c;
		for (int i = 0; i < m; i++) {
			String[] line = br.readLine().split(" ");
			a = Integer.parseInt(line[0]) - 1;
			b = Integer.parseInt(line[1]) - 1;
			c = Integer.parseInt(line[2]);
			costs[a][b] = c;
			costs[b][a] = c;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					costs[i][j] = Math.min(costs[i][j], costs[i][k] + costs[k][j]);
				}
			}
		}
		int ans = Integer.MAX_VALUE;
		for (int[] perm : permutations(rs)) {
			int tmp = 0;
			for (int j = 1; j < perm.length; j++) {
				tmp += costs[perm[j-1]][perm[j]];
			}
			ans = Math.min(ans, tmp);
		}
		System.out.println(ans);
	}

	// permutations
	public static List<int[]> permutations(int[] arr) {
		List<int[]> res = new ArrayList<>();
		helper(arr, res, 0);
		return res;
	}

	public static void helper(int[] arr, List<int[]> res, int n) {
		if (n == arr.length) {
			int[] tmp = new int[arr.length];
			System.arraycopy(arr, 0, tmp, 0, arr.length);
			res.add(tmp);
		} else {
			for (int i = 0; i < arr.length; i++) {
				helper(arr, res, n+1);
				if (n%2 == 1) {
					int tmp = arr[i];
					arr[i] = arr[n];
					arr[n] = tmp;
				} else {
					int tmp = arr[0];
					arr[0] = arr[n];
					arr[n] = tmp;
				}
			}
		}
	}

	// Union-Find
	class unionFind {
		int[] d;

		public unionFind(int n) {
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
		for (int i = 1; i <= n; i++) {
			res = res * a % mod;
		}
		return res;
	}

	public static int modinv(int n, int mod) {
		return modpow(n, mod-2, mod);
	}

	public static int modcomb(int n, int a, int mod) {
		int x = 1;
		int y = 1;
		for (int i = 0; i < a; i++) {
			x = x * (n - i) % mod;
			y = y * (i + 1) % mod;
		}
		return x * modpow(y, mod-2, mod) % mod;
	}

	public static int modfactorial(int n, int mod) {
		int result = 1;
		for (int i = 1; i <= n; i++) {
			result = (result * i) % mod;
		}
		return result;
	}

	// Combination
	class Combination {
		int[] facts;
		int[] invs;
		int mod;

		public Combination(int n, int mod) {
			facts = new int[n+1];
			invs = new int[n+1];
			this.mod = mod;
		}

		public int calc(int n, int k) {
			int ret = facts[n] * invs[k];
			ret %= mod;
			ret = ret * invs[n-k];
			ret %= mod;
			return ret;
		}

		public void init(int n) {
			facts[0] = 1;
			// 階乗を算出
			for (int i = 1; i <= n; i++) {
				facts[i] = facts[i-1] * i % mod;
			}
			// 逆元を算出
			invs[n] = modinv(facts[n], mod);
			for (int i = n - 1; i >= 0; i--) {
				invs[i] = invs[i+1] * (i + 1) % mod;
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
		for (int i = 2; i*i <= x; i++) {
			while (x%i == 0) {
				res.put(i, res.getOrDefault(i, 0) + 1);
				x = x / i;
			}
		}
		if (x!= 1) {
			res.put(x, 1);
		}
		return res;
	}

	public static List<Integer> divisor(int x) {
		List<Integer> res = new ArrayList<>();
		for (int i = 1; i*i <= x; i++) {
			if (x%i == 0) {
				res.add(i);
				if (i!= x/i) {
					res.add(x/i);
				}
			}
		}
		return res;
	}

	public static int gcd(int x, int y) {
		if (y == 0) {
			return x;
		}
		return gcd(y, x%y);
	}

	public static int lcm(int x, int y) {
		return x / gcd(x, y) * y;
	}

	public static String reverseString(String s) {
		char[] r = s.toCharArray();
		for (int i = 0, j = r.length-1; i < r.length/2; i++, j--) {
			char tmp = r[i];
			r[i] = r[j];
			r[j] = tmp;
		}
		return new String(r);
	}

	public static int pow(int a, int n) {
		int ret = 1;
		for (int i = 1; i <= n; i++) {
			ret *= a;
		}
		return ret;
	}

	// Queue
	class Queue {
		int[] q;
		int index;

		public Queue() {
			q = new int[100000];
			index = 0;
		}

		public boolean empty() {
			return index == 0;
		}

		public void push(int i) {
			q[index] = i;
			index++;
		}

		public int pop() {
			index--;
			return q[index];
		}
	}

	// Stack
	class Stack {
		int[] s;
		int index;

		public Stack() {
			s = new int[100000];
			index = 0;
		}

		public boolean empty() {
			return index == 0;
		}

		public void push(int i) {
			s[index] = i;
			index++;
		}

		public int pop() {
			index--;
			return s[index];
		}
	}

	// priority_queue
	class intHeap {
		int[] h;
		int size;

		public intHeap(int n) {
			h = new int[n+1];
			size = 0;
		}

		public int size() {
			return size;
		}

		public boolean empty() {
			return size == 0;
		}

		public int top() {
			return h[1];
		}

		public void push(int x) {
			size++;
			h[size] = x;
			swim(size);
		}

		public int pop() {
			int res = h[1];
			h[1] = h[size];
			size--;
			sink(1);
			return res;
		}

		public void swim(int k) {
			while (k > 1 && h[k/2] < h[k]) {
				int tmp = h[k/2];
				h[k/2] = h[k];
				h[k] = tmp;
				k /= 2;
			}
		}

		public void sink(int k) {
			while (2*k <= size) {
				int j = 2*k;
				if (j < size && h[j+1] < h[j]) {
					j++;
				}
				if (h[k] >= h[j]) {
					break;
				}
				int tmp = h[k];
				h[k] = h[j];
				h[j] = tmp;
				k = j;
			}
		}
	}

	// sortable points
	class point {
		int x;
		int y;

		public point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	class points implements Comparator<point> {
		public int compare(point a, point b) {
			if (a.x < b.x) {
				return -1;
			} else if (a.x > b.x) {
				return 1;
			} else {
				return 0;
			}
		}
	}
}

