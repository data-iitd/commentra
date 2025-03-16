import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main {
    // Map to hold the count for each ID
    private final Map<Integer, Integer> counterMap;
    // Unique identifier for this instance
    private final int myId;
    // Total number of IDs
    private final int n;

    // Constructor to initialize the counter with a given ID and total number of IDs
    Main(int myId, int n) {
        this.myId = myId;
        this.n = n;
        this.counterMap = new HashMap<>();
        // Initialize the counter for each ID to zero
        for (int i = 0; i < n; i++) {
            counterMap.put(i, 0);
        }
    }

    // Method to increment the count for the current ID
    public void increment() {
        counterMap.put(myId, counterMap.get(myId) + 1);
    }

    // Method to calculate the total count across all IDs
    public int value() {
        int sum = 0;
        // Sum up the counts from the counterMap
        for (int v : counterMap.values()) {
            sum += v;
        }
        return sum;
    }

    // Method to compare the counts of this instance with another instance
    public boolean compare(Main other) {
        // Check if this instance's counts are less than or equal to the other instance's counts
        for (int i = 0; i < n; i++) {
            if (this.counterMap.get(i) > other.counterMap.get(i)) {
                return false;
            }
        }
        return true;
    }

    // Method to merge counts from another instance into this instance
    public void merge(Main other) {
        // For each ID, take the maximum count from both instances
        for (int i = 0; i < n; i++) {
            this.counterMap.put(i, Math.max(this.counterMap.get(i), other.counterMap.get(i)));
        }
    }

    // Method to get the current state of the counterMap
    public Map<Integer, Integer> getState() {
        return counterMap;
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the total number of IDs
        int n = scanner.nextInt();
        // Read the unique ID for this instance
        int myId = scanner.nextInt();
        // Create a new counter instance
        Main counter = new Main(myId, n);
        // Read the number of operations to perform
        int operations = scanner.nextInt();
        
        // Process each operation
        for (int i = 0; i < operations; i++) {
            int operation = scanner.nextInt();
            // Increment the count for the current ID
            if (operation == 1) {
                counter.increment();
            } 
            // Merge counts from another instance
            else if (operation == 2) {
                int mergeId = scanner.nextInt();
                Main otherCounter = new Main(mergeId, n);
                // Read the counts for the other instance
                for (int j = 0; j < n; j++) {
                    otherCounter.counterMap.put(j, scanner.nextInt());
                }
                // Merge the other instance's counts into this instance
                counter.merge(otherCounter);
            } 
            // Handle invalid operation input
            else {
                System.out.println("Invalid operation.");
            }
        }
        // Output the final total count and state of the counter
        System.out.println("Final counter value: " + counter.value());
        System.out.println("Final counter state: " + counter.getState());
    }
}
