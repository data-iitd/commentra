
import java.util.Iterator; // Importing the Iterator interface for traversing collections.
import java.util.LinkedList; // Importing the LinkedList class for implementing a linked list.
import java.util.Scanner; // Importing the Scanner class for reading input from the user.

public class Main {
 int count; // Declaring and initializing the count variable to 0.
 boolean[] seen; // Declaring and initializing the seen array to keep track of visited nodes.
 int path = 0, cycle = 1; // Declaring and initializing the path and cycle variables.
 LinkedList<LinkedList<Integer>> graph; // Declaring and initializing the graph as a 2D linked list.

 public int dfs(int child, int par) {
 if (seen[child] == true) { // Checking if the current node has already been visited.
 return cycle; // If it has, then there is a cycle in the graph and we return 1.
 }
 seen[child] = true; // Marking the current node as visited.

 for (Integer i : graph.get(child)) { // Iterating through the neighbors of the current node.
 if (i != par) { // Checking if the neighbor is not the parent node.
 this.count++; // Incrementing the count of edges traversed.
 if (dfs(i, child) == cycle) { // Recursively calling the dfs function on the neighbor.
 return cycle; // If there is a cycle, then we return 1.
 }
 }
 }
 return path; // If there is no cycle, then we return 0.
 }

 public static void main(String[] args) {
 Scanner sc = new Scanner(System.in); // Creating a new Scanner object for reading input.
 int m = sc.nextInt(); // Reading the number of nodes in the graph.
 int n = sc.nextInt(); // Reading the number of edges in the graph.
 Main ft = new Main(); // Creating a new instance of the Main class.
 ft.graph = new LinkedList<>(); // Initializing the graph as an empty 2D linked list.
 ft.seen = new boolean[m + 1]; // Initializing the seen array as a boolean array of size (m+1).

 for (int i = 0; i <= m; i++) { // Initializing the graph with empty linked lists for each node.
 ft.graph.add(new LinkedList<Integer>());
 }

 for (int i = 0; i < n; i++) { // Reading the edges from the input and adding them to the graph.
 int x = sc.nextInt();
 int y = sc.nextInt();
 ft.graph.get(x).add(y); // Adding an edge from x to y.
 ft.graph.get(y).add(x); // Adding an edge from y to x.
 }

 int toremove = 0; // Initializing the toremove variable to 0.
 for (int i = 1; i <= m; i++) { // Iterating through all the nodes in the graph.
 if (!ft.seen[i]) { // If the current node has not been visited.
 ft.count = 0; // Resetting the count of edges traversed to 0.
 if (ft.dfs(i, 0) == ft.cycle) { // If there is a cycle in the subgraph rooted at the current node.
 if (ft.count % 2 == 1) { // If the number of edges traversed is odd.
 toremove++; // Increment the toremove variable.
 }
 }
 }
 }

 if ((m - toremove) % 2 == 1) { // Checking if the number of nodes is odd.
 toremove++; // If it is, then increment the toremove variable.
 }

 System.out.println(toremove); // Printing the result.
 }
}