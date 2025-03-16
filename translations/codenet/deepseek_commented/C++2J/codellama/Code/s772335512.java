// Step 1: Import the Scanner class.
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        // Step 2: Define global variables
        // G is a vector of vectors representing the graph.
        int[][] G = new int[100000][];
        // used is a boolean array to keep track of visited nodes.
        boolean[] used = new boolean[100000];
        // grundy is an array to store the Grundy number of each node.
        int[] grundy = new int[100000];

        // Step 3: Define the dfs function
        // The function dfs is used to perform a depth-first search on the graph.
        void dfs(int v){
            // It marks the current node as visited.
            used[v] = true;
            // It initializes the Grundy number of the current node to 0.
            grundy[v] = 0;
            // It iterates through all the neighbors of the current node.
            for(int i = 0; i < G[v].length; i++){
                // If a neighbor has not been visited, it recursively calls dfs on that neighbor.
                if(!used[G[v][i]]){
                    dfs(G[v][i]);
                    // It updates the Grundy number of the current node by performing the XOR operation with (grundy[G[v][i]] + 1).
                    grundy[v] ^= (grundy[G[v][i]]+1);
                }
            }
        }

        // Step 4: Main function
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        G = new int[N][];
        for(int i = 0; i < N-1; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            x--; y--;
            G[x] = new int[1];
            G[x][0] = y;
            G[y] = new int[1];
            G[y][0] = x;
        }
        dfs(0);
        if(grundy[0] != 0){
            // It prints "Alice" if the Grundy number is not 0, otherwise it prints "Bob".
            System.out.println("Alice");
        }else{
            System.out.println("Bob");
        }
    }
}

