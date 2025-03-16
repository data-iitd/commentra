
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main {
    // Initialize two hash maps to store positive and negative counter values for each node
    private final Map<Integer, Integer> pCounter;
    private final Map<Integer, Integer> nCounter;
    
    // Initialize instance variables
    private final int myId;
    private final int n;
    
    // Constructor
    Main(int myId, int n) {
        this.myId = myId;
        this.n = n;
        
        // Initialize the hash maps with zero values for all nodes
        this.pCounter = new HashMap<>();
        this.nCounter = new HashMap<>();
        for (int i = 0; i < n; i++) {
            pCounter.put(i, 0);
            nCounter.put(i, 0);
        }
    }
    
    // Increment the positive counter for the current node
    public void increment() {
        pCounter.put(myId, pCounter.get(myId) + 1);
    }
    
    // Increment the negative counter for the current node
    public void decrement() {
        nCounter.put(myId, nCounter.get(myId) + 1);
    }
    
    // Calculate the difference between positive and negative counters
    public int value() {
        int sumP = 0;
        int sumN = 0;
        
        // Sum up all positive counter values
        for (int value : pCounter.values()) {
            sumP += value;
        }
        
        // Sum up all negative counter values
        for (int value : nCounter.values()) {
            sumN += value;
        }
        
        // Return the difference between positive and negative counters
        return sumP - sumN;
    }
    
    // Merge the positive and negative counters of two PN-Counters
    public void merge(Main other) {
        if (this.n != other.n) {
            throw new IllegalArgumentException("Cannot merge PN-Counters with different number of nodes");
        }
        
        // Merge positive counters
        for (int i = 0; i < n; i++) {
            pCounter.put(i, Math.max(pCounter.get(i), other.pCounter.get(i)));
        }
        
        // Merge negative counters
        for (int i = 0; i < n; i++) {
            nCounter.put(i, Math.max(nCounter.get(i), other.nCounter.get(i)));
        }
    }
    
    // Main method to read input and call methods
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input: my ID and total number of nodes
        int myId = scanner.nextInt();
        int totalNodes = scanner.nextInt();
        
        // Initialize a PN-Counter instance for the given myId and totalNodes
        Main pnCounter = new Main(myId, totalNodes);
        
        // Read input: number of operations
        int operations = scanner.nextInt();
        
        // Read input: operations and call corresponding methods
        for (int i = 0; i < operations; i++) {
            String operation = scanner.nextLine().trim();
            
            if (operation.equalsIgnoreCase("INCREMENT")) {
                pnCounter.increment(); // Increment the positive counter for the current node
            } else if (operation.equalsIgnoreCase("DECREMENT")) {
                pnCounter.decrement(); // Increment the negative counter for the current node
            } else {
                System.out.println("Invalid operation: " + operation);
            }
        }
        
        // Print the final value of the counter
        System.out.println("Final value of the counter: " + pnCounter.value());