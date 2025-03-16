import java.util.*;

public class Prim {
    public static void main(String[] args) {
        int n, e, i, j;
        int[] d = new int[MAX];
        int[] pi = new int[MAX];
        int[] color = new int[MAX];
        int min, u, v, sum = 0;

        // Read the number of vertices
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // Read the adjacency matrix representation of the graph
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                e = sc.nextInt();
                if(e == -1){
                    G[i][j] = INF; // If input is -1, set the edge weight to infinity
                } else {
                    G[i][j] = e;   // Otherwise, set the edge weight to the input value
                }
            }
        }

        // Call the Prim's algorithm function to find the MST
        prim();
        return 0; // Return success
    }
}

