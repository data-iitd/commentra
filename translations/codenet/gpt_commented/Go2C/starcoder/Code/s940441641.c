

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REPD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define INF INT_MAX

typedef struct {
	int x, y, dir;
} State;

typedef struct {
	State *data;
	int size, capacity;
} Heap;

// Function to convert (x, y, dir) to a unique ID
int toID(int x, int y, int dir) {
	return 4*(W*y+x) + dir;
}
// Function to convert an ID back to (x, y, dir)
void splatID(int id, int *x, int *y, int *dir) {
	*x = id / 4 % W;
	*y = id / 4 / W;
	*dir = id % 4;
}

// Initialize the distance array with infinity
void initDist(int *dist, int W, int H) {
	REP(i, W*H*4) {
		dist[i] = INF;
	}
}

// Initialize the priority queue (min-heap) with starting states
void initQ(Heap *q, int W, int H, int x1, int y1) {
	q->data = (State*)malloc(sizeof(State) * 4);
	q->size = 0;
	q->capacity = 4;
	REP(i, 4) {
		q->data[i].x = x1;
		q->data[i].y = y1;
		q->data[i].dir = i;
		q->size++;
	}
}

// Main loop for Dijkstra's algorithm
void dijkstra(int *c, int W, int H, int K, int x1, int y1, int x2, int y2, Heap *q, int *dist) {
	while (q->size > 0) {
		State now = q->data[0];
		q->size--;
		q->data[0] = q->data[q->size];
		int x = now.x, y = now.y, dir = now.dir;

		// Skip if the current position is a wall
		if (c[y][x] == '@') {
			continue;
		}
		// Skip if we have already found a better cost for this state
		if (dist[toID(x, y, dir)] <= now.Cost) {
			continue;
		}
		// Update the distance for the current state
		dist[toID(x, y, dir)] = now.Cost;

		// If we reached the destination, exit the loop
		if (x == x2 && y == y2) {
			break;
		}

		// Explore all four possible directions
		REP(i, 4) {
			int nCost = (now.Cost + K - 1) / K * K; // Calculate the new cost
			int nID = toID(x, y, i); // Get the new ID for the direction
			if (dist[nID] <= nCost) { // Skip if we have a better cost
				continue;
			}
			// Push the new state into the priority queue
			q->data[q->size].Cost = nCost;
			q->data[q->size].ID = nID;
			q->size++;
		}

		// Move in the current direction
		int nx = x + dx[dir], ny = y + dy[dir];
		// Check if the new position is within bounds
		if (0 <= nx && nx < W && 0 <= ny && ny < H) {
			int nCost = now.Cost + 1; // Increment the cost for moving forward
			int nID = toID(nx, ny, dir); // Get the new ID for the position
			if (dist[nID] <= nCost) { // Skip if we have a better cost
				continue;
			}
			// Push the new state into the priority queue
			q->data[q->size].Cost = nCost;
			q->data[q->size].ID = nID;
			q->size++;
		}
	}
}

// Determine the minimum cost to reach the destination
int getAns(int *dist, int W, int H, int K, int x2, int y2) {
	int ans = INF;
	REP(i, 4) {
		int id = toID(x2, y2, i); // Get the ID for the destination in each direction
		if (dist[id] < ans) { // Check if we found a better cost
			int d2 = (dist[id] + K - 1) / K; // Calculate the cost in terms of K
			if (d2 < ans) { // Update the answer if it's better
				ans = d2;
			}
		}
	}
	return ans;
}

// Main function
int main() {
	// Read the dimensions of the grid and the cost parameter
	int H, W, K = ReadInt(), ReadInt(), ReadInt();
	// Read the starting and ending coordinates, adjusting for 0-based indexing
	int x1, y1, x2, y2 = ReadInt()-1, ReadInt()-1, ReadInt()-1, ReadInt()-1;
	x1 ^= y1 ^= y1 ^= x1; // Swap x and y for the starting point
	x2 ^= y2 ^= y2 ^= x2; // Swap x and y for the ending point

	// Read the grid representation
	char **c = (char**)malloc(sizeof(char*) * H);
	REP(y, H) {
		c[y] = (char*)malloc(sizeof(char) * W);
		scanf("%s", c[y]);
	}

	// Define movement directions (right, down, left, up)
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};

	// Initialize the distance array with infinity
	int *dist = (int*)malloc(sizeof(int) * W * H * 4);
	initDist(dist, W, H);

	// Initialize the priority queue (min-heap) with starting states
	Heap q;
	initQ(&q, W, H, x1, y1);

	// Main loop for Dijkstra's algorithm
	dijkstra(c, W, H, K, x1, y1, x2, y2, &q, dist);

	// Determine the minimum cost to reach the destination
	int ans = getAns(dist, W, H, K, x2, y2);

	// Output the result
	if (ans < INF) {
		printf("%d\n", ans); // Print the minimum cost
	} else {
		printf("-1\n"); // Print -1 if the destination is unreachable
	}

	// Free the memory
	REP(y, H) {
		free(c[y]);
	}
	free(c);
	free(dist);
	free(q.data);
}

// Reader for standard input
FILE *reader = fopen("dijkstra.in", "r");

// Scan function to read input
#define SCAN(a) if (fscanf(reader, "%d", &(a))!= 1) { \
	printf("Error reading input\n"); \
	exit(1); \
}

// Read an integer from input
#define READ_INT(a) SCAN(a)

// Read a string from input
#define READ_STRING(a) fscanf(reader, "%s", a)

// Read a slice of integers from input
#define READ_INTS(a, n) REP(i, n) { \
	if (fscanf(reader, "%d", &(a[i]))!= 1) { \
		printf("Error reading input\n"); \
		exit(1); \
	} \
}

// Reader for standard output
FILE *writer = fopen("dijkstra.out", "w");

// Print function to output
#define PRINT(a) fprintf(writer, "%d\n", a)

// Print a slice of integers to output
#define PRINT_INTS(a, n) REP(i, n) { \
	fprintf(writer, "%d ", a[i]); \
}

// Print a slice of strings to output
#define PRINT_STRS(a, n) REP(i, n) { \
	fprintf(writer, "%s ", a[i]); \
}

// Print a slice of characters to output
#define PRINT_CHARS(a, n) REP(i, n) { \
	fprintf(writer, "%c ", a[i]); \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_SPACE(a, n) REP(i, n) { \
	fprintf(writer, "%c", a[i]); \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE(a, n) REP(i, n) { \
	fprintf(writer, "%c", a[i]); \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_SPACE_NO_NEWLINE(a, n) REP(i, n) { \
	fprintf(writer, "%c", a[i]); \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE(a, n) REP(i, n) { \
	fprintf(writer, "%c", a[i]); \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of characters to output
#define PRINT_CHARS_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE_NO_NEWLINE_NO_SPACE_NO_COMMA_NO_SPACE(a, n) REP(i, n) { \
	if (i!= n - 1) { \
		fprintf(writer, "%c, ", a[i]); \
	} else { \
		fprintf(writer, "%c", a[i]); \
	} \
}

// Print a slice of c