import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main {
    // This map keeps track of the number of increment operations per node.
    private final Map<Integer, Integer> pCounter;
    // This map keeps track of the number of decrement operations per node.
    private final Map<Integer, Integer> nCounter;
    // The ID of the current node.
    private final int myId;
    // The total number of nodes.
    private final int n;

    // Constructor initializes the node ID, total number of nodes, and the counters.
    Main(int myId, int n) {
        this.myId = myId;
        this.n = n;
        this.pCounter = new HashMap<>();
        this.nCounter = new HashMap<>();
        // Initialize the counters for each node to zero.
        for (int i = 0; i < n; i++) {
            pCounter.put(i, 0);
            nCounter.put(i, 0);
        }
    }

    // Increments the counter for the current node.
    public void increment() {
        pCounter.put(myId, pCounter.get(myId) + 1);
    }

    // Decrements the counter for the current node.
    public void decrement() {
        nCounter.put(myId, nCounter.get(myId) + 1);
    }

    // Calculates the value of the counter by subtracting the sum of decrements from the sum of increments.
    public int value() {
        int sumP = pCounter.values().stream().mapToInt(Integer::intValue).sum();
        int sumN = nCounter.values().stream().mapToInt(Integer::intValue).sum();
        return sumP - sumN;
    }

    // Merges the state of another Main object into the current one, ensuring that the maximum values are taken.
    public void merge(Main other) {
        if (this.n != other.n) {
            throw new IllegalArgumentException("Cannot merge PN-Counters with different number of nodes");
        }
        for (int i = 0; i < n; i++) {
            this.pCounter.put(i, Math.max(this.pCounter.get(i), other.pCounter.get(i)));
            this.nCounter.put(i, Math.max(this.nCounter.get(i), other.nCounter.get(i)));
        }
    }

    // Main method to read inputs, process operations, and print the final value of the counter.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int myId = scanner.nextInt();
        int totalNodes = scanner.nextInt();
        Main pnCounter = new Main(myId, totalNodes);
        int operations = scanner.nextInt();
        scanner.nextLine(); 
        for (int i = 0; i < operations; i++) {
            String operation = scanner.nextLine().trim();
            if (operation.equalsIgnoreCase("INCREMENT")) {
                pnCounter.increment();
            } else if (operation.equalsIgnoreCase("DECREMENT")) {
                pnCounter.decrement();
            } else {
                System.out.println("Invalid operation: " + operation);
            }
        }
        System.out.println("Final value of the counter: " + pnCounter.value());
    }
}
