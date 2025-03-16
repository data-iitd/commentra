import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    // Size of the hash map
    private int size; 
    // Array of linked lists to store the buckets
    private LinkedList<Node>[] buckets; 

    // Constructor to initialize the hash map with a default bucket size
    public Main() {
        initBuckets(16); // Initialize buckets with a size of 16
        size = 0; // Initialize size to 0
    }

    // Method to initialize the buckets with linked lists
    private void initBuckets(int n) {
        buckets = new LinkedList[n]; // Create an array of linked lists
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new LinkedList<>(); // Initialize each bucket as a new linked list
        }
    }

    // Method to add a key-value pair to the hash map
    public void put(K key, V value) {
        int bucketIndex = hashFunction(key); // Get the index of the bucket for the key
        LinkedList<Node> nodes = buckets[bucketIndex]; // Get the linked list at that bucket
        // Check if the key already exists in the bucket
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                node.value = value; // Update the value if the key exists
                return;
            }
        }
        // Add a new node if the key does not exist
        nodes.add(new Node(key, value));
        size++; // Increment the size of the hash map
        // Check load factor and rehash if necessary
        if ((float) size / buckets.length > 0.75f) {
            reHash(); // Rehash if the load factor exceeds 0.75
        }
    }

    // Method to retrieve a value by key
    public V get(K key) {
        int bucketIndex = hashFunction(key); // Get the index of the bucket for the key
        LinkedList<Node> nodes = buckets[bucketIndex]; // Get the linked list at that bucket
        // Search for the key in the bucket
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                return node.value; // Return the value if the key is found
            }
        }
        return null; // Return null if the key is not found
    }

    // Method to remove a key-value pair from the hash map
    public void remove(K key) {
        int bucketIndex = hashFunction(key); // Get the index of the bucket for the key
        LinkedList<Node> nodes = buckets[bucketIndex]; // Get the linked list at that bucket
        Node target = null; // Variable to hold the target node for removal
        // Search for the key in the bucket
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                target = node; // Found the target node
                break;
            }
        }
        // Remove the target node if it exists
        if (target != null) {
            nodes.remove(target); // Remove the node from the linked list
            size--; // Decrement the size of the hash map
        }
    }

    // Method to check if a key exists in the hash map
    public boolean containsKey(K key) {
        return get(key) != null; // Return true if the key is found, false otherwise
    }

    // Method to get the current size of the hash map
    public int size() {
        return size; // Return the size of the hash map
    }

    // Method to convert the hash map to a string representation
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("{"); // Start of the string representation
        // Iterate through each bucket and its nodes
        for (LinkedList<Node> nodes : buckets) {
            for (Node node : nodes) {
                builder.append(node.key).append(" : ").append(node.value).append(", "); // Append key-value pairs
            }
        }
        // Remove the trailing comma and space if there are any elements
        if (builder.length() > 1) {
            builder.setLength(builder.length() - 2);
        }
        builder.append("}"); // End of the string representation
        return builder.toString(); // Return the string representation
    }

    // Hash function to determine the bucket index for a given key
    private int hashFunction(K key) {
        return Math.floorMod(key.hashCode(), buckets.length); // Return the index using modulo operation
    }

    // Method to rehash the hash map when the load factor exceeds the threshold
    private void reHash() {
        LinkedList<Node>[] oldBuckets = buckets; // Store the old buckets
        initBuckets(oldBuckets.length * 2); // Initialize new buckets with double the size
        size = 0; // Reset size to 0
        // Reinsert all nodes from old buckets into new buckets
        for (LinkedList<Node> nodes : oldBuckets) {
            for (Node node : nodes) {
                put(node.key, node.value); // Reinsert each key-value pair
            }
        }
    }

    // Inner class to represent a key-value pair (node)
    private class Node {
        private final K key; // Key of the node
        private V value; // Value of the node

        // Constructor for the Node class
        public Node(K key, V value) {
            this.key = key; // Initialize key
            this.value = value; // Initialize value
        }
    }

    // Main method to run the hash map operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        Main<String, String> hashMap = new Main<>(); // Create a new instance of the hash map
        int operations = scanner.nextInt(); // Read the number of operations to perform
        scanner.nextLine(); // Consume the newline character
        // Loop through the number of operations
        for (int i = 0; i < operations; i++) {
            String command = scanner.next(); // Read the command
            switch (command) {
                case "PUT": { // Handle PUT command
                    String key = scanner.next(); // Read the key
                    String value = scanner.next(); // Read the value
                    hashMap.put(key, value); // Add the key-value pair to the hash map
                    break;
                }
                case "GET": { // Handle GET command
                    String key = scanner.next(); // Read the key
                    String value = hashMap.get(key); // Retrieve the value
                    System.out.println(value != null ? value : "NOT FOUND"); // Print the value or "NOT FOUND"
                    break;
                }
                case "REMOVE": { // Handle REMOVE command
                    String key = scanner.next(); // Read the key
                    hashMap.remove(key); // Remove the key-value pair from the hash map
                    break;
                }
                case "CONTAINS": { // Handle CONTAINS command
                    String key = scanner.next(); // Read the key
                    System.out.println(hashMap.containsKey(key) ? "YES" : "NO"); // Print "YES" or "NO"
                    break;
                }
                case "SIZE": { // Handle SIZE command
                    System.out.println(hashMap.size()); // Print the size of the hash map
                    break;
                }
                case "PRINT": { // Handle PRINT command
                    System.out.println(hashMap); // Print the string representation of the hash map
                    break;
                }
                default:
                    System.out.println("INVALID COMMAND"); // Handle invalid commands
            }
        }
        scanner.close(); // Close the scanner
    }
}
