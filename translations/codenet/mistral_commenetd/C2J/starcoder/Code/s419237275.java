
import java.util.*;

public class Main {

  public static void main(String[] args) {

    int n,A[][];
    int color[],d[],f[];
    int TT;

    Scanner sc = new Scanner(System.in);

    System.out.print("Enter the number of nodes: ");
    n = sc.nextInt(); // Read the number of nodes from the user

    // Initialize the 2D array A with zeros
    A = new int[n][n];
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        A[i][j] = 0;
      }
    }

    // Read the adjacency matrix from the user
    for(int i=0;i<n;i++){
      System.out.print("Enter the number of neighbors for node " + (i+1) + ": ");
      int k = sc.nextInt();
      for(int j=0;j<k;j++){
        System.out.print("Enter the neighbor index: ");
        int v = sc.nextInt();
        A[i][v-1] = 1; // Store the edge weight (assumed to be 1) in the adjacency matrix
      }
    }

    aaaaa(A,n); // Call the function aaaaa() to perform the required computation

    return;
  }

  public static void aaaaa(int A[][],int n) {
    int u,i;

    // Initialize all nodes with color SHIRO (white)
    color = new int[n];
    for(i=0;i<n;i++){
      color[i] = SHIRO;
    }

    TT = 0; // Initialize the time variable TT to 0

    // Perform Depth First Search (DFS) from each unvisited node
    for(u=0;u<n;u++){
      if(color[u] == SHIRO){
        bbbbb(A,u);
      }
    }

    // Print the results
    for(i = 0;i<n;i++){
      System.out.println(i+1 + " " + d[i] + " " + f[i]);
      System.out.println("Node " + (i+1) + " is visited at time " + d[i] + " and its finishing time is " + f[i] + ".");
    }
  }

  public static void bbbbb(int A[][],int k) {
    int v;
    color[k] = HAI; // Mark the current node as visited (gray)
    TT++; // Increment the time variable TT
    d[k] = TT; // Set the discovery time for the current node

    // Explore all neighbors of the current node
    for(v=0;v<n;v++){
      if(A[k][v] == 1 && color[v] == SHIRO){ // If the neighbor is unvisited
        bbbbb(A,v); // Recursively call the function bbbbb() for the neighbor
      }
    }

    // Mark the current node as finished (black)
    color[k] = KURO;
    f[k] = ++TT; // Set the finishing time for the current node
  }

}

