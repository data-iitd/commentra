#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

// Array to store colors assigned to each point
int* colors; 

int main() { 
    // Create a scanner to read input
    int n, m, me, you, length; 
    scanf("%d", &n); 
    
    // Calculate the number of edges (m = n - 1 for a tree)
    m = n - 1; 
    
    // Initialize colors array with -1 (indicating uncolored)
    colors = (int*)malloc(n * sizeof(int)); 
    memset(colors, -1, n * sizeof(int)); 
    
    // Create an array of Point objects
    Point* points = (Point*)malloc(n * sizeof(Point)); 
    
    // Initialize each Point object with its index
    for (int i = 0; i < n; i++) { 
        points[i].name = i; 
    } 
    
    // Read edges and establish friendships between points
    while (m-- > 0) { 
        scanf("%d %d %d", &me, &you, &length); 
        
        // Establish friendship in both directions
        points[me].becomeFriend(&points[you], length); 
        points[you].becomeFriend(&points[me], length); 
    } 
    
    // Start DFS from the first point (index 0)
    dfs(&points[0], 0); 
    
    // Output the colors assigned to each point
    for (int i = 0; i < n; i++) { 
        printf("%d\n", colors[i]); 
    } 
    
    return 0; 
} 

// Class representing a point in the graph
typedef struct Point { 
    int name; // Unique identifier for the point
    int* friends; // Map to store friends and their friendship lengths
    int friends_size; // Number of friends
} Point; 

// Method to establish friendship with another point
void becomeFriend(Point* p, Point* friend, int length) { 
    // Add friend with the specified length
    p->friends = (int*)realloc(p->friends, (p->friends_size + 1) * sizeof(int)); 
    p->friends[p->friends_size++] = friend->name; 
    p->friends = (int*)realloc(p->friends, (p->friends_size + 1) * sizeof(int)); 
    p->friends[p->friends_size++] = length; 
} 

// Depth-First Search (DFS) to assign colors based on friendship lengths
void dfs(Point* p, int length) { 
    // Check if the point has already been colored
    bool alreadyKnown = colors[p->name] != -1; 
    if (alreadyKnown) return; // Exit if already colored
    
    // Assign color based on the length (even or odd)
    if (length % 2 == 0) { 
        colors[p->name] = 0; // Even length -> color 0
    } else { 
        colors[p->name] = 1; // Odd length -> color 1
    } 
    
    // Recursively visit all friends of the current point
    for (int i = 0; i < p->friends_size; i += 2) { 
        Point* friend = &points[p->friends[i]]; // Get the friend point
        int length2 = p->friends[i + 1]; // Get the length of friendship
        dfs(friend, length + length2); // Recursive DFS call
    } 
} 

