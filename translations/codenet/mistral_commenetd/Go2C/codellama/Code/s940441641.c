
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

// Function to read a single integer from standard input
int ReadInt()
{
    int i;
    scanf("%d", &i);
    return i;
}

// Function to read a single string from standard input
char* ReadString()
{
    char* s = malloc(1000000);
    scanf("%s", s);
    return s;
}

// Function to read multiple integers from standard input
int* ReadInts(int n)
{
    int* v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    return v;
}

// Function to read the initial dimensions and number of moves from standard input
void ReadInput(int* H, int* W, int* K, int* x1, int* y1, int* x2, int* y2)
{
    *H = ReadInt();
    *W = ReadInt();
    *K = ReadInt();
    *x1 = ReadInt() - 1;
    *y1 = ReadInt() - 1;
    *x2 = ReadInt() - 1;
    *y2 = ReadInt() - 1;
    *y1 = *x1;
    *x1 = *y1;
    *y2 = *x2;
    *x2 = *y2;
}

// Function to read the input grid from standard input
char** ReadGrid(int H, int W)
{
    char** c = malloc(H * sizeof(char*));
    for (int y = 0; y < H; y++)
    {
        c[y] = ReadString();
    }
    return c;
}

// Function to calculate the index of a cell in the grid based on its position and direction
int toID(int x, int y, int dir)
{
    return 4 * (W * y + x) + dir;
}

// Function to extract the position and direction from the index of a cell
void splatID(int id, int* x, int* y, int* dir)
{
    *x = id % W;
    *y = id / W;
    *dir = id % 4;
}

// Function to initialize the distances to all cells to infinity and add the starting cell to the heap
void initDist(int H, int W, int K, int x1, int y1, int x2, int y2)
{
    int* dist = malloc(W * H * 4 * sizeof(int));
    for (int i = 0; i < W * H * 4; i++)
    {
        dist[i] = INT_MAX;
    }
    for (int i = 0; i < 4; i++)
    {
        dist[toID(x1, y1, i)] = 0;
    }
}

// Function to process the heap until the goal cell is reached or all cells have been visited
void processHeap()
{
    while (q.size > 0)
    {
        State now = q.pop();
        int x, y, dir;
        splatID(now.ID, &x, &y, &dir);
        if (x == x2 && y == y2)
        {
            break;
        }
        if (dist[now.ID] <= now.Cost)
        {
            continue;
        }
        dist[now.ID] = now.Cost;
        for (int i = 0; i < 4; i++)
        {
            int nCost = now.Cost + K;
            int nID = toID(x, y, i);
            if (dist[nID] <= nCost)
            {
                continue;
            }
            q.push(State{
                Cost: nCost,
                ID:   nID,
            });
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H)
        {
            int nCost = now.Cost + 1;
            int nID = toID(nx, ny, dir);
            if (dist[nID] <= nCost)
            {
                continue;
            }
            q.push(State{
                Cost: nCost,
                ID:   nID,
            });
        }
    }
}

// Function to calculate the minimum number of moves to reach the goal cell
int calculateAnswer()
{
    int ans = INT_MAX;
    for (int i = 0; i < 4; i++)
    {
        int id = toID(x2, y2, i);
        if (dist[id] < ans)
        {
            ans = dist[id];
        }
    }
    return ans;
}

// Function to print the result
void printResult()
{
    if (ans < INT_MAX)
    {
        printf("%d\n", ans);
    }
    else
    {
        printf("-1\n");
    }
}

// Function to scan multiple arguments from standard input
void Scan(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

// Function to scan multiple arguments from standard input
void Scan(char** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = ReadString();
    }
}

// Types
typedef struct State
{
    int Cost;
    int ID;
} State;

typedef struct Heap
{
    State* data;
    int size;
    int capacity;
} Heap;

// Functions
void Heap_push(Heap* h, State v)
{
    if (h->size == h->capacity)
    {
        h->capacity *= 2;
        h->data = realloc(h->data, h->capacity * sizeof(State));
    }
    h->data[h->size++] = v;
}

State Heap_pop(Heap* h)
{
    State v = h->data[0];
    h->data[0] = h->data[--h->size];
    return v;
}

// Global variables
int* dist;
Heap q;
int Inf = INT_MAX;

// Constants
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// Main function
int main()
{
    // Read the input dimensions, number of moves, and starting and ending positions
    int H, W, K, x1, y1, x2, y2;
    ReadInput(&H, &W, &K, &x1, &y1, &x2, &y2);

    // Read the input grid
    char** c = ReadGrid(H, W);

    // Initialize the distances and add the starting cell to the heap
    initDist(H, W, K, x1, y1, x2, y2);

    // Process the heap until the goal cell is reached or all cells have been visited
    processHeap();

    // Calculate the minimum number of moves to reach the goal cell
    int ans = calculateAnswer();

    // Print the result
    printResult();

    return 0;
}

