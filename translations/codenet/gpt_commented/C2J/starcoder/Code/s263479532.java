import java.util.*;

public class Prim {
    public static void main(String[] args) {
        int n, G[][];
        int i, j;

        // Read the number of vertices in the graph
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // Read the adjacency matrix representation of the graph
        G = new int[n][n];
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                G[i][j] = sc.nextInt();
            }
        }

        // Call Prim's algorithm and print the total weight of the minimum spanning tree
        System.out.println(prim(G, n));
    }

    public static int prim(int G[][], int n) {
        int u, i, v, mincost, d[] = new int[n], pi[] = new int[n], color[] = new int[n], sum=0;

        // Initialize arrays for distance, parent, and color of each vertex
        for(u=0; u<n; u++)
        {
            d[u] = Integer.MAX_VALUE;      // Set initial distances to infinity
            pi[u] = -1;     // Set initial parents to NIL
            color[u] = 0; // Set initial colors to WHITE (unvisited)
        }

        // Start with the first vertex
        d[0] = 0;

        // Main loop to find the minimum spanning tree
        while(1)
        {
            mincost = Integer.MAX_VALUE;

            // Find the vertex with the minimum cost edge that is not yet included in the MST
            for(i=0; i<n; i++)
            {
                if(color[i] == 0 && d[i] < mincost)
                {
                    mincost = d[i];
                    u = i; // Update the vertex to be included in the MST
                }
            }

            // If no vertex is found, break the loop
            if(mincost == Integer.MAX_VALUE) break;

            // Mark the selected vertex as BLACK (included in the MST)
            color[u] = 1;

            // Update the distances and parents for the adjacent vertices
            for(v=0; v<n; v++)
            {
                // If the vertex is not yet included in the MST and the edge weight is less than the current known distance
                if(color[v] == 0 && G[u][v] < d[v] && G[u][v]!= -1)
                {
                    pi[v] = u;    // Update the parent of vertex v
                    d[v] = G[u][v]; // Update the distance to vertex v
                }
            }
        }

        // Calculate the total weight of the minimum spanning tree
        for(i=0; i<n; i++)
        {
            if(d[i]!= Integer.MAX_VALUE) sum += d[i]; // Sum up the distances of included vertices
        }

        // Return the total weight of the minimum spanning tree
        return sum;
    }
}

