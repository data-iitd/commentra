package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// IO
		// new FileReader("codeforces/problemset/problem/1000/A.java")
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		// new BufferedWriter(new FileWriter("out.txt"))
		PrintWriter pw = new PrintWriter(System.out);

		// INPUT
		String line;
		int N;
		int[] p = new int[200000];
		line = f.readLine();
		N = Integer.parseInt(line);
		line = f.readLine();
		for (int i = 0; i < N; i++) {
			p[i] = Integer.parseInt(line);
		}

		// PARSE HELPER SESSION

		// OUTPUT GENERATION PART
		int ans = 0;
		pw.println(ans);

		// BFS/DFS PART
		// visited := []int{}
		// bfs/dfs(1, neighbor, func(node int) {
		// 	visited = append(visited, node)
		// })
		// pw.println(visited);

		// DFS 2
		// var dp [2000000]int
		// nei := make(map[int][]int)
		// nei[0] = []int{1, 2}
		// nei[1] = []int{0}
		// nei[2] = []int{0, 3}
		// nei[3] = []int{2}
		// dfs2(0, nei, func(n, p int) {
		// 	pw.printf("%d -> %d\n", p, n)
		// 	dp[n] = p
		// }, func(n, p int) {
		// 	pw.printf("%d -> %d\n", n, p)
		// })
		// pw.println(dp[0:5]);

		// COMBINATION
		// pw.printf("%d %d %d\n", N, M, Math.max(N, M));
		// pw.printf("Lucas %d %d\n", combMod(N, M, 13), combination(N, M));

		// pw.flush();
		pw.close();
	}
}

// Libraries

// Io helps parsing inputs from standard input for programming contest.
class Io {
	private BufferedReader reader;
	private StringTokenizer tokenizer;
	private PrintWriter writer;

	public Io() {
		reader = new BufferedReader(new InputStreamReader(System.in));
		tokenizer = new StringTokenizer("");
		writer = new PrintWriter(System.out);
	}

	public void flush() {
		writer.flush();
	}

	public String next() throws IOException {
		while (!tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
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

	public void print(Object... o) {
		for (int i = 0; i < o.length; i++) {
			if (i!= 0) {
				writer.print(' ');
			}
			writer.print(o[i]);
		}
	}

	public void println(Object... o) {
		print(o);
		writer.println();
	}
}

// Stack data structure
class Stack {
	private Element top;
	private int size;

	public Stack() {
		top = null;
		size = 0;
	}

	public int Len() {
		return size;
	}

	public void Push(Object value) {
		top = new Element(value, top);
		size++;
	}

	public Object Pop() {
		if (size > 0) {
			Object value = top.value;
			top = top.next;
			size--;
			return value;
		}
		return null;
	}
}

// Element is a struct for stack element
class Element {
	public Object value;
	public Element next;

	public Element(Object value, Element next) {
		this.value = value;
		this.next = next;
	}
}

// direct calculation of combination
// n, m should be "small"
public int combination(int n, int m) {
	if (m > n) {
		return 0;
	} else if (m == n || m == 0) {
		return 1;
	} else {
		int res = 1;
		for (int i = 0; i < m; i++) {
			res *= (n - i);
		}
		for (int i = 1; i <= m; i++) {
			res /= i;
		}
		return res;
	}
}

// caluclate combination modulo based on Lucas theorem
public int combMod(int n, int m, int p) {
	int ntemp = n;
	int mtemp = m;
	int res = 1;
	for (int i = 0; i < 100; i++) {
		// System.out.printf("ntemp: %d\n", ntemp);
		int nreminder = ntemp % p;
		ntemp = ntemp / p;
		int mreminder = mtemp % p;
		mtemp = mtemp / p;
		res = res * (combination(nreminder, mreminder) % p);
		if (ntemp == 0) {
			break;
		}
	}
	return res % p;
}

// powerInt (use Math.pow() for float parameters)
public int powerInt(int n, int p) {
	int tmp = 1;
	for (int i = 0; i < n; i++) {
		tmp *= p;
	}
	return tmp;
}

public void findDivisors(int n, int[] a) {
	if (n == 1) {
		return;
	}

	int sqrt = (int) Math.sqrt(n);
	for (int i = 2; i <= sqrt; i++) {
		if (n % i == 0) {
			a = append(a, i);
			a = append(a, n / i);
		}
	}
	a = append(a, n);
}

public int[] removeDuplicate(int[] a) {
	int[] res = new int[a.length];
	int idx = 0;
	for (int i = 0; i < a.length; i++) {
		if (i == 0 || a[i]!= a[i - 1]) {
			res[idx] = a[i];
			idx++;
		}
	}
	return res;
}

public int abs(int a) {
	if (a > 0) {
		return a;
	}
	return -a;
}

// var gcdmap map[int](map[int]int)
// func gcd(a, b int) int {
// 	ina := a
// 	inb := b
// 	if _, ok := gcdmap[a];!ok {
// 		gcdmap[a] = make(map[int]int)
// 	}
// 	if _, ok := gcdmap[ina][inb]; ok {
// 		return gcdmap[ina][inb]
// 	}
// 	for b!= 0 {
// 		t := b
// 		b = a % b
// 		a = t
// 	}
// 	gcdmap[ina][inb] = a
// 	return a
// }

public int gcd(int a, int b) {
	while (a!= 0) {
		a, b = b % a, a;
	}
	return b;
}

public int power2mod(int n, int mod) {
	int res = 1, x = 2;
	for (; n > 0; n >>= 1) {
		if (n % 2 == 1) {
			res = res * x % mod;
		}
		x = x * x % mod;
	}
	return res;
}

public int power2(int n) {
	return power2mod(n, 1000000007);
}

