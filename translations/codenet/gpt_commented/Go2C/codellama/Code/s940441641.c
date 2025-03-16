
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

// Define a constant for infinity
#define INF 1 << 60

// Define a struct for a state in the priority queue
typedef struct {
    int cost;
    int id;
} State;

// Define a struct for a heap element
typedef struct {
    int cost;
    int id;
} HeapElement;

// Define a struct for a heap
typedef struct {
    HeapElement *data;
    int size;
    int capacity;
} Heap;

// Define a function to initialize a heap
void initHeap(Heap *h) {
    h->data = (HeapElement *)malloc(sizeof(HeapElement) * 1000000);
    h->size = 0;
    h->capacity = 1000000;
}

// Define a function to push an element into a heap
void pushHeap(Heap *h, HeapElement e) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = (HeapElement *)realloc(h->data, sizeof(HeapElement) * h->capacity);
    }
    h->data[h->size] = e;
    h->size++;
}

// Define a function to pop an element from a heap
HeapElement popHeap(Heap *h) {
    HeapElement e = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    return e;
}

// Define a function to check if a heap is empty
bool isEmptyHeap(Heap *h) {
    return h->size == 0;
}

// Define a function to get the minimum cost in a heap
int getMinCost(Heap *h) {
    return h->data[0].cost;
}

// Define a function to get the minimum ID in a heap
int getMinID(Heap *h) {
    return h->data[0].id;
}

// Define a function to update the cost of a state in a heap
void updateCost(Heap *h, int id, int cost) {
    for (int i = 0; i < h->size; i++) {
        if (h->data[i].id == id) {
            h->data[i].cost = cost;
            break;
        }
    }
}

// Define a function to convert (x, y, dir) to a unique ID
int toID(int x, int y, int dir) {
    return 4 * (x + y * 100) + dir;
}

// Define a function to convert an ID back to (x, y, dir)
void splatID(int id, int *x, int *y, int *dir) {
    *x = id / 4 % 100;
    *y = id / 4 / 100;
    *dir = id % 4;
}

// Define a function to check if a position is within bounds
bool isInBounds(int x, int y, int H, int W) {
    return 0 <= x && x < W && 0 <= y && y < H;
}

// Define a function to check if a position is a wall
bool isWall(char c) {
    return c == '@';
}

// Define a function to check if a position is a destination
bool isDestination(int x, int y, int x2, int y2) {
    return x == x2 && y == y2;
}

// Define a function to get the cost of moving in a direction
int getCost(int dir) {
    return dir == 0 || dir == 2 ? 1 : 0;
}

// Define a function to get the next position in a direction
void getNextPosition(int x, int y, int dir, int *nx, int *ny) {
    *nx = x + (dir == 0 || dir == 1 ? 1 : -1);
    *ny = y + (dir == 0 || dir == 3 ? 1 : -1);
}

// Define a function to get the next direction
int getNextDirection(int dir) {
    return (dir + 1) % 4;
}

// Define a function to get the next ID
int getNextID(int x, int y, int dir, int nx, int ny, int ndir) {
    return toID(nx, ny, ndir);
}

// Define a function to get the next cost
int getNextCost(int cost, int k) {
    return (cost + k - 1) / k * k;
}

// Define a function to get the next state
State getNextState(int x, int y, int dir, int nx, int ny, int ndir, int ncost) {
    return (State){ncost, getNextID(nx, ny, ndir, nx, ny, ndir)};
}

// Define a function to get the minimum cost to reach the destination
int getMinCostToDestination(int x2, int y2, int H, int W, int *dist) {
    int ans = INF;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
        if (dist[id] < ans) {
            int d2 = (dist[id] + 1) / 2;
            if (d2 < ans) {
                ans = d2;
            }
        }
    }
    return ans;
}

// Define a function to solve the problem
void solve(int H, int W, int K) {
    // Initialize the distance array with infinity
    int *dist = (int *)malloc(sizeof(int) * 1000000);
    for (int i = 0; i < 1000000; i++) {
        dist[i] = INF;
    }

    // Initialize the priority queue (min-heap) with starting states
    Heap q;
    initHeap(&q);
    for (int i = 0; i < 4; i++) {
        pushHeap(&q, (HeapElement){0, toID(0, 0, i)});
    }

    // Main loop for Dijkstra's algorithm
    while (!isEmptyHeap(&q)) {
        State now = popHeap(&q);
        int x, y, dir;
        splatID(now.id, &x, &y, &dir);

        // Skip if the current position is a wall
        if (isWall(c[y][x])) {
            continue;
        }
        // Skip if we have already found a better cost for this state
        if (dist[now.id] <= now.cost) {
            continue;
        }
        // Update the distance for the current state
        dist[now.id] = now.cost;

        // If we reached the destination, exit the loop
        if (isDestination(x, y, x2, y2)) {
            break;
        }

        // Explore all four possible directions
        for (int i = 0; i < 4; i++) {
            int ncost = (now.cost + K - 1) / K * K; // Calculate the new cost
            int nid = getNextID(x, y, dir, x, y, i); // Get the new ID for the direction
            if (dist[nid] <= ncost) { // Skip if we have a better cost
                continue;
            }
            // Push the new state into the priority queue
            pushHeap(&q, getNextState(x, y, dir, x, y, i, ncost));
        }

        // Move in the current direction
        int nx, ny;
        getNextPosition(x, y, dir, &nx, &ny);
        // Check if the new position is within bounds
        if (isInBounds(nx, ny, H, W)) {
            int ncost = now.cost + getCost(dir); // Increment the cost for moving forward
            int nid = getNextID(nx, ny, dir, nx, ny, dir); // Get the new ID for the position
            if (dist[nid] <= ncost) { // Skip if we have a better cost
                continue;
            }
            // Push the new state into the priority queue
            pushHeap(&q, getNextState(nx, ny, dir, nx, ny, dir, ncost));
        }
    }

    // Determine the minimum cost to reach the destination
    int ans = getMinCostToDestination(x2, y2, H, W, dist);

    // Output the result
    if (ans < INF) {
        printf("%d\n", ans); // Print the minimum cost
    } else {
        printf("-1\n"); // Print -1 if the destination is unreachable
    }
}

// Define the grid representation
char c[100][100];

// Define the starting and ending coordinates
int x1, y1, x2, y2;

int main() {
    // Read the dimensions of the grid and the cost parameter
    int H, W, K;
    scanf("%d %d %d", &H, &W, &K);
    // Read the starting and ending coordinates, adjusting for 0-based indexing
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--; y1--; x2--; y2--; // Adjust for 0-based indexing

    // Read the grid representation
    for (int y = 0; y < H; y++) {
        scanf("%s", c[y]);
    }

    // Solve the problem
    solve(H, W, K);

    return 0;
}

