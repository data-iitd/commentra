
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    // Initialize an empty hash map with a given capacity
    private ArrayList<LinkedList<Node>> buckets;
    private int size;

    public Main() {
        buckets = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            buckets.add(new LinkedList<>()); // Initialize a new linked list for each bucket
        }
        size = 0;
    }

    // Put a key-value pair into the hash map
    public void put(K key, V value) {
        int hash = Math.abs(key.hashCode() % buckets.size()); // Calculate the hash code of the key and find the index of the bucket
        LinkedList<Node> nodes = buckets.get(hash); // Get the linked list of the corresponding bucket

        for (Node node : nodes) { // Search for the existing node with the same key in the bucket
            if (node.key.equals(key)) {
                node.val = value; // Update the value of the existing node
                return;
            }
        }

        nodes.add(new Node(key, value)); // Add a new node to the bucket if the key is not found
        size++;

        if ((float) size / buckets.size() > 0.5f) { // Check if the load factor exceeds 0.5 and resize the hash map if necessary
            reHash();
        }
    }

    // Resize the hash map and rehash all the key-value pairs
    private void reHash() {
        ArrayList<LinkedList<Node>> oldBuckets = buckets; // Save the old hash map
        buckets = new ArrayList<>();
        size = 0;

        for (int i = 0; i < oldBuckets.size() * 2; i++) { // Create new buckets with double the capacity
            buckets.add(new LinkedList<>());
        }

        for (LinkedList<Node> nodes : oldBuckets) { // Transfer all the nodes from the old hash map to the new one
            for (Node node : nodes) {
                put(node.key, node.val);
            }
        }
    }

    // Get the value of a key from the hash map
    public V get(K key) {
        int hash = Math.abs(key.hashCode() % buckets.size()); // Calculate the hash code of the key and find the index of the bucket
        LinkedList<Node> nodes = buckets.get(hash); // Get the linked list of the corresponding bucket

        for (Node node : nodes) { // Search for the node with the matching key in the bucket
            if (node.key.equals(key)) {
                return node.val; // Return the value if found
            }
        }

        return null; // Return null if not found
    }

    // Remove a key-value pair from the hash map
    public void remove(K key) {
        int hash = Math.abs(key.hashCode() % buckets.size()); // Calculate the hash code of the key and find the index of the bucket
        LinkedList<Node> nodes = buckets.get(hash); // Get the linked list of the corresponding bucket

        Node target = null; // Initialize a variable to store the target node to be removed

        for (Node node : nodes) { // Search for the node with the matching key in the bucket
            if (node.key.equals(key)) {
                target = node; // Set the target node
                break;
            }
        }

        if (target != null) { // Remove the target node if found
            nodes.remove(target);
            size--;
        }
    }

    // Check if a key exists in the hash map
    public boolean containsKey(K key) {
        return get(key) != null; // Return true if the get method returns a non-null value
    }

    // Get the current size of the hash map
    public int size() {
        return size;
    }

    // Override the toString method to print the hash map in a readable format
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("{");

        for (LinkedList<Node> nodes : buckets) { // Iterate through all the buckets and print their contents
            for (Node node : nodes) {
                builder.append(node.key).append(" : ").append(node.val).append(", ");
            }
        }

        if (builder.length() > 1) { // Remove the last comma and space if there are multiple buckets
            builder.setLength(builder.length() - 2);
        }

        builder.append("}"); // Add the curly braces to enclose the hash map
        return builder.toString();
    }

    // Define a private inner class to represent a node in the hash map
    private class Node {
        K key;
        V val;

        Node(K key, V val) {
            this.key = key;
            this.val = val;
        }
    }

    // Main method to read commands from the standard input and perform the corresponding operations
    public static void main(String[] args) {
        Main<String, String> map = new Main<>(); // Create a new instance of the hash map
        Scanner sc = new Scanner(System.in); // Initialize a scanner to read commands from the standard input

        int operations = Integer.parseInt(sc.nextLine().trim()); // Read the number of operations

        for (int i = 0; i < operations; i++) { // Perform each operation in the given order
            String[] command = sc.nextLine().split(" ");
            switch (command[0].toUpperCase()) {
                case "PUT":
                    map.put(command[1], command[2]);
                    break;
                case "GET":
                    String value = map.get(command[1]);
                    System.out.println(value != null ? value : "NOT FOUND");
                    break;
                case "REMOVE":
                    map.remove(command[1]);
                    break;
                case "CONTAINS":
                    System.out.println(map.containsKey(command[1]) ? "YES" : "NO");
                    break;
                case "SIZE":
                    System.out.println(map.size());
                    break;
                case "PRINT":
                    System.out.println(map);
                    break;
                default:
                    System.out.println("INVALID COMMAND");
            }
        }

        sc.close(); // Close the scanner after all the operations are completed
    }
}