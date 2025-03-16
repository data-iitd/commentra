
package main

import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.Comparator;

// Function to read a single integer from standard input
public static int ReadInt() {
	Scanner sc = new Scanner(System.in);
	return sc.nextInt();
}

// Function to read a single string from standard input
public static String ReadString() {
	Scanner sc = new Scanner(System.in);
	return sc.next();
}

// Function to read multiple integers from standard input
public static int[] ReadInts(int n) {
	int[] v = new int[n];
	for (int i = 0; i < n; i++) {
		v[i] = ReadInt();
	}
	return v;
}

// Function to read the initial dimensions and number of moves from standard input
public static int[] ReadInput() {
	int[] v = new int[7];
	v[0] = ReadInt();
	v[1] = ReadInt();
	v[2] = ReadInt();
	v[3] = ReadInt() - 1;
	v[4] = ReadInt() - 1;
	v[5] = ReadInt() - 1;
	v[6] = ReadInt() - 1;
	v[3] = v[4];
	v[4] = v[3];
	v[5] = v[6];
	v[6] = v[5];
	return v;
}

// Function to read the input grid from standard input
public static String[] ReadGrid(int H, int W) {
	String[] c = new String[H];
	for (int y = 0; y < H; y++) {
		c[y] = ReadString();
	}
	return c;
}

// Function to calculate the index of a cell in the grid based on its position and direction
public static int toID(int x, int y, int dir) {
	return 4 * (W * y + x) + dir;
}

// Function to extract the position and direction from the index of a cell
public static int[] splatID(int id) {
	int[] v = new int[3];
	v[0] = id % W;
	v[1] = id / W;
	v[2] = id % 4;
	return v;
}

// Function to initialize the distances to all cells to infinity and add the starting cell to the heap
public static void initDist(int H, int W, int K, int x1, int y1, int x2, int y2) {
	dist = new int[W * H * 4];
	for (int i = 0; i < W * H * 4; i++) {
		dist[i] = Inf;
	}
	for (int i = 0; i < 4; i++) {
		q.add(new State(0, toID(x1, y1, i)));
	}
}

// Function to process the heap until the goal cell is reached or all cells have been visited
public static void processHeap() {
	while (!q.isEmpty()) {
		State now = q.poll();
		int x = now.ID % W;
		int y = now.ID / W;
		int dir = now.ID % 4;

		if (x == x2 && y == y2) {
			break;
		}

		if (dist[now.ID] <= now.Cost) {
			continue;
		}

		dist[now.ID] = now.Cost;
		for (int i = 0; i < 4; i++) {
			int nCost = now.Cost + K;
			int nID = toID(x, y, i);
			if (dist[nID] <= nCost) {
				continue;
			}
			q.add(new State(nCost, nID));
		}

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (0 <= nx && nx < W && 0 <= ny && ny < H) {
			int nCost = now.Cost + 1;
			int nID = toID(nx, ny, dir);
			if (dist[nID] <= nCost) {
				continue;
			}
			q.add(new State(nCost, nID));
		}
	}
}

// Function to calculate the minimum number of moves to reach the goal cell
public static int calculateAnswer() {
	int ans = Inf;
	for (int i = 0; i < 4; i++) {
		int id = toID(x2, y2, i);
		if (dist[id] < ans) {
			ans = dist[id];
		}
	}
	return ans;
}

// Function to print the result
public static void printResult() {
	if (ans < Inf) {
		System.out.println(ans);
	} else {
		System.out.println(-1);
	}
}

// Global variables
public static int[] dist;
public static PriorityQueue<State> q = new PriorityQueue<State>(new Comparator<State>() {
	public int compare(State a, State b) {
		return a.Cost - b.Cost;
	}
});
public static int Inf = 1 << 60;

// Constants
public static int[] dx = { 1, 0, -1, 0 };
public static int[] dy = { 0, 1, 0, -1 };

// Types
public static class State {
	public int Cost, ID;

	public State(int cost, int id) {
		Cost = cost;
		ID = id;
	}
}

// Functions
public static void main(String[] args) {
	// Read the input dimensions, number of moves, and starting and ending positions
	int[] v = ReadInput();
	int H = v[0], W = v[1], K = v[2], x1 = v[3], y1 = v[4], x2 = v[5], y2 = v[6];

	// Read the input grid
	String[] c = ReadGrid(H, W);

	// Initialize the distances and add the starting cell to the heap
	initDist(H, W, K, x1, y1, x2, y2);

	// Process the heap until the goal cell is reached or all cells have been visited
	processHeap();

	// Calculate the minimum number of moves to reach the goal cell
	ans = calculateAnswer();

	// Print the result
	printResult();
}

// Comments
// Function to read a single integer from standard input
// Returns an integer value read from standard input
public static int ReadInt() {
	Scanner sc = new Scanner(System.in);
	return sc.nextInt();
}

// Function to read a single string from standard input
// Returns a string value read from standard input
public static String ReadString() {
	Scanner sc = new Scanner(System.in);
	return sc.next();
}

// Function to read multiple integers from standard input
// Reads n integers from standard input and returns a slice of integers
public static int[] ReadInts(int n) {
	int[] v = new int[n];
	for (int i = 0; i < n; i++) {
		v[i] = ReadInt();
	}
	return v;
}

