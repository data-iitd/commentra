
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Constructor for the Main class with a given capacity
    private class Node {
        private final K key;
        private V value;
        private int frequency;
        private Node previous;
        private Node next;

        // Constructor for Node class with given key, value, and frequency
        Node(K key, V value, int frequency) {
            this.key = key;
            this.value = value;
            this.frequency = frequency;
        }
    }

    private Node head;
    private Node tail;
    private final Map<K, Node> cache;
    private final int capacity;

    // Constructor for Main class with given capacity
    public Main(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Capacity must be greater than zero."); // Throw an exception if capacity is not greater than zero
        }
        this.capacity = capacity;
        this.cache = new HashMap<>();
    }

    // Get method to retrieve the value associated with a given key
    public V get(K key) {
        Node node = cache.get(key);
        if (node == null) {
            return null;
        }
        removeNode(node); // Remove the node from the list before updating its frequency
        node.frequency += 1; // Update the frequency of the node
        addNodeWithUpdatedFrequency(node); // Add the node back to the list with its updated frequency
        return node.value;
    }

    // Put method to add or update a key-value pair in the cache
    public void put(K key, V value) {
        if (cache.containsKey(key)) {
            Node node = cache.get(key);
            node.value = value; // Update the value of the existing node
            node.frequency += 1; // Increment the frequency of the existing node
            removeNode(node); // Remove the node from the list before adding it back with updated frequency
            addNodeWithUpdatedFrequency(node); // Add the node back to the list with its updated frequency
        } else {
            if (cache.size() >= capacity) {
                cache.remove(head.key); // Remove the least frequently used node from the cache
                removeNode(head); // Remove the node from the list
            }
            Node node = new Node(key, value, 1); // Create a new node with the given key, value, and frequency of 1
            addNodeWithUpdatedFrequency(node); // Add the new node to the list with its updated frequency
            cache.put(key, node); // Add the new node to the cache
        }
    }

    // Method to add a node to the list with its updated frequency
    private void addNodeWithUpdatedFrequency(Node node) {
        if (tail != null && head != null) {
            Node temp = head; // Initialize a temporary node to traverse the list
            while (temp != null) {
                if (temp.frequency > node.frequency) { // Traverse the list to find the position to insert the new node
                    if (temp == head) {
                        node.next = temp;
                        temp.previous = node;
                        head = node;
                        break;
                    } else {
                        node.next = temp;
                        node.previous = temp.previous;
                        temp.previous.next = node;
                        temp.previous = node;
                        break;
                    }
                } else {
                    temp = temp.next; // Continue traversing the list if the current node's frequency is not greater than the new node's frequency
                }
            }
        } else {
            tail = node; // If the list is empty, set the new node as both the head and tail
            head = tail;
        }
    }

    // Method to remove a node from the list
    private void removeNode(Node node) {
        if (node.previous != null) {
            node.previous.next = node.next; // Update the next pointer of the previous node
        } else {
            head = node.next; // Update the head if the removed node was the head
        }
        if (node.next != null) {
            node.next.previous = node.previous; // Update the previous pointer of the next node
        } else {
            tail = node.previous; // Update the tail if the removed node was the tail
        }
    }

    // Main method to read input and test the LFU cache implementation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int capacity = scanner.nextInt(); // Read the capacity of the cache from the input
        int operations = scanner.nextInt(); // Read the number of operations from the input
        Main<Integer, String> lfuCache = new Main<>(capacity); // Create a new instance of the Main class with the given capacity
        for (int i = 0; i < operations; i++) {
            String operation = scanner.next(); // Read the operation type from the input
            if (operation.equals("PUT")) {
                int key = scanner.nextInt(); // Read the key and value to be added or updated from the input
                String value = scanner.next();
                lfuCache.put(key, value); // Call the put method to add or update the key-value pair in the cache
                System.out.println("Added: (" + key + ", " + value + ")"); // Print a message indicating that a key-value pair was added or updated
            } else if (operation.equals("GET")) {
                int key = scanner.nextInt(); // Read the key to be retrieved from the input
                String result = lfuCache.get(key); // Call the get method to retrieve the value associated with the given key
                System.out.println("Retrieved: " + (result != null ? result : "null")); // Print the retrieved value or a null message if the key was not found in the cache
            }
        }
        scanner.close(); // Close the scanner after processing all the input
    }
}

