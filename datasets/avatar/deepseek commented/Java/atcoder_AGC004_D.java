
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        // Start the MyRunnable thread to handle input and output
        new Thread(null, new MyRunnable(), "", 1 << 26).start();
    }
}

class MyRunnable implements Runnable {
    @Override
    public void run() {
        int n; // Number of elements
        int k; // Some parameter k
        List<Integer> as = new ArrayList<>(); // List to store input values

        // Read input values using Scanner
        try (Scanner sc = new Scanner(System.in)) {
            n = sc.nextInt(); // Read the number of elements
            k = sc.nextInt(); // Read the parameter k
            for (int i = 0; i < n; i++) {
                as.add(sc.nextInt() - 1); // Read each element and adjust by subtracting 1
            }
        }

        // Initialize the Calculator object and calculate the result
        System.out.println(new Calculator(n, k, as).calculate());
    }
}

class Calculator {
    private int k; // Parameter k
    private int answer = 0; // Variable to store the answer
    private boolean isCalculate = false; // Flag to check if calculation is done
    private List<List<Integer>> lists = new ArrayList<>(); // List of lists to store relationships

    // Constructor to initialize the Calculator object
    Calculator(int n, int k, List<Integer> as) {
        this.k = k;
        for (int i = 0; i < n; i++) {
            this.lists.add(new ArrayList<>()); // Initialize each list in the lists
        }
        for (int i = 0; i < n; i++) {
            int j = as.get(i);
            if (0 < i) {
                this.lists.get(j).add(i); // Add relationship between elements
            } else if (0 < j) {
                this.answer++; // Increment answer if condition is met
            }
        }
    }

    // Method to calculate the result using DFS
    int calculate() {
        if (!this.isCalculate) {
            this.dfs(0, 0); // Start DFS from the root node
            this.isCalculate = true; // Set the flag to true
        }
        return this.answer; // Return the calculated answer
    }

    // DFS method to traverse through the lists
    private int dfs(int a, int pre) {
        int h = 0; // Variable to store the height of the tree
        for (int i : this.lists.get(a)) {
            h = Math.max(h, this.dfs(i, a)); // Recursively calculate the height
        }
        if (0 < pre && h == this.k - 1) {
            h = 0; // Reset height if condition is met
            this.answer++; // Increment answer if condition is met
        } else {
            h++; // Increment height otherwise
        }
        return h; // Return the height
    }
}

