package main;

import java.util.Arrays;
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
		int[][] c = new int[H][W];
		for (int y = 0; y < H; y++) {
			String s = sc.next();
			for (int x = 0; x < W; x++) {
				c[y][x] = s.charAt(x) == '.'? 0 : 1;
			}
		}
		int[] dist = new int[H * W * 4];
		Arrays.fill(dist, Integer.MAX_VALUE);
		for (int dir = 0; dir < 4; dir++) {
			dist[toID(x1, y1, dir)] = 0;
			q.push(new State(0, toID(x1, y1, dir)));
		}
		processHeap();
		int ans = Integer.MAX_VALUE;
		for (int dir = 0; dir < 4; dir++) {
			int id = toID(x2, y2, dir);
			if (dist[id] < ans) {
				ans = dist[id];
			}
		}
		if (ans == Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(ans);
		}
	}

	// Constants to represent the possible directions of movement
	static final int[] dx = {1, 0, -1, 0};
	static final int[] dy = {0, 1, 0, -1};

	// Function to calculate the index of the next cell in a given direction from the current cell
	static int toID(int x, int y, int dir) {
		return 4 * (W * y + x) + dir;
	}

	// Function to extract the position and direction from the index of a cell
	static int[] splatID(int id) {
		int x = id % W;
		int y = id / W;
		int dir = id % 4;
		return new int[] {x, y, dir};
	}

	// Function to process the heap until the goal cell is reached or all cells have been visited
	static void processHeap() {
		while (!q.isEmpty()) {
			State now = q.pop();
			int x = splatID(now.id)[0];
			int y = splatID(now.id)[1];
			int dir = splatID(now.id)[2];
			if (x == x2 && y == y2) {
				break;
			}
			if (dist[now.id] <= now.cost) {
				continue;
			}
			dist[now.id] = now.cost;
			for (int i = 0; i < 4; i++) {
				int nCost = now.cost + K;
				int nID = toID(x, y, i);
				if (dist[nID] <= nCost) {
					continue;
				}
				q.push(new State(nCost, nID));
			}
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (0 <= nx && nx < W && 0 <= ny && ny < H) {
				int nCost = now.cost + 1;
				int nID = toID(nx, ny, dir);
				if (dist[nID] <= nCost) {
					continue;
				}
				q.push(new State(nCost, nID));
			}
		}
	}

	// Function to calculate the minimum number of moves to reach the goal cell
	static int calculateAnswer() {
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < 4; i++) {
			int id = toID(x2, y2, i);
			if (dist[id] < ans) {
				ans = dist[id];
			}
		}
		return ans;
	}

	// Function to print the result
	static void printResult() {
		int ans = calculateAnswer();
		if (ans == Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(ans);
		}
	}

	// Global variables
	static int H, W, K, x1, y1, x2, y2;
	static int[][] c;
	static int[] dist;
	static Heap<State> q = new Heap<>();

	// Types
	static class State implements Comparable<State> {
		int cost, id;

		public State(int cost, int id) {
			this.cost = cost;
			this.id = id;
		}

		@Override
		public int compareTo(State o) {
			return cost - o.cost;
		}
	}

	// Functions
	static int ReadInt() {
		Scanner sc = new Scanner(System.in);
		return sc.nextInt();
	}

	static String ReadString() {
		Scanner sc = new Scanner(System.in);
		return sc.next();
	}

	static int[] ReadInts(int n) {
		Scanner sc = new Scanner(System.in);
		int[] v = new int[n];
		for (int i = 0; i < n; i++) {
			v[i] = sc.nextInt();
		}
		return v;
	}

	static int[][] ReadGrid(int H, int W) {
		int[][] c = new int[H][W];
		for (int y = 0; y < H; y++) {
			String s = ReadString();
			for (int x = 0; x < W; x++) {
				c[y][x] = s.charAt(x) == '.'? 0 : 1;
			}
		}
		return c;
	}

	static void initDist(int H, int W, int K, int x1, int y1, int x2, int y2) {
		dist = new int[H * W * 4];
		Arrays.fill(dist, Integer.MAX_VALUE);
		for (int dir = 0; dir < 4; dir++) {
			dist[toID(x1, y1, dir)] = 0;
			q.push(new State(0, toID(x1, y1, dir)));
		}
	}

	static void processHeap() {
		while (!q.isEmpty()) {
			State now = q.pop();
			int x = splatID(now.id)[0];
			int y = splatID(now.id)[1];
			int dir = splatID(now.id)[2];
			if (x == x2 && y == y2) {
				break;
			}
			if (dist[now.id] <= now.cost) {
				continue;
			}
			dist[now.id] = now.cost;
			for (int i = 0; i < 4; i++) {
				int nCost = now.cost + K;
				int nID = toID(x, y, i);
				if (dist[nID] <= nCost) {
					continue;
				}
				q.push(new State(nCost, nID));
			}
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (0 <= nx && nx < W && 0 <= ny && ny < H) {
				int nCost = now.cost + 1;
				int nID = toID(nx, ny, dir);
				if (dist[nID] <= nCost) {
					continue;
				}
				q.push(new State(nCost, nID));
			}
		}
	}

	static int calculateAnswer() {
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < 4; i++) {
			int id = toID(x2, y2, i);
			if (dist[id] < ans) {
				ans = dist[id];
			}
		}
		return ans;
	}

	static void printResult() {
		int ans = calculateAnswer();
		if (ans == Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(ans);
		}
	}

	static void Scan(Object... o) {
		Scanner sc = new Scanner(System.in);
		for (Object e : o) {
			if (e instanceof Integer) {
				int v = sc.nextInt();
				if (e instanceof Integer) {
					int iv = (Integer) e;
					iv = v;
				}
			} else if (e instanceof String) {
				String v = sc.next();
				if (e instanceof String) {
					String iv = (String) e;
					iv = v;
				}
			} else if (e instanceof int[]) {
				int[] v = new int[((int[]) e).length];
				for (int i = 0; i < v.length; i++) {
					v[i] = sc.nextInt();
				}
				int[] iv = (int[]) e;
				System.arraycopy(v, 0, iv, 0, v.length);
			} else if (e instanceof int[][]) {
				int[][] v = new int[((int[][]) e).length][((int[][]) e)[0].length];
				for (int i = 0; i < v.length; i++) {
					for (int j = 0; j < v[0].length; j++) {
						v[i][j] = sc.nextInt();
					}
				}
				int[][] iv = (int[][]) e;
				System.arraycopy(v, 0, iv, 0, v.length);
			}
		}
	}

	static void main(String[] args) {
		int H = ReadInt();
		int W = ReadInt();
		int K = ReadInt();
		int x1 = ReadInt() - 1;
		int y1 = ReadInt() - 1;
		int x2 = ReadInt() - 1;
		int y2 = ReadInt() - 1;
		int[][] c = ReadGrid(H, W);
		initDist(H, W, K, x1, y1, x2, y2);
		processHeap();
		printResult();
	}
}

