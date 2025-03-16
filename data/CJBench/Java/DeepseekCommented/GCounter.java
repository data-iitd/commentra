import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main {
    private final Map<Integer, Integer> counterMap; // Stores the counters
    private final int myId; // Identifier for the current instance
    private final int n; // Number of counters

    // Constructor to initialize the counters
    Main(int myId, int n) {
        this.myId = myId;
        this.n = n;
        this.counterMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            counterMap.put(i, 0); // Initialize each counter to 0
        }
    }

    // Increment the counter associated with the current instance's ID
    public void increment() {
        counterMap.put(myId, counterMap.get(myId) + 1);
    }

    // Calculate the sum of all counters
    public int value() {
        int sum = 0;
        for (int v : counterMap.values()) {
            sum += v;
        }
        return sum;
    }

    // Compare the current counters with another instance's counters
    public boolean compare(Main other) {
        for (int i = 0; i < n; i++) {
            if (this.counterMap.get(i) > other.counterMap.get(i)) {
                return false; // Current counters are greater than the other's
            }
        }
        return true; // Current counters are less than or equal to the other's
    }

    // Merge the current counters with another instance's counters
    public void merge(Main other) {
        for (int i = 0; i < n; i++) {
            this.counterMap.put(i, Math.max(this.counterMap.get(i), other.counterMap.get(i)));
        }
    }

    // Get the current state of the counters
    public Map<Integer, Integer> getState() {
        return counterMap;
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of counters
        int myId = scanner.nextInt(); // Read the current instance's ID
        Main counter = new Main(myId, n); // Create a new counter instance
        int operations = scanner.nextInt(); // Read the number of operations

        for (int i = 0; i < operations; i++) {
            int operation = scanner.nextInt(); // Read the operation type
            if (operation == 1) {
                counter.increment(); // Increment the counter
            } else if (operation == 2) {
                int mergeId = scanner.nextInt(); // Read the merge instance's ID
                Main otherCounter = new Main(mergeId, n); // Create another counter instance
                for (int j = 0; j < n; j++) {
                    otherCounter.counterMap.put(j, scanner.nextInt()); // Read the counters to merge
                }
                counter.merge(otherCounter); // Merge the counters
            } else {
                System.out.println("Invalid operation."); // Print error message for invalid operation
            }
        }
        System.out.println("Final counter value: " + counter.value()); // Print the final counter value
        System.out.println("Final counter state: " + counter.getState()); // Print the final counter state
    }
}
