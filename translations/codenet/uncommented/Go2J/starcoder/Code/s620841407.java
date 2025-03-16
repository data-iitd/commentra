
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] edges = new int[n-1][2];
		for (int i = 0; i < n-1; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			x--;
			y--;
			edges[i][0] = x;
			edges[i][1] = y;
		}

		ReRootingSolver s = new ReRootingSolver(n, edges, 1, (x, y) -> (x * y) % m, (v, p) -> v + 1);
		for (int i = 0; i < n; i++) {
			System.out.println(s.Query(i) - 1);
		}
	}
}

class ReRootingSolver {
	int NodeCount;

	int[][] Adjacents;
	int[][] IndexForAdjacents;

	T[] Res;
	T[][] DP;

	T Identity;
	BinaryOperator<T> Operate;
	BiFunction<T, Integer, T> OperateNode;

	public ReRootingSolver(int nodeCount, int[][] edges, T identity, BinaryOperator<T> operate, BiFunction<T, Integer, T> operateNode) {
		NodeCount = nodeCount;

		Adjacents = new int[nodeCount][];
		IndexForAdjacents = new int[nodeCount][];
		for (int i = 0; i < nodeCount; i++) {
			IndexForAdjacents[i] = new int[nodeCount];
		}
		for (int[] e : edges) {
			IndexForAdjacents[e[0]][e[1]] = IndexForAdjacents[e[1]][e[0]] = IndexForAdjacents[e[0]].length;
			Adjacents[e[0]] = Arrays.copyOf(Adjacents[e[0]], Adjacents[e[0]].length + 1);
			Adjacents[e[1]] = Arrays.copyOf(Adjacents[e[1]], Adjacents[e[1]].length + 1);
			Adjacents[e[0]][IndexForAdjacents[e[0]][e[1]]] = e[1];
			Adjacents[e[1]][IndexForAdjacents[e[1]][e[0]]] = e[0];
		}

		DP = new T[nodeCount][];
		for (int i = 0; i < nodeCount; i++) {
			DP[i] = new T[nodeCount];
		}

		Res = new T[nodeCount];

		Identity = identity;
		Operate = operate;
		OperateNode = operateNode;

		if (nodeCount > 1) {
			Initialize();
		} else {
			Res[0] = OperateNode.apply(Identity, 0);
		}
	}

	public T Query(int node) {
		return Res[node];
	}

	public void Initialize() {
		int[] parents = new int[NodeCount];
		int[] order = new int[NodeCount];

		// InitOrderedTree
		int index = 0;
		Stack<Integer> stack = new Stack<>();
		stack.push(0);
		parents[0] = -1;
		while (!stack.isEmpty()) {
			int node = stack.pop();
			order[index] = node;
			index++;
			for (int i = 0; i < Adjacents[node].length; i++) {
				int adjacent = Adjacents[node][i];
				if (adjacent == parents[node]) {
					continue;
				}
				stack.push(adjacent);
				parents[adjacent] = node;
			}
		}

		// fromLeaf
		for (int i = order.length - 1; i >= 1; i--) {
			int node = order[i];
			int parent = parents[node];

			T accum = Identity;
			int parentIndex = -1;
			for (int j = 0; j < Adjacents[node].length; j++) {
				if (Adjacents[node][j] == parent) {
					parentIndex = j;
					continue;
				}
				accum = Operate.apply(accum, DP[node][j]);
			}
			DP[parent][IndexForAdjacents[node][parentIndex]] = OperateNode.apply(accum, node);
		}

		// toLeaf
		for (int i = 0; i < order.length; i++) {
			int node = order[i];
			T accum = Identity;
			T[] accumsFromTail = new T[Adjacents[node].length];
			accumsFromTail[accumsFromTail.length - 1] = Identity;
			for (int j = accumsFromTail.length - 1; j >= 1; j--) {
				accumsFromTail[j - 1] = Operate.apply(DP[node][j], accumsFromTail[j]);
			}
			for (int j = 0; j < Adjacents[node].length; j++) {
				DP[Adjacents[node][j]][IndexForAdjacents[node][j]] = OperateNode.apply(Operate.apply(accum, accumsFromTail[j]), node);
				accum = Operate.apply(accum, DP[node][j]);
			}
			Res[node] = OperateNode.apply(accum, node);
		}
	}
}

