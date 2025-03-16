import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    // Represents a node in the LFU cache
    private class Node {
        private final K key; // Key of the node
        private V value; // Value stored in the node
        private int frequency; // Frequency of the node
        private Node previous; // Pointer to the previous node
        private Node next; // Pointer to the next node

        // Constructor for Node
        Node(K key, V value, int frequency) {
            this.key = key;
            this.value = value;
            this.frequency = frequency;
        }
    }

    // Head of the doubly linked list
    private Node head;
    // Tail of the doubly linked list
    private Node tail;
    // Map to store the nodes in the cache
    private final Map<K, Node> cache;
    // Capacity of the cache
    private final int capacity;

    // Constructor for Main class
    public Main(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Capacity must be greater than zero.");
        }
        this.capacity = capacity;
        this.cache = new HashMap<>();
    }

    // Method to get the value associated with the key
    public V get(K key) {
        Node node = cache.get(key);
        if (node == null) {
            return null; // Return null if the key is not found
        }
        removeNode(node); // Remove the node from its current position
        node.frequency += 1; // Increment the frequency of the node
        addNodeWithUpdatedFrequency(node); // Add the node with updated frequency
        return node.value; // Return the value of the node
    }

    // Method to add or update a key-value pair in the cache
    public void put(K key, V value) {
        if (cache.containsKey(key)) {
            Node node = cache.get(key); // Get the existing node
            node.value = value; // Update the value
            node.frequency += 1; // Increment the frequency
            removeNode(node); // Remove the node from its current position
            addNodeWithUpdatedFrequency(node); // Add the node with updated frequency
        } else {
            if (cache.size() >= capacity) {
                cache.remove(this.head.key); // Remove the least frequently used node
                removeNode(head); // Remove the node from the list
            }
            Node node = new Node(key, value, 1); // Create a new node with frequency 1
            addNodeWithUpdatedFrequency(node); // Add the node with updated frequency
            cache.put(key, node); // Add the node to the cache
        }
    }

    // Method to add a node to the list based on its frequency
    private void addNodeWithUpdatedFrequency(Node node) {
        if (tail != null && head != null) {
            Node temp = this.head;
            while (temp != null) {
                if (temp.frequency > node.frequency) {
                    if (temp == head) {
                        node.next = temp; // Insert node at the head
                        temp.previous = node;
                        this.head = node;
                        break;
                    } else {
                        node.next = temp; // Insert node in the middle
                        node.previous = temp.previous;
                        temp.previous.next = node;
                        temp.previous = node;
                        break;
                    }
                } else {
                    temp = temp.next;
                    if (temp == null) {
                        tail.next = node; // Insert node at the tail
                        node.previous = tail;
                        node.next = null;
                        tail = node;
                        break;
                    }
                }
            }
        } else {
            tail = node; // If the list is empty, set the node as head and tail
            head = tail;
        }
    }

    // Method to remove a node from the list
    private void removeNode(Node node) {
        if (node.previous != null) {
            node.previous.next = node.next; // Update the next pointer of the previous node
        } else {
            this.head = node.next; // If the node is the head, update the head
        }
        if (node.next != null) {
            node.next.previous = node.previous; // Update the previous pointer of the next node
        } else {
            this.tail = node.previous; // If the node is the tail, update the tail
        }
    }

    // Main method to read input and perform operations on the cache
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int capacity = scanner.nextInt(); // Read the capacity of the cache
        int operations = scanner.nextInt(); // Read the number of operations
        Main<Integer, String> lfuCache = new Main<>(capacity);
        for (int i = 0; i < operations; i++) {
            String operation = scanner.next(); // Read the operation (GET or PUT)
            if (operation.equals("PUT")) {
                int key = scanner.nextInt(); // Read the key for PUT operation
                String value = scanner.next(); // Read the value for PUT operation
                lfuCache.put(key, value); // Perform the PUT operation
                System.out.println("Added: (" + key + ", " + value + ")"); // Print the added key-value pair
            } else if (operation.equals("GET")) {
                int key = scanner.nextInt(); // Read the key for GET operation
                String result = lfuCache.get(key); // Perform the GET operation
                System.out.println("Retrieved: " + (result != null ? result : "null")); // Print the retrieved value or null
            }
        }
        scanner.close(); // Close the scanner
    }
}
