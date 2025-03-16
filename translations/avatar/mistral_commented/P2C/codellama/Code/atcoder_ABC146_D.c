#######
# Code
#######

# Include header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a graph
struct Graph
{
    int V;
    int E;
    int** adj;
};

// Structure to represent a queue
struct Queue
{
    int front;
    int rear;
    int* array;
};

// Function to create a queue of given capacity
struct Queue* createQueue(int capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue)
{
    return (queue->front == queue->rear);
}

// Function to check if the queue is full
int isFull(struct Queue* queue)
{
    return (queue->rear == queue->capacity - 1);
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    if (queue->front == -1)
        queue->front = 0;
}

// Function to remove an item from the queue
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return item;
}

// Function to perform Breadth First Search (BFS)
int bfs(struct Graph* graph, int start)
{
    int* visited = (int*) malloc(graph->V * sizeof(int));
    int* node2color = (int*) malloc(graph->V * sizeof(int));
    struct Queue* queue = createQueue(graph->V);
    int K = -1;

    // Initialize visited and node2color arrays
    for (int i = 0; i < graph->V; i++)
    {
        visited[i] = 0;
        node2color[i] = -1;
    }

    // Mark the starting node as visited and enqueue it
    visited[start] = 1;
    enqueue(queue, start);

    // BFS algorithm
    while (!isEmpty(queue))
    {
        // Dequeue the next node from the queue
        int q = dequeue(queue);

        // Initialize color for the current node
        int color = 0;

        // Traverse through all neighbors of the current node
        for (int i = 0; i < graph->adj[q]->size; i++)
        {
            // Skip if the neighbor is already visited
            int nex = graph->adj[q]->array[i];
            if (visited[nex])
                continue;

            // Mark the neighbor as visited and assign it a color
            visited[nex] = 1;
            color += 1;

            // If the color of the current node is same as its neighbor, assign a new color to the neighbor
            if (color == node2color[q])
                color += 1;

            // Update node2color and E dictionary with the new color
            node2color[nex] = color;

            // Add the neighbor to the queue
            enqueue(queue, nex);
        }

        // Update the maximum color found so far
        K = max(K, color);
    }

    // Return the maximum color
    return K;
}

// Function to read input and call bfs function
int main()
{
    // Read number of nodes from the input
    int N;
    scanf("%d", &N);

    // Initialize graph as a list of deques and empty dictionary for edges
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = N;
    graph->E = 0;
    graph->adj = (int**) malloc(graph->V * sizeof(int*));
    for (int i = 0; i < graph->V; i++)
    {
        graph->adj[i] = (int*) malloc(sizeof(int));
        graph->adj[i]->size = 0;
    }

    // Read edges from the input and add them to the graph
    for (int i = 0; i < N-1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph->adj[a]->array[graph->adj[a]->size++] = b;
        graph->adj[b]->array[graph->adj[b]->size++] = a;
        graph->E++;
    }

    // Call bfs function and print the result
    int K = bfs(graph, 0);
    printf("%d\n", K);

    // Print colors of all edges
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->adj[i]->size; j++)
        {
            int nex = graph->adj[i]->array[j];
            if (i < nex)
                printf("%d ", node2color[i]);
        }
    }

    // Free memory
    for (int i = 0; i < graph->V; i++)
        free(graph->adj[i]);
    free(graph->adj);
    free(graph);
    free(visited);
    free(node2color);
    free(queue->array);
    free(queue);

    return 0;
}

