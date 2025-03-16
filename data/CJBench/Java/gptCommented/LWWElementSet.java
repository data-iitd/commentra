import java.util.*;
import java.util.HashMap;

// Class representing an element with a key, timestamp, and bias
class Element {
    String key; // Unique identifier for the element
    int timestamp; // Timestamp indicating the time of the operation
    Bias bias; // Bias indicating whether the operation is an addition or removal

    // Constructor to initialize an Element
    Element(String key, int timestamp, Bias bias) {
        this.key = key;
        this.timestamp = timestamp;
        this.bias = bias;
    }
}

// Enum representing the type of operation: addition or removal
enum Bias {
    ADDS,
    REMOVALS
}

// Main class implementing the Last Write Wins (LWW) set
class Main {
    private final Map<String, Element> addSet; // Map to store added elements
    private final Map<String, Element> removeSet; // Map to store removed elements

    // Constructor to initialize the LWW set
    Main() {
        this.addSet = new HashMap<>(); // Initialize the add set
        this.removeSet = new HashMap<>(); // Initialize the remove set
    }

    // Method to add an element to the add set
    public void add(Element e) {
        addSet.put(e.key, e); // Store the element in the add set
    }

    // Method to remove an element from the remove set if it exists in the add set
    public void remove(Element e) {
        if (lookup(e)) { // Check if the element exists in the add set
            removeSet.put(e.key, e); // Store the element in the remove set
        }
    }

    // Method to check if an element is present in the add set and not removed
    public boolean lookup(Element e) {
        Element inAddSet = addSet.get(e.key); // Get the element from the add set
        Element inRemoveSet = removeSet.get(e.key); // Get the element from the remove set
        // Return true if the element is in the add set and either not in the remove set or has a later timestamp
        return (inAddSet != null && (inRemoveSet == null || inAddSet.timestamp > inRemoveSet.timestamp));
    }

    // Method to compare the current LWW set with another LWW set
    public boolean compare(Main other) {
        // Check if the other set contains all keys from the current add and remove sets
        return other.addSet.keySet().containsAll(addSet.keySet()) && other.removeSet.keySet().containsAll(removeSet.keySet());
    }

    // Method to merge another LWW set into the current set
    public void merge(Main other) {
        // Merge elements from the other add set
        for (Element e : other.addSet.values()) {
            // Add the element if it's not present or has a later timestamp
            if (!addSet.containsKey(e.key) || compareTimestamps(addSet.get(e.key), e)) {
                addSet.put(e.key, e);
            }
        }
        // Merge elements from the other remove set
        for (Element e : other.removeSet.values()) {
            // Add the element if it's not present or has a later timestamp
            if (!removeSet.containsKey(e.key) || compareTimestamps(removeSet.get(e.key), e)) {
                removeSet.put(e.key, e);
            }
        }
    }

    // Method to compare timestamps of two elements
    public boolean compareTimestamps(Element e, Element other) {
        // Check if the biases of the two elements are the same
        if (e.bias != other.bias) {
            throw new IllegalArgumentException("Invalid bias value"); // Throw an exception if biases differ
        }
        Bias bias = e.bias; // Get the bias of the first element
        int timestampComparison = Integer.compare(e.timestamp, other.timestamp); // Compare timestamps
        // If timestamps are equal, return false for ADDS bias, true for REMOVALS bias
        if (timestampComparison == 0) {
            return bias != Bias.ADDS;
        }
        // Return true if the first element's timestamp is less than the second's
        return timestampComparison < 0;
    }

    // Method to print the contents of the add and remove sets
    public void printSets() {
        System.out.println("Add Set: " + addSet.keySet()); // Print keys of the add set
        System.out.println("Remove Set: " + removeSet.keySet()); // Print keys of the remove set
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        Main lwwSet = new Main(); // Create an instance of the LWW set
        int operations = scanner.nextInt(); // Read the number of operations
        scanner.nextLine(); // Consume the newline character

        // Process each operation
        for (int i = 0; i < operations; i++) {
            String command = scanner.next(); // Read the command (ADD or REMOVE)
            String key = scanner.next(); // Read the key for the element
            int timestamp = scanner.nextInt(); // Read the timestamp for the operation
            Bias bias = Bias.valueOf(scanner.next()); // Read the bias (ADDS or REMOVALS)
            Element element = new Element(key, timestamp, bias); // Create a new Element

            // Execute the command based on its type
            if (command.equals("ADD")) {
                lwwSet.add(element); // Add the element to the set
            } else if (command.equals("REMOVE")) {
                lwwSet.remove(element); // Remove the element from the set
            }
        }

        // Read the number of lookups to perform
        int lookupCount = scanner.nextInt(); 
        scanner.nextLine(); // Consume the newline character

        // Perform each lookup
        for (int i = 0; i < lookupCount; i++) {
            String key = scanner.next(); // Read the key to lookup
            Element lookupElement = new Element(key, 0, Bias.ADDS); // Create a lookup Element
            // Print the result of the lookup
            System.out.println("Lookup " + key + ": " + lwwSet.lookup(lookupElement));
        }

        // Print the contents of the add and remove sets
        lwwSet.printSets();
        scanner.close(); // Close the scanner
    }
}
