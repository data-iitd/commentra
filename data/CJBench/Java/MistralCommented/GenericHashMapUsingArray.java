import java.util.LinkedList;
import java.util.Scanner;

// Class definition for the main class
public class Main {

    // Declare instance variables
    private int size;
    private LinkedList<Node>[] buckets;

    // Constructor for the Main class
    public Main() {
        initBuckets(16); // Initialize the buckets with a capacity of 16
        size = 0;
    }

    // Method to initialize the buckets with the given capacity
    private void initBuckets(int n) {
        buckets = new LinkedList[n]; // Create an array of LinkedLists with the given capacity
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new LinkedList<>(); // Initialize each LinkedList in the array
        }
    }

    // Method to put a key-value pair in the hash map
    public void put(K key, V value) {
        int bucketIndex = hashFunction(key); // Calculate the index of the bucket where the key should be stored
        LinkedList<Node> nodes = buckets[bucketIndex]; // Get the LinkedList for the corresponding bucket

        // Search for the existing node with the same key
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                node.value = value; // If found, update the value of the existing node
                return;
            }
        }

        // If the key is not found, add a new node to the bucket
        nodes.add(new Node(key, value));
        size++;

        // Check if the load factor exceeds 0.75 and resize the hash map if necessary
        if ((float) size / buckets.length > 0.75f) {
            reHash();
        }
    }

    // Method to get the value associated with the given key
    public V get(K key) {
        int bucketIndex = hashFunction(key);
        LinkedList<Node> nodes = buckets[bucketIndex];

        // Search for the node with the given key in the bucket
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                return node.value;
            }
        }

        // If the key is not found, return null
        return null;
    }

    // Method to remove a key-value pair from the hash map
    public void remove(K key) {
        int bucketIndex = hashFunction(key);
        LinkedList<Node> nodes = buckets[bucketIndex];
        Node target = null;

        // Search for the node with the given key in the bucket
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                target = node;
                break;
            }
        }

        // If the node is found, remove it from the bucket and decrease the size
        if (target != null) {
            nodes.remove(target);
            size--;
        }
    }

    // Method to check if the hash map contains a given key
    public boolean containsKey(K key) {
        return get(key) != null;
    }

    // Method to get the current size of the hash map
    public int size() {
        return size;
    }

    // Method to print the contents of the hash map in a readable format
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("{");

        // Iterate through each bucket and add its contents to the StringBuilder
        for (LinkedList<Node> nodes : buckets) {
            for (Node node : nodes) {
                builder.append(node.key).append(" : ").append(node.value).append(", ");
            }
        }

        // Remove the trailing comma and space if there are any
        if (builder.length() > 1) {
            builder.setLength(builder.length() - 2);
        }

        // Close the curly braces and return the StringBuilder as a string
        builder.append("}");
        return builder.toString();
    }

    // Method to calculate the hash code for a given key and determine the index of the bucket
    private int hashFunction(K key) {
        return Math.floorMod(key.hashCode(), buckets.length);
    }

    // Method to resize the hash map when the load factor exceeds 0.75
    private void reHash() {
        LinkedList<Node>[] oldBuckets = buckets; // Save a reference to the old buckets
        initBuckets(oldBuckets.length * 2); // Initialize new buckets with double the capacity
        size = 0; // Reset the size to 0

        // Iterate through each node in the old buckets and put it in the new hash map
        for (LinkedList<Node> nodes : oldBuckets) {
            for (Node node : nodes) {
                put(node.key, node.value);
            }
        }
    }

    // Inner class definition for a Node with a key and a value
    private class Node {
        private final K key;
        private V value;

        public Node(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }

    // Main method to run the hash map implementation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner to read input from the console
        Main<String, String> hashMap = new Main<>(); // Create an instance of the Main class

        int operations = scanner.nextInt(); // Read the number of operations from the input
        scanner.nextLine(); // Consume the newline character

        // Process each operation in the input
        for (int i = 0; i < operations; i++) {
            String command = scanner.next(); // Read the command from the input
            switch (command) {
                case "PUT": { // Handle the PUT command
                    String key = scanner.next();
                    String value = scanner.next();
                    hashMap.put(key, value);
                    break;
                }
                case "GET": { // Handle the GET command
                    String key = scanner.next();
                    String value = hashMap.get(key);
                    System.out.println(value != null ? value : "NOT FOUND");
                    break;
                }
                case "REMOVE": { // Handle the REMOVE command
                    String key = scanner.next();
                    hashMap.remove(key);
                    break;
                }
                case "CONTAINS": { // Handle the CONTAINS command
                    String key = scanner.next();
                    System.out.println(hashMap.containsKey(key) ? "YES" : "NO");
                    break;
                }
                case "SIZE": { // Handle the SIZE command
                    System.out.println(hashMap.size());
                    break;
                }
                case "PRINT": { // Handle the PRINT command
                    System.out.println(hashMap);
                    break;
                }
                default:
                    System.out.println("INVALID COMMAND"); // Handle invalid commands
            }
        }

        scanner.close(); // Close the Scanner when finished
    }
}
