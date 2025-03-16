
import java.util.ArrayList; // Importing ArrayList for creating graph
import java.util.List; // Importing List for creating graph
import java.util.Scanner; // Importing Scanner for taking input

public class Main {

 static int n; // Declaring the number of vertices in the graph
 static List<ArrayList<Edge>> g; // Declaring a 2D ArrayList to represent the graph
 static int[] ans; // Declaring an array to store the answer

 public static void main(String[] args) {
 Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input
 int n = Integer.parseInt(sc.next()); // Reading the number of vertices from the input
 g = new ArrayList<>(); // Creating an empty ArrayList to store the graph
 for (int i = 0; i < n; i++) { // Looping through each vertex to create an empty ArrayList for its adjacent edges
 g.add(new ArrayList<>());
 }

 for (int i = 0; i < n - 1; i++) { // Looping through each edge to add it to the graph
 int a = Integer.parseInt(sc.next()) - 1; // Reading the first vertex of the edge
 int b = Integer.parseInt(sc.next()) - 1; // Reading the second vertex of the edge
 g.get(a).add(new Edge(i, b)); // Adding the edge from vertex 'a' to 'b'
 g.get(b).add(new Edge(i, a)); // Adding the edge from vertex 'b' to 'a'
 }

 ans = new int[n - 1]; // Creating an array of size 'n-1' to store the answer
 dfs(0, -1, -1); // Calling the DFS function to find the answer

 int max = 0; // Initializing the maximum answer to 0
 for (int temp : ans) { // Looping through the array to find the maximum answer
 max = Math.max(max, temp);
 }

 System.out.println(max); // Printing the maximum answer
 for (int c : ans) { // Printing all the answers
 System.out.println(c);
 }
 }

 static void dfs(int to, int color, int parents) { // Function to perform Depth First Search
 int k = 1; // Initializing the color to 1
 for (Edge e : g.get(to)) { // Looping through each edge adjacent to the current vertex
 if (e.to == parents) continue; // Skipping the edge if it is already colored with the current color
 if (k == color) k++; // Incrementing the color if the current vertex is already colored with the same color
 ans[e.id] = k; // Storing the answer in the array
 dfs(e.to, k, to); // Recursively calling the DFS function for the adjacent vertex
 k++; // Incrementing the color for the next vertex
 }
 }

 static class Edge { // Class to represent an edge
 Edge(int id, int to) { // Constructor to initialize the edge with its id and the vertex it connects to
 this.id = id;
 this.to = to;
 }
 int id; // Storing the id of the edge
 int to; // Storing the vertex the edge connects to
 }
}