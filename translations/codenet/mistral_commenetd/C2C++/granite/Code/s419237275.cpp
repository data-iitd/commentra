

#include <iostream>

#define N 200
#define SHIRO 0
#define HAI 1
#define KURO 2

void aaaaa();
void bbbbb(int);

int n,A[N][N];
int color[N],d[N],f[N];
int TT;

int main() {

  int u,k,v;
  int i,j;

  std::cout << "Enter the number of nodes: ";
  std::cin >> n; // Read the number of nodes from the user

  // Initialize the 2D array A with zeros
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j] = 0;
    }
  }

  // Read the adjacency matrix from the user
  for(i=0;i<n;i++){
    std::cout << "Enter the number of neighbors for node " << i+1 << ": ";
    std::cin >> k;
    for(j=0;j<k;j++){
      std::cout << "Enter the neighbor index: ";
      std::cin >> v;
      A[i][v-1] = 1; // Store the edge weight (assumed to be 1) in the adjacency matrix
    }
  }

  aaaaa(); // Call the function aaaaa() to perform the required computation

  return 0;
}


void aaaaa() {
  int u,i;

  // Initialize all nodes with color SHIRO (white)
  for(i=0;i<n;i++){
    color[i] = SHIRO;
  }

  TT = 0; // Initialize the time variable TT to 0

  // Perform Depth First Search (DFS) from each unvisited node
  for(u=0;u<n;u++){
    if(color[u] == SHIRO){
      bbbbb(u);
    }
  }

  // Print the results
  for(i = 0;i<n;i++){
    std::cout << i+1 << " " << d[i] << " " << f[i] << std::endl;
    std::cout << "Node " << i+1 << " is visited at time " << d[i] << " and its finishing time is " << f[i] << "." << std::endl;
  }
}

void bbbbb(int k) {
  int v;
  color[k] = HAI; // Mark the current node as visited (gray)
  TT++; // Increment the time variable TT
  d[k] = TT; // Set the discovery time for the current node

  // Explore all neighbors of the current node
  for(v=0;v<n;v++){
    if(A[k][v] == 1 && color[v] == SHIRO){ // If the neighbor is unvisited
      bbbbb(v); // Recursively call the function bbbbb() for the neighbor
    }
  }

  // Mark the current node as finished (black)
  color[k] = KURO;
  f[k] = ++TT; // Set the finishing time for the current node
}

