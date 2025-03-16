import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    // ArrayList of LinkedLists to store the buckets for the hash map
    private ArrayList<LinkedList<Node>> buckets;
    // Variable to keep track of the number of elements in the hash map
    private int size;

    // Constructor to initialize the hash map with 10 buckets
    public Main() {
        buckets = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            buckets.add(new LinkedList<>());
        }
        size = 0; // Initialize size to 0
    }

    // Method to add a key-value pair to the hash map
    public void put(K key, V value) {
        // Calculate the hash index for the key
        int hash = Math.abs(key.hashCode() % buckets.size());
        LinkedList<Node> nodes = buckets.get(hash);
        
        // Check if the key already exists, and update the value if it does
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                node.val = value;
                return; // Exit if the key is found and updated
            }
        }
        
        // If the key does not exist, add a new node with the key-value pair
        nodes.add(new Node(key, value));
        size++; // Increment the size of the hash map
        
        // Check load factor and rehash if necessary
        if ((float) size / buckets.size() > 0.5f) {
            reHash();
        }
    }

    // Method to rehash the hash map when the load factor exceeds 0.5
    private void reHash() {
        // Store the old buckets for rehashing
        ArrayList<LinkedList<Node>> oldBuckets = buckets;
        buckets = new ArrayList<>();
        size = 0; // Reset size for the new buckets
        
        // Create new buckets with double the size
        for (int i = 0; i < oldBuckets.size() * 2; i++) {
            buckets.add(new LinkedList<>());
        }
        
        // Reinsert all nodes from the old buckets into the new buckets
        for (LinkedList<Node> nodes : oldBuckets) {
            for (Node node : nodes) {
                put(node.key, node.val);
            }
        }
    }

    // Method to retrieve a value by its key
    public V get(K key) {
        // Calculate the hash index for the key
        int hash = Math.abs(key.hashCode() % buckets.size());
        LinkedList<Node> nodes = buckets.get(hash);
        
        // Search for the key in the corresponding bucket
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                return node.val; // Return the value if the key is found
            }
        }
        return null; // Return null if the key is not found
    }

    // Method to remove a key-value pair from the hash map
    public void remove(K key) {
        // Calculate the hash index for the key
        int hash = Math.abs(key.hashCode() % buckets.size());
        LinkedList<Node> nodes = buckets.get(hash);
        Node target = null;
        
        // Search for the key in the corresponding bucket
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                target = node; // Mark the node for removal
                break;
            }
        }
        
        // Remove the node if it was found
        if (target != null) {
            nodes.remove(target);
            size--; // Decrement the size of the hash map
        }
    }

    // Method to check if a key exists in the hash map
    public boolean containsKey(K key) {
        return get(key) != null; // Return true if the key is found
    }

    // Method to get the current size of the hash map
    public int size() {
        return this.size; // Return the size
    }

    // Override toString method to provide a string representation of the hash map
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("{");
        
        // Iterate through each bucket and append key-value pairs to the string
        for (LinkedList<Node> nodes : buckets) {
            for (Node node : nodes) {
                builder.append(node.key).append(" : ").append(node.val).append(", ");
            }
        }
        
        // Remove the trailing comma and space if there are any elements
        if (builder.length() > 1) {
            builder.setLength(builder.length() - 2);
        }
        builder.append("}");
        return builder.toString(); // Return the constructed string
    }

    // Inner class to represent a key-value pair (node) in the hash map
    private class Node {
        K key; // Key of the node
        V val; // Value of the node
        
        // Constructor to initialize the node with a key and value
        Node(K key, V val) {
            this.key = key;
            this.val = val;
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Main<String, String> map = new Main<>(); // Create a new hash map
        Scanner sc = new Scanner(System.in); // Create a scanner for input
        int operations = Integer.parseInt(sc.nextLine().trim()); // Read number of operations
        
        // Process each operation based on user input
        for (int i = 0; i < operations; i++) {
            String[] command = sc.nextLine().split(" ");
            switch (command[0].toUpperCase()) {
                case "PUT":
                    map.put(command[1], command[2]); // Add key-value pair
                    break;
                case "GET":
                    String value = map.get(command[1]); // Retrieve value by key
                    System.out.println(value != null ? value : "NOT FOUND"); // Print result
                    break;
                case "REMOVE":
                    map.remove(command[1]); // Remove key-value pair
                    break;
                case "CONTAINS":
                    System.out.println(map.containsKey(command[1]) ? "YES" : "NO"); // Check if key exists
                    break;
                case "SIZE":
                    System.out.println(map.size()); // Print the size of the hash map
                    break;
                case "PRINT":
                    System.out.println(map); // Print the entire hash map
                    break;
                default:
                    System.out.println("INVALID COMMAND"); // Handle invalid commands
            }
        }
        sc.close(); // Close the scanner
    }
}
