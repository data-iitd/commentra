import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Node class representing each entry in the cache
    private class Node {
        private final K key; // Key of the cache entry
        private V value; // Value of the cache entry
        private int frequency; // Access frequency of the cache entry
        private Node previous; // Pointer to the previous node in the linked list
        private Node next; // Pointer to the next node in the linked list

        // Constructor to initialize a new node
        Node(K key, V value, int frequency) {
            this.key = key;
            this.value = value;
            this.frequency = frequency;
        }
    }

    private Node head; // Head of the doubly linked list
    private Node tail; // Tail of the doubly linked list
    private final Map<K, Node> cache; // HashMap to store key-node pairs for quick access
    private final int capacity; // Maximum capacity of the cache

    // Constructor to initialize the cache with a given capacity
    public Main(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Capacity must be greater than zero.");
        }
        this.capacity = capacity;
        this.cache = new HashMap<>();
    }

    // Method to retrieve a value by key from the cache
    public V get(K key) {
        Node node = cache.get(key); // Get the node associated with the key
        if (node == null) {
            return null; // Return null if the key is not found
        }
        removeNode(node); // Remove the node from its current position
        node.frequency += 1; // Increment the frequency of access
        addNodeWithUpdatedFrequency(node); // Reinsert the node based on updated frequency
        return node.value; // Return the value of the node
    }

    // Method to add or update a key-value pair in the cache
    public void put(K key, V value) {
        if (cache.containsKey(key)) { // Check if the key already exists
            Node node = cache.get(key); // Get the existing node
            node.value = value; // Update the value
            node.frequency += 1; // Increment the frequency
            removeNode(node); // Remove the node from its current position
            addNodeWithUpdatedFrequency(node); // Reinsert the node based on updated frequency
        } else {
            // If the cache is at capacity, remove the least frequently used node
            if (cache.size() >= capacity) {
                cache.remove(this.head.key); // Remove the head node from the cache
                removeNode(head); // Remove the head node from the linked list
            }
            // Create a new node for the new key-value pair
            Node node = new Node(key, value, 1);
            addNodeWithUpdatedFrequency(node); // Add the new node to the linked list
            cache.put(key, node); // Add the new node to the cache
        }
    }

    // Method to add a node to the linked list based on its frequency
    private void addNodeWithUpdatedFrequency(Node node) {
        if (tail != null && head != null) { // Check if the list is not empty
            Node temp = this.head; // Start from the head of the list
            while (temp != null) {
                // Find the correct position based on frequency
                if (temp.frequency > node.frequency) {
                    if (temp == head) {
                        // If the node is to be added at the head
                        node.next = temp;
                        temp.previous = node;
                        this.head = node; // Update head to new node
                        break;
                    } else {
                        // Insert the node in the middle of the list
                        node.next = temp;
                        node.previous = temp.previous;
                        temp.previous.next = node;
                        temp.previous = node;
                        break;
                    }
                } else {
                    temp = temp.next; // Move to the next node
                    if (temp == null) {
                        // If reached the end of the list, add to the tail
                        tail.next = node;
                        node.previous = tail;
                        node.next = null;
                        tail = node; // Update tail to new node
                        break;
                    }
                }
            }
        } else {
            // If the list is empty, set head and tail to the new node
            tail = node;
            head = tail;
        }
    }

    // Method to remove a node from the linked list
    private void removeNode(Node node) {
        if (node.previous != null) {
            node.previous.next = node.next; // Bypass the node to remove it
        } else {
            this.head = node.next; // Update head if removing the head node
        }
        if (node.next != null) {
            node.next.previous = node.previous; // Bypass the node to remove it
        } else {
            this.tail = node.previous; // Update tail if removing the tail node
        }
    }

    // Main method to run the LFU Cache operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int capacity = scanner.nextInt(); // Read the capacity of the cache
        int operations = scanner.nextInt(); // Read the number of operations to perform
        Main<Integer, String> lfuCache = new Main<>(capacity); // Create an instance of LFU Cache

        // Loop through the operations
        for (int i = 0; i < operations; i++) {
            String operation = scanner.next(); // Read the operation type (PUT or GET)
            if (operation.equals("PUT")) {
                int key = scanner.nextInt(); // Read the key for PUT operation
                String value = scanner.next(); // Read the value for PUT operation
                lfuCache.put(key, value); // Add the key-value pair to the cache
                System.out.println("Added: (" + key + ", " + value + ")");
            } else if (operation.equals("GET")) {
                int key = scanner.nextInt(); // Read the key for GET operation
                String result = lfuCache.get(key); // Retrieve the value from the cache
                System.out.println("Retrieved: " + (result != null ? result : "null")); // Print the result
            }
        }
        scanner.close(); // Close the scanner
    }
}
