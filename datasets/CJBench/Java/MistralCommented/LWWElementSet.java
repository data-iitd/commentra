
import java.util.*;
import java.util.HashMap;

// Class representing an element with a key, timestamp, and bias
class Element {
    String key;
    int timestamp;
    Bias bias;

    // Constructor for Element class
    Element(String key, int timestamp, Bias bias) {
        this.key = key;
        this.timestamp = timestamp;
        this.bias = bias;
    }
}

// Enum representing the bias type (ADDS or REMOVALS)
enum Bias {
    ADDS,
    REMOVALS
}

// Main class for LWW Set implementation
class Main {
    // Private instance variables for add and remove sets
    private final Map<String, Element> addSet;
    private final Map<String, Element> removeSet;

    // Constructor for Main class
    Main() {
        // Initialize addSet and removeSet as empty HashMap instances
        this.addSet = new HashMap<>();
        this.removeSet = new HashMap<>();
    }

    // Method to add an element to the addSet
    public void add(Element e) {
        // Add the given element to the addSet with the given key as the key
        addSet.put(e.key, e);
    }

    // Method to remove an element from the addSet
    public void remove(Element e) {
        // Check if the given element exists in the addSet
        if (lookup(e)) {
            // If it exists, add it to the removeSet with the same key
            removeSet.put(e.key, e);
            // Remove it from the addSet
            addSet.remove(e.key);
        }
    }

    // Method to check if an element exists in the addSet or removeSet
    public boolean lookup(Element e) {
        // Get the Element with the given key from the addSet
        Element inAddSet = addSet.get(e.key);
        // Get the Element with the given key from the removeSet
        Element inRemoveSet = removeSet.get(e.key);
        // Return true if the Element exists only in the addSet or if it exists in both sets but the one in the addSet has a later timestamp
        return (inAddSet != null && (inRemoveSet == null || inAddSet.timestamp > inRemoveSet.timestamp));
    }

    // Method to compare two Main objects based on their add and remove sets
    public boolean compare(Main other) {
        // Check if both sets have the same keys
        return other.addSet.keySet().containsAll(addSet.keySet()) && other.removeSet.keySet().containsAll(removeSet.keySet());
    }

    // Method to merge two Main objects
    public void merge(Main other) {
        // Iterate through each Element in other.addSet
        for (Element e : other.addSet.values()) {
            // If the given key doesn't exist in the current Main object's addSet or if the given Element has a later timestamp
            if (!addSet.containsKey(e.key) || compareTimestamps(addSet.get(e.key), e)) {
                // Add the given Element to the current Main object's addSet
                addSet.put(e.key, e);
            }
        }
        // Iterate through each Element in other.removeSet
        for (Element e : other.removeSet.values()) {
            // If the given key doesn't exist in the current Main object's removeSet or if the given Element has a later timestamp
            if (!removeSet.containsKey(e.key) || compareTimestamps(removeSet.get(e.key), e)) {
                // Add the given Element to the current Main object's removeSet
                removeSet.put(e.key, e);
            }
        }
    }

    // Method to compare the timestamps of two Elements
    public boolean compareTimestamps(Element e, Element other) {
        // Throw an IllegalArgumentException if the bias values don't match
        if (e.bias != other.bias) {
            throw new IllegalArgumentException("Invalid bias value");
        }
        // Compare the timestamps of the two Elements
        Bias bias = e.bias;
        int timestampComparison = Integer.compare(e.timestamp, other.timestamp);
        // Return true if the Elements have different biases or if the current Element has an earlier timestamp and the same bias
        return (bias != Bias.ADDS || timestampComparison > 0) && (timestampComparison != 0);
    }

    // Method to print the addSet and removeSet
    public void printSets() {
        // Print the keys of the addSet and removeSet
        System.out.println("Add Set: " + addSet.keySet());
        System.out.println("Remove Set: " + removeSet.keySet());
    }

    // Main method for testing the LWW Set implementation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Create a new instance of the Main class
        Main lwwSet = new Main();

        // Read the number of operations from the input
        int operations = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Process each operation
        for (int i = 0; i < operations; i++) {
            String command = scanner.next();
            String key = scanner.next();
            int timestamp = scanner.nextInt();
            Bias bias = Bias.valueOf(scanner.next());

            // Create a new Element based on the given command, key, timestamp, and bias
            Element element = new Element(key, timestamp, bias);

            // Based on the command, add or remove the Element from the LWW Set
            if (command.equals("ADD")) {
                lwwSet.add(element);
            } else if (command.equals("REMOVE")) {
                lwwSet.remove(element);
            }
        }

        // Read the number of lookups from the input
        int lookupCount = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Process each lookup
        for (int i = 0; i < lookupCount; i++) {
            String key = scanner.next();
            Element lookupElement = new Element(key, 0, Bias.ADDS);

            // Perform a lookup on the LWW Set with the given key
            boolean result = lwwSet.lookup(lookupElement);
            // Print the result of the lookup
            System.out.println("Lookup " + key + ": " + result);
        }

        // Print the addSet and removeSet
        lwwSet.printSets();

        // Close the scanner
        scanner.close();
    }
}