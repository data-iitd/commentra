
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); // Read the number of nodes from the user

        int[][] A = new int[n][n]; // Initialize the 2D array A with zeros

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                A[i][j] = 0;
            }
        }

        // Read the adjacency matrix from the user
        for(int i=0;i<n;i++){
            int k = sc.nextInt();
            for(int j=0;j<k;j++){
                int v = sc.nextInt();
                A[i][v-1] = 1; // Store the edge weight (assumed to be 1) in the adjacency matrix
            }
        }

        aaaaa(n,A); // Call the function aaaaa() to perform the required computation

    }

    public static void aaaaa(int n, int[][] A){
        int[] color = new int[n]; // Initialize the array color with zeros
        int[] d = new int[n]; // Initialize the array d with zeros
        int[] f = new int[n]; // Initialize the array f with zeros
        int TT = 0; // Initialize the time variable TT to 0

        // Initialize all nodes with color SHIRO (white)
        for(int i=0;i<n;i++){
            color[i] = 0;
        }

        // Perform Depth First Search (DFS) from each unvisited node
        for(int u=0;u<n;u++){
            if(color[u] == 0){
                bbbbb(u,n,A,color,d,f,TT);
            }
        }

        // Print the results
        for(int i = 0;i<n;i++){
            System.out.println(i+1 + " " + d[i] + " " + f[i]);
            System.out.println("Node " + (i+1) + " is visited at time " + d[i] + " and its finishing time is " + f[i] + ".");
        }
    }

    public static void bbbbb(int k, int n, int[][] A, int[] color, int[] d, int[] f, int TT){
        color[k] = 1; // Mark the current node as visited (gray)
        TT++; // Increment the time variable TT
        d[k] = TT; // Set the discovery time for the current node

        // Explore all neighbors of the current node
        for(int v=0;v<n;v++){
            if(A[k][v] == 1 && color[v] == 0){ // If the neighbor is unvisited
                bbbbb(v,n,A,color,d,f,TT); // Recursively call the function bbbbb() for the neighbor
            }
        }

        // Mark the current node as finished (black)
        color[k] = 2;
        f[k] = ++TT; // Set the finishing time for the current node
    }

}

