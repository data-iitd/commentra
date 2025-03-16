package main;

import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		InputStreamReader is = new InputStreamReader(System.in);
		OutputStreamWriter os = new OutputStreamWriter(System.out);
		InputReader in = new InputReader(is);
		PrintStream out = System.out;
		Scanner sc = new Scanner(is);

		int n, m;
		try {
			n = in.readInt();
			m = in.readInt();
		} catch (Exception e) {
			throw new InputMismatchException();
		}

		int[][] edges = new int[n - 1][2];
		for (int i = 0; i < n - 1; i++) {
			try {
				for (int j = 0; j < 2; j++) {
					edges[i][j] = in.readInt();
				}
			} catch (Exception e) {
				throw new InputMismatchException();
			}
		}

		ReRootingSolver s = new ReRootingSolver(n, edges, 1, (x, y) -> (x * y) % m, (v, p) -> v + 1);
		for (int i = 0; i < n; i++) {
			out.println(s.Query(i) - 1);
		}

		try {
			sc.close();
		} catch (Exception e) {
		}
	}
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream), 32768);
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null ||!tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public char[] nextCharArray() {
		return next().toCharArray();
	}

	// public boolean hasNext() {
	// try {
	// return reader.ready();
	// } catch(IOException e) {
	// throw new RuntimeException(e);
	// }
	// }
}

class ReRootingSolver {
	int nodeCount;

	int[][] adjacents;
	int[][] indexForAdjacents;

	T[] res;
	T[][] dp;

	T identity;
	BinaryOperator<T> operate;
	BiFunction<T, Integer, T> operateNode;

	public ReRootingSolver(int nodeCount, int[][] edges, T identity, BinaryOperator<T> operate,
			BiFunction<T, Integer, T> operateNode) {
		this.nodeCount = nodeCount;

		this.adjacents = new int[nodeCount][];
		this.indexForAdjacents = new int[nodeCount][];
		for (int i = 0; i < nodeCount; i++) {
			this.indexForAdjacents[i] = new int[0];
			this.adjacents[i] = new int[0];
		}
		for (int[] e : edges) {
			this.indexForAdjacents[e[0]] = Arrays.copyOf(this.indexForAdjacents[e[0]],
					this.indexForAdjacents[e[0]].length + 1);
			this.indexForAdjacents[e[1]] = Arrays.copyOf(this.indexForAdjacents[e[1]],
					this.indexForAdjacents[e[1]].length + 1);
			this.adjacents[e[0]] = Arrays.copyOf(this.adjacents[e[0]], this.adjacents[e[0]].length + 1);
			this.adjacents[e[1]] = Arrays.copyOf(this.adjacents[e[1]], this.adjacents[e[1]].length + 1);
			this.indexForAdjacents[e[0]][this.indexForAdjacents[e[0]].length - 1] = this.adjacents[e[1]].length - 1;
			this.indexForAdjacents[e[1]][this.indexForAdjacents[e[1]].length - 1] = this.adjacents[e[0]].length - 1;
			this.adjacents[e[0]][this.adjacents[e[0]].length - 1] = e[1];
			this.adjacents[e[1]][this.adjacents[e[1]].length - 1] = e[0];
		}

		this.dp = new T[this.adjacents.length][];
		for (int i = 0; i < this.adjacents.length; i++) {
			this.dp[i] = new T[this.adjacents[i].length];
		}

		this.res = new T[this.adjacents.length];

		this.identity = identity;
		this.operate = operate;
		this.operateNode = operateNode;

		if (this.nodeCount > 1) {
			this.Initialize();
		} else {
			this.res[0] = this.operateNode.apply(this.identity, 0);
		}
	}

	public T Query(int node) {
		return this.res[node];
	}

	public void Initialize() {
		int[] parents, order;
		parents = new int[this.nodeCount];
		order = new int[this.nodeCount];

		// InitOrderedTree initializes the tree in a way that is useful for traversal
		int index = 0;
		Stack<Integer> stack = new Stack<Integer>();
		stack.push(0);
		parents[0] = -1;
		while (!stack.isEmpty()) {
			int node = stack.pop();
			order[index] = node;
			index++;
			for (int i = 0; i < this.adjacents[node].length; i++) {
				int adjacent = this.adjacents[node][i];
				if (adjacent == parents[node]) {
					continue;
				}
				stack.push(adjacent);
				parents[adjacent] = node;
			}
		}

		// fromLeaf computes values starting from the leaves
		for (int i = order.length - 1; i >= 1; i--) {
			int node = order[i];
			int parent = parents[node];

			T accum = this.identity;
			int parentIndex = -1;
			for (int j = 0; j < this.adjacents[node].length; j++) {
				if (this.adjacents[node][j] == parent) {
					parentIndex = j;
					continue;
				}
				accum = this.operate.apply(accum, this.dp[node][j]);
			}
			this.dp[parent][this.indexForAdjacents[node][parentIndex]] = this.operateNode.apply(accum, node);
		}

		// toLeaf computes values propagating from leaves to the root
		for (int i = 0; i < order.length; i++) {
			int node = order[i];
			T accum = this.identity;
			T[] accumsFromTail = new T[this.adjacents[node].length];
			accumsFromTail[this.adjacents[node].length - 1] = this.identity;
			for (int j = this.adjacents[node].length - 1; j >= 1; j--) {
				accumsFromTail[j - 1] = this.operate.apply(this.dp[node][j], accumsFromTail[j]);
			}
			for (int j = 0; j < this.adjacents[node].length; j++) {
				this.dp[this.adjacents[node][j]][this.indexForAdjacents[node][j]] = this.operateNode.apply(
						this.operate.apply(accum, accumsFromTail[j]), node);
				accum = this.operate.apply(accum, this.dp[node][j]);
			}
			this.res[node] = this.operateNode.apply(accum, node);
		}
	}
}

