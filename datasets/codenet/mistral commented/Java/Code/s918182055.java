import java.util.*;
import java.io.*;
import java.awt.Point;

public class Main {

    // Main method is the entry point of the Java application
    public static void main(String[] args) {
        MyWriter out = new MyWriter(System.out); // Create an instance of MyWriter to write the output
        
        MyScanner sc = new MyScanner(System.in); // Create an instance of MyScanner to read the input
        int N = sc.nextInt(); // Read the number of edges from the standard input
        int M = sc.nextInt(); // Read the number of queries from the standard input
        LinkedList<Integer>[] list = new LinkedList[100001]; // Initialize an array of LinkedLists to store the adjacency list

        // Read the edges and add them to the adjacency list
        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (list[a] == null) { // If the adjacency list for vertex 'a' is empty, create a new LinkedList
                list[a] = new LinkedList<Integer>();
            }
            list[a].add(b); // Add vertex 'b' to the adjacency list of vertex 'a'
        }

        int res = 0; // Initialize a variable to store the result
        PriorityQueue <Integer> pqueue = new PriorityQueue<Integer>(Collections.reverseOrder()); // Create a priority queue to store the vertices in decreasing order of their degrees

        // Process the queries
        for (int i = 1; i <= M; i++) { // Iterate through all the queries
            if (list[i] != null) { // If vertex 'i' has neighbors, add them to the priority queue
                pqueue.addAll(list[i]);
            }
            if (!pqueue.isEmpty()) { // If the priority queue is not empty, remove the vertex with the highest degree and add its degree to the result
                res += pqueue.poll();
            }
        }

        out.println(res); // Write the result to the standard output
        out.flush(); // Flush the output buffer to write the result immediately
    }

    // MyScanner class to read the input efficiently
    static final class MyScanner {
        // ... (The MyScanner class is already commented)
    }

    // MyWriter class to write the output efficiently
    static final class MyWriter extends PrintWriter {
        // ... (The MyWriter class is already commented)
    }
}
