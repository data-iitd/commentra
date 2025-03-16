import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main {
    // Maps to keep track of positive and negative counts for each node
    private final Map<Integer, Integer> pCounter;
    private final Map<Integer, Integer> nCounter;
    
    // Identifier for the current node
    private final int myId;
    
    // Total number of nodes in the system
    private final int n;

    // Constructor to initialize the PN-Counter with a given ID and number of nodes
    Main(int myId, int n) {
        this.myId = myId;
        this.n = n;
        
        // Initialize the positive and negative counters for each node
        this.pCounter = new HashMap<>();
        this.nCounter = new HashMap<>();
        for (int i = 0; i < n; i++) {
            pCounter.put(i, 0); // Initialize positive counter for node i
            nCounter.put(i, 0); // Initialize negative counter for node i
        }
    }

    // Method to increment the positive counter for the current node
    public void increment() {
        pCounter.put(myId, pCounter.get(myId) + 1);
    }

    // Method to increment the negative counter for the current node
    public void decrement() {
        nCounter.put(myId, nCounter.get(myId) + 1);
    }

    // Method to calculate the current value of the counter (positive - negative)
    public int value() {
        // Sum all positive counts
        int sumP = pCounter.values().stream().mapToInt(Integer::intValue).sum();
        // Sum all negative counts
        int sumN = nCounter.values().stream().mapToInt(Integer::intValue).sum();
        // Return the difference between positive and negative sums
        return sumP - sumN;
    }

    // Method to merge another PN-Counter into this one
    public void merge(Main other) {
        // Check if the number of nodes is the same before merging
        if (this.n != other.n) {
            throw new IllegalArgumentException("Cannot merge PN-Counters with different number of nodes");
        }
        // Merge the positive and negative counters by taking the maximum values
        for (int i = 0; i < n; i++) {
            this.pCounter.put(i, Math.max(this.pCounter.get(i), other.pCounter.get(i)));
            this.nCounter.put(i, Math.max(this.nCounter.get(i), other.nCounter.get(i)));
        }
    }

    // Main method to run the PN-Counter application
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the ID of the current node
        int myId = scanner.nextInt();
        // Read the total number of nodes in the system
        int totalNodes = scanner.nextInt();
        
        // Create a new PN-Counter instance for the current node
        Main pnCounter = new Main(myId, totalNodes);
        
        // Read the number of operations to perform
        int operations = scanner.nextInt();
        scanner.nextLine(); // Consume the remaining newline character
        
        // Process each operation
        for (int i = 0; i < operations; i++) {
            String operation = scanner.nextLine().trim();
            // Increment the counter if the operation is INCREMENT
            if (operation.equalsIgnoreCase("INCREMENT")) {
                pnCounter.increment();
            // Decrement the counter if the operation is DECREMENT
            } else if (operation.equalsIgnoreCase("DECREMENT")) {
                pnCounter.decrement();
            // Handle invalid operations
            } else {
                System.out.println("Invalid operation: " + operation);
            }
        }
        
        // Output the final value of the counter after all operations
        System.out.println("Final value of the counter: " + pnCounter.value());
    }
}