// Function to read the initial dimensions and number of moves from standard input
// Returns the height, width, and number of moves of the grid
public static int[] ReadInput() {
	int[] v = new int[7];
	v[0] = ReadInt();
	v[1] = ReadInt();
	v[2] = ReadInt();
	v[3] = ReadInt() - 1;
	v[4] = ReadInt() - 1;
	v[5] = ReadInt() - 1;
	v[6] = ReadInt() - 1;
	v[3] = v[4];
	v[4] = v[3];
	v[5] = v[6];
	v[6] = v[5];
	return v;
}

// Function to read the input grid from standard input
// Returns a slice of strings representing the grid
public static String[] ReadGrid(int H, int W) {
	String[] c = new String[H];
	for (int y = 0; y < H; y++) {
		c[y] = ReadString();
	}
	return c;
}

// Function to calculate the index of a cell in the grid based on its position and direction
public static int toID(int x, int y, int dir) {
	return 4 * (W * y + x) + dir;
}

// Function to extract the position and direction from the index of a cell
public static int[] splatID(int id) {
	int[] v = new int[3];
	v[0] = id % W;
	v[1] = id / W;
	v[2] = id % 4;
	return v;
}

// Function to initialize the distances to all cells to infinity and add the starting cell to the heap
public static void initDist(int H, int W, int K, int x1, int y1, int x2, int y2) {
	dist = new int[W * H * 4];
	for (int i = 0; i < W * H * 4; i++) {
		dist[i] = Inf;
	}
	for (int i = 0; i < 4; i++) {
		q.add(new State(0, toID(x1, y1, i)));
	}
}

// Function to process the heap until the goal cell is reached or all cells have been visited
public static void processHeap() {
	while (!q.isEmpty()) {
		State now = q.poll();
		int x = now.ID % W;
		int y = now.ID / W;
		int dir = now.ID % 4;

		if (x == x2 && y == y2) {
			break;
		}

		if (dist[now.ID] <= now.Cost) {
			continue;
		}

		dist[now.ID] = now.Cost;
		for (int i = 0; i < 4; i++) {
			int nCost = now.Cost + K;
			int nID = toID(x, y, i);
			if (dist[nID] <= nCost) {
				continue;
			}
			q.add(new State(nCost, nID));
		}

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (0 <= nx && nx < W && 0 <= ny && ny < H) {
			int nCost = now.Cost + 1;
			int nID = toID(nx, ny, dir);
			if (dist[nID] <= nCost) {
				continue;
			}
			q.add(new State(nCost, nID));
		}
	}
}

// Function to calculate the minimum number of moves to reach the goal cell
public static int calculateAnswer() {
	int ans = Inf;
	for (int i = 0; i < 4; i++) {
		int id = toID(x2, y2, i);
		if (dist[id] < ans) {
			ans = dist[id];
		}
	}
	return ans;
}

// Function to print the result
public static void printResult() {
	if (ans < Inf) {
		System.out.println(ans);
	} else {
		System.out.println(-1);
	}
}

// Global variables
public static int[] dist;
public static PriorityQueue<State> q = new PriorityQueue<State>(new Comparator<State>() {
	public int compare(State a, State b) {
		return a.Cost - b.Cost;
	}
});
public static int Inf = 1 << 60;

// Constants
public static int[] dx = { 1, 0, -1, 0 };
public static int[] dy = { 0, 1, 0, -1 };

// Types
public static class State {
	public int Cost, ID;

	public State(int cost, int id) {
		Cost = cost;
		ID = id;
	}
}

// Functions
public static void main(String[] args) {
	// Read the input dimensions, number of moves, and starting and ending positions
	int[] v = ReadInput();
	int H = v[0], W = v[1], K = v[2], x1 = v[3], y1 = v[4], x2 = v[5], y2 = v[6];

	// Read the input grid
	String[] c = ReadGrid(H, W);

	// Initialize the distances and add the starting cell to the heap
	initDist(H, W, K, x1, y1, x2, y2);

	// Process the heap until the goal cell is reached or all cells have been visited
	processHeap();

	// Calculate the minimum number of moves to reach the goal cell
	ans = calculateAnswer();

	// Print the result
	printResult();
}

// Comments
// Function to read a single integer from standard input
// Returns an integer value read from standard input
public static int ReadInt() {
	Scanner sc = new Scanner(System.in);
	return sc.nextInt();
}

// Function to read a single string from standard input
// Returns a string value read from standard input
public static String ReadString() {
	Scanner sc = new Scanner(System.in);
	return sc.next();
}

// Function to read multiple integers from standard input
// Reads n integers from standard input and returns a slice of integers
public static int[] ReadInts(int n) {
	int[] v = new int[n];
	for (int i = 0; i < n; i++) {
		v[i] = ReadInt();
	}
	return v;
}

// Function to read the initial dimensions and number of moves from standard input
// Returns the height, width, and number of moves of the grid
public static int[] ReadInput() {
	int[] v = new int[7];
	v[0] = ReadInt();
	v[1] = ReadInt();
	v[2] = ReadInt();
	v[3] = ReadInt() - 1;
	v[4] = ReadInt() - 1;
	v[5] = ReadInt() - 1;
	v[6] = ReadInt() - 1;
	v[3] = v[4];
	v[4] = v[3];
	v[5] = v[6];
	v[6] = v[5];
	return v;
}

// Function to read the input grid from standard input
// Returns a slice of strings representing the grid
public static String[] ReadGrid(int H, int W) {
	String[] c = new String[H];
	for (int y = 0; y < H; y++) {
		c[y] = ReadString();
	}
	return c;
}

// Function to calculate the index of a cell in the grid based on its position and direction
publi