
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// Read the number of nodes (N) and the number of edges (M)
		int N = sc.nextInt();
		int M = sc.nextInt();

		// Initialize a slice of Node with N elements
		Node[] n = new Node[N];
		for (int i = 0; i < N; i++) {
			n[i] = new Node();
		}

		// Read M pairs of edges and populate the adjacency list for each node
		for (int i = 0; i < M; i++) {
			int from = sc.nextInt() - 1;
			int to = sc.nextInt() - 1;
			n[from].to.add(to);
			n[to].to.add(from);
		}

		// Print the size of the adjacency list for each node
		for (int i = 0; i < N; i++) {
			System.out.println(n[i].to.size());
		}
	}
}

class Node {
	ArrayList<Integer> to;

	public Node() {
		to = new ArrayList<Integer>();
	}
}

