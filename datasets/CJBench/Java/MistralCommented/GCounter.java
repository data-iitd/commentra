
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main {
    // Initialize a map to store the counter for each process
    private final Map<Integer, Integer> counterMap;
    // Initialize the ID of the current process
    private final int myId;
    // Initialize the total number of processes
    private final int n;

    Main(int myId, int n) {
        this.myId = myId;
        this.n = n;
        // Initialize an empty map with size n
        this.counterMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            counterMap.put(i, 0);
        }
    }

    // Increment the counter for the current process
    public void increment() {
        counterMap.put(myId, counterMap.get(myId) + 1);
    }

    // Return the sum of all counters
    public int value() {
        int sum = 0;
        // Iterate through all counters and sum them up
        for (int v : counterMap.values()) {
            sum += v;
        }
        return sum;
    }

    // Compare the counters of this process with another process
    public boolean compare(Main other) {
        for (int i = 0; i < n; i++) {
            // If the counter for any process i is greater in this process than in the other process, return false
            if (this.counterMap.get(i) > other.counterMap.get(i)) {
                return false;
            }
        }
        // If all counters are less or equal, return true
        return true;
    }

    // Merge the counters of this process with another process
    public void merge(Main other) {
        for (int i = 0; i < n; i++) {
            // Update the counter for each process i with the maximum value between this process and the other process
            this.counterMap.put(i, Math.max(this.counterMap.get(i), other.counterMap.get(i)));
        }
    }

    // Return the current state of the counters
    public Map<Integer, Integer> getState() {
        return counterMap;
    }

    // Main method to read input and run the simulation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the total number of processes and the ID of the current process
        int n = scanner.nextInt();
        int myId = scanner.nextInt();
        // Create a new instance of the Main class with the given parameters
        Main counter = new Main(myId, n);
        // Read the number of operations
        int operations = scanner.nextInt();
        // Iterate through all operations
        for (int i = 0; i < operations; i++) {
            int operation = scanner.nextInt();
            // If the operation is to increment the counter, call the increment method
            if (operation == 1) {
                counter.increment();
            } // If the operation is to merge the counters with another process, read the ID of the other process and its counters, and call the merge method
            else if (operation == 2) {
                int mergeId = scanner.nextInt();
                Main otherCounter = new Main(mergeId, n);
                // Read the counters for the other process and initialize a new instance of the Main class with the given parameters
                for (int j = 0; j < n; j++) {
                    otherCounter.counterMap.put(j, scanner.nextInt());
                }
                // Call the merge method with the other instance of the Main class
                counter.merge(otherCounter);
            } // If the operation is invalid, print an error message
            else {
                System.out.println("Invalid operation.");
            }
        }
        // Print the final counter value and state
        System.out.println("Final counter value: " + counter.value());
        System.out.println("Final counter state: " + counter.getState());
    }
}