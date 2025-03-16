import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        // Start a new thread to run the MyRunnable class
        new Thread(null, new MyRunnable(), "", 1 << 26).start();
    }
}

class MyRunnable implements Runnable {
    @Override
    public void run() {
        int n; // Number of elements
        int k; // A specific threshold value
        List<Integer> as = new ArrayList<>(); // List to store input values

        // Use a Scanner to read input values from the console
        try (Scanner sc = new Scanner(System.in)) {
            n = sc.nextInt(); // Read the number of elements
            k = sc.nextInt(); // Read the threshold value
            // Read n integers and adjust them (subtract 1) before adding to the list
            for (int i = 0; i < n; i++) {
                as.add(sc.nextInt() - 1);
            }
        }

        // Create a Calculator instance and calculate the result, then print it
        System.out.println(new Calculator(n, k, as).calculate());
    }
}

class Calculator {
    private int k; // Store the threshold value
    private int answer = 0; // Store the final answer
    private boolean isCalculate = false; // Flag to check if calculation is done
    private List<List<Integer>> lists = new ArrayList<>(); // Adjacency list representation

    // Constructor to initialize the Calculator with input values
    Calculator(int n, int k, List<Integer> as) {
        this.k = k; // Set the threshold value
        // Initialize the adjacency list
        for (int i = 0; i < n; i++) {
            this.lists.add(new ArrayList<>());
        }
        // Build the adjacency list based on the input values
        for (int i = 0; i < n; i++) {
            int j = as.get(i); // Get the corresponding value
            if (0 < i) {
                this.lists.get(j).add(i); // Add edge to the adjacency list
            } else if (0 < j) {
                this.answer++; // Increment answer if the condition is met
            }
        }
    }

    // Method to calculate the answer
    int calculate() {
        // If calculation hasn't been performed yet, start the DFS
        if (!this.isCalculate) {
            this.dfs(0, 0); // Start DFS from node 0
            this.isCalculate = true; // Mark calculation as done
        }
        return this.answer; // Return the final answer
    }

    // Depth-First Search (DFS) method to explore the graph
    private int dfs(int a, int pre) {
        int h = 0; // Height of the current node
        // Explore all adjacent nodes
        for (int i : this.lists.get(a)) {
            h = Math.max(h, this.dfs(i, a)); // Recursively find the height
        }
        // Check if the conditions for incrementing the answer are met
        if (0 < pre && h == this.k - 1) {
            h = 0; // Reset height if condition is met
            this.answer++; // Increment answer
        } else {
            h++; // Increment height
        }
        return h; // Return the height
    }
}
