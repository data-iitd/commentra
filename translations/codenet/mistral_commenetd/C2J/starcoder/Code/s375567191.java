
import java.util.*;

public class Main {
  public static void main(String[] args) {
    int time, n, g[][] = new int[MAX][MAX] = {0}; // initialize time, number of vertices, and 2D adjacency matrix g
    int d[], f[], color[] = new int[MAX] = {WHITE}; // initialize depth, finish, and color arrays
    Scanner sc = new Scanner(System.in);

    time = 0; // initialize time counter
    n = sc.nextInt(); // read the number of vertices in the graph

    for(int i=0;i<n;i++){ // iterate through each vertex in the graph
      int x = sc.nextInt(); // read the number of edges and their destinations for the current vertex
      int y = sc.nextInt();

      for(int j=0;j<y;j++){ // iterate through all the edges for the current vertex
        int z = sc.nextInt(); // read the destination vertex for the current edge
        g[x-1][z-1] = 1; // mark that there is an edge between 'x' and 'z'
      }
    }

    for(int i=0;i<n;i++) // iterate through all the vertices in the graph
      if(color[i] == WHITE) // if 'i' is not yet visited
        visit(i); // recursively call DFS on 'i'

    for(int i=0;i<n;i++) // print the depth, finish, and vertex number for each vertex
      System.out.printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  public static void visit(int u){ // function to perform Depth First Search (DFS) from vertex 'u'
    int i;

    color[u] = GRAY; // mark the current vertex as 'gray'
    d[u] = ++time; // assign depth value to the current vertex

    for(i=0;i<n;i++){ // iterate through all the adjacent vertices of 'u'
      if(g[u][i] == 0) // if there is no edge between 'u' and 'i'
        continue;
      if(color[i] == WHITE) // if 'i' is not yet visited
        visit(i); // recursively call DFS on 'i'
    }

    color[u] = BLACK; // mark the current vertex as 'black'
    f[u] = ++time; // assign finish value to the current vertex
  }
}

