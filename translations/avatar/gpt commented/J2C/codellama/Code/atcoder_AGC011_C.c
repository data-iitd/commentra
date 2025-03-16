#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <time.h>
#include <float.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>
#include <mqueue.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <monetary.h>
#include <nl_types.h>
#include <langinfo.h>
#include <stropts.h>
#include <sys/ioctl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/statvfs.h>
#include <sys/vfs.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netpacket/packet.h>
#include <poll.h>
#include <resolv.h>
#include <netdb.h>
#include <sys/uio.h>
#include <utime.h>
#include <sys/un.h>
#include <wchar.h>
#include <wctype.h>
#include <wordexp.h>

// Adjacency list representation of the graph
typedef struct {
    int *graph;
    int *visited;
    int *color;
    long one;
    long bipartite;
    long count;
    bool mujun;
} Graph;

// Depth-First Search (DFS) method to explore the graph
int dfs(Graph *graph, int a, int c) {
    // If the node has already been visited
    if (graph->visited[a]) {
        // Check for color conflict indicating the graph is not bipartite
        if (graph->color[a] >= 0 && graph->color[a] != c) graph->mujun = true; 
        return 0; 
    }
    // Mark the node as visited and assign it a color
    graph->visited[a] = true; 
    graph->color[a] = c; 
    int total = 1; // Count the current node

    // Recursively visit all adjacent nodes with alternate color
    for (int b = 0; b < graph->graph[a]; ++b) {
        total += dfs(graph, graph->graph[a + b], 1 - c); 
    }
    return total; // Return the total count of nodes in this component
}

// Main execution method for the program
void run(Graph *graph) {
    // Read number of nodes and edges
    int n = 0; 
    int m = 0; 
    scanf("%d %d", &n, &m); 

    // Initialize the graph
    graph->graph = (int *)malloc(n * sizeof(int)); 
    for (int i = 0; i < n; ++i) 
        graph->graph[i] = (int *)malloc(n * sizeof(int)); 

    // Read edges and populate the graph
    for (int i = 0; i < m; ++i) {
        int u = 0; 
        int v = 0; 
        scanf("%d %d", &u, &v); 
        graph->graph[u - 1][v - 1] = 1; 
        graph->graph[v - 1][u - 1] = 1; 
    }

    // Initialize visited and color arrays
    graph->visited = (int *)malloc(n * sizeof(int)); 
    graph->color = (int *)malloc(n * sizeof(int)); 
    memset(graph->color, -1, n * sizeof(int)); // Set all colors to -1 (uncolored)

    // Initialize counters
    graph->one = 0; 
    graph->bipartite = 0; 
    graph->count = 0; 

    // Iterate through all nodes to find connected components
    for (int i = 0; i < n; ++i) {
        if (graph->visited[i]) continue; // Skip already visited nodes
        graph->count++; // Increment component count
        graph->mujun = false; // Reset bipartite flag
        int kind = dfs(graph, i, 0); // Perform DFS starting from node i

        // Update counters based on the results of DFS
        if (kind == 1) graph->one++; 
        else if (!graph->mujun) graph->bipartite++; 
    }

    // Calculate the total based on the counts of components
    long total = graph->one * (2 * n - graph->one); 
    total += (graph->count - graph->one) * (graph->count - graph->one); 
    total += graph->bipartite * graph->bipartite; 

    // Output the final result
    printf("%ld\n", total); 
}

// Main method to start the program
int main(int argc, char *argv[]) {
    Graph graph; 
    run(&graph); 
    return 0; 
}