// Comments
// Global variables
// H, W, K, x1, y1, x2, y2: the height, width, number of moves, and starting and ending positions of the grid
// c: the grid
// dist: the distance from the starting cell to all other cells
// q: the heap of states
// dx, dy: the possible directions of movement
// State: the state of the grid
// Heap: the heap of states
// HeapElement: the interface of heap elements
// Inf: the constant representing infinity
// toID: function to calculate the index of a cell in the grid based on its position and direction
// splatID: function to calculate the position and direction from the index of a cell
// initDist: function to initialize the distances to all cells to infinity and add the starting cell to the heap
// processHeap: function to process the heap until the goal cell is reached or all cells have been visited
// calculateAnswer: function to calculate the minimum number of moves to reach the goal cell
// printResult: function to print the result
// ReadInt: function to read a single integer from standard input
// ReadString: function to read a single string from standard input
// ReadInts: function to read multiple integers from standard input
// ReadInput: function to read the initial dimensions and number of moves from standard input
// ReadGrid: function to read the input grid from standard input
// Scan: function to read from standard input using a buffer reader
// main: the main function

// Constants to represent the possible directions of movement
// dx: the horizontal direction
// dy: the vertical direction

// Type to represent a state of the grid
// Cost: the cost of the state
// ID: the index of the state

// Type to represent a heap of states
// HeapElement: the interface of heap elements
// Heap: the heap of states

// Function to read a single integer from standard input
// Returns an integer value read from standard input

// Function to read a single string from standard input
// Returns a string value read from standard input

// Function to read multiple integers from standard input
// Reads n integers from standard input and returns a slice of integers

// Function to read the initial dimensions and number of moves from standard input
// Returns the height, width, and number of moves of the grid

// Function to read the input grid from standard input
// Returns a slice of strings representing the grid

// Function to calculate the index of a cell in the grid based on its position and direction
// x, y, dir: the position and direction of the cell
// Returns the index of the cell

// Function to calculate the index of a cell from its index
// id: the index of the cell
// Returns the position and direction of the cell

// Function to initialize the distances to all cells to infinity and add the starting cell to the heap
// H, W, K, x1, y1, x2, y2: the height, width, number of moves, and starting and ending positions of the grid

// Function to process the heap until the goal cell is reached or all cells have been visited

// Function to calculate the minimum number of moves to reach the goal cell

// Function to print the result

// Global variables
// H, W, K, x1, y1, x2, y2: the height, width, number of moves, and starting and ending positions of the grid
// c: the grid
// dist: the distance from the starting cell to all other cells
// q: the heap of states
// dx, dy: the possible directions of movement
// State: the state of the grid
// Heap: the heap of states
// HeapElement: the interface of heap elements
// Inf: the constant representing infinity
// toID: function to calculate the in