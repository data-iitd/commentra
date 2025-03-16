import java.util.Scanner;

public class Main {
    // Size of the hash table
    private final int hashSize;
    // Array of linked lists to handle collisions
    private final LinkedList<K, V>[] buckets;
    // Current number of elements in the hash table
    private int size; 

    // Constructor to initialize the hash table with a given size
    @SuppressWarnings("unchecked")
    public Main(int hashSize) {
        this.hashSize = hashSize;
        // Initialize each bucket as a new LinkedList
        this.buckets = new LinkedList[hashSize];
        for (int i = 0; i < hashSize; i++) {
            buckets[i] = new LinkedList<>();
        }
        this.size = 0; // Initialize size to zero
    }

    // Method to compute the hash index for a given key
    private int computeHash(K key) {
        if (key == null) {
            return 0; // Handle null keys
        }
        int hash = key.hashCode() % hashSize; // Compute hash code
        return hash < 0 ? hash + hashSize : hash; // Ensure non-negative index
    }

    // Method to insert a key-value pair into the hash table
    public void insert(K key, V value) {
        int hash = computeHash(key); // Compute the hash index
        // Insert the key-value pair into the corresponding bucket
        if (buckets[hash].insert(key, value)) {
            size++; // Increment size if insertion was successful
        }
    }

    // Method to delete a key-value pair from the hash table
    public void delete(K key) {
        int hash = computeHash(key); // Compute the hash index
        // Delete the key from the corresponding bucket
        if (buckets[hash].delete(key)) {
            size--; // Decrement size if deletion was successful
        }
    }

    // Method to search for a value by its key
    public V search(K key) {
        int hash = computeHash(key); // Compute the hash index
        Node<K, V> node = buckets[hash].findKey(key); // Find the node in the bucket
        return node != null ? node.getValue() : null; // Return value or null if not found
    }

    // Method to display all key-value pairs in the hash table
    public void display() {
        for (int i = 0; i < hashSize; i++) {
            System.out.printf("Bucket %d: %s%n", i, buckets[i].display());
        }
    }

    // Method to get the current size of the hash table
    public int size() {
        return size; // Return the number of elements
    }

    // Inner class representing a linked list to handle collisions
    public static class LinkedList<K, V> {
        private Node<K, V> head; // Head of the linked list

        // Method to insert a key-value pair into the linked list
        public boolean insert(K key, V value) {
            Node<K, V> existingNode = findKey(key); // Check if key already exists
            if (existingNode != null) {
                existingNode.setValue(value); // Update value if key exists
                return false; // Return false as no new node was added
            }
            // Create a new node and insert it at the head
            Node<K, V> newNode = new Node<>(key, value);
            newNode.setNext(head);
            head = newNode;
            return true; // Return true as a new node was added
        }

        // Method to delete a key from the linked list
        public boolean delete(K key) {
            if (head == null) {
                return false; // Return false if the list is empty
            }
            // Check if the head needs to be removed
            if ((key == null && head.getKey() == null) || (head.getKey() != null && head.getKey().equals(key))) {
                head = head.getNext(); // Remove the head
                return true; // Return true as the key was found and removed
            }
            // Traverse the list to find the key
            Node<K, V> current = head;
            while (current.getNext() != null) {
                if ((key == null && current.getNext().getKey() == null) || (current.getNext().getKey() != null && current.getNext().getKey().equals(key))) {
                    current.setNext(current.getNext().getNext()); // Remove the node
                    return true; // Return true as the key was found and removed
                }
                current = current.getNext(); // Move to the next node
            }
            return false; // Return false if the key was not found
        }

        // Method to find a node by its key
        public Node<K, V> findKey(K key) {
            Node<K, V> current = head; // Start from the head
            while (current != null) {
                // Check if the current node's key matches the search key
                if ((key == null && current.getKey() == null) || (current.getKey() != null && current.getKey().equals(key))) {
                    return current; // Return the found node
                }
                current = current.getNext(); // Move to the next node
            }
            return null; // Return null if the key was not found
        }

        // Method to display all key-value pairs in the linked list
        public String display() {
            StringBuilder sb = new StringBuilder();
            Node<K, V> current = head; // Start from the head
            while (current != null) {
                sb.append(current.getKey()).append("=").append(current.getValue()); // Append key-value pair
                current = current.getNext(); // Move to the next node
                if (current != null) {
                    sb.append(" -> "); // Append arrow if there are more nodes
                }
            }
            return sb.length() > 0 ? sb.toString() : "null"; // Return the string representation or "null" if empty
        }
    }

    // Inner class representing a node in the linked list
    public static class Node<K, V> {
        private final K key; // Key of the node
        private V value; // Value of the node
        private Node<K, V> next; // Reference to the next node

        // Constructor to create a new node
        public Node(K key, V value) {
            this.key = key;
            this.value = value;
        }

        // Getter for the key
        public K getKey() {
            return key;
        }

        // Getter for the value
        public V getValue() {
            return value;
        }

        // Setter for the value
        public void setValue(V value) {
            this.value = value;
        }

        // Getter for the next node
        public Node<K, V> getNext() {
            return next;
        }

        // Setter for the next node
        public void setNext(Node<K, V> next) {
            this.next = next;
        }
    }

    // Main method to run the hash table operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int hashSize = scanner.nextInt(); // Read the size of the hash table
        Main<String, String> hashMap = new Main<>(hashSize); // Create a new hash table
        int operations = scanner.nextInt(); // Read the number of operations
        scanner.nextLine(); // Consume the newline character

        // Perform operations based on user input
        for (int i = 0; i < operations; i++) {
            String[] input = scanner.nextLine().split(" "); // Read the operation and its arguments
            switch (input[0]) {
                case "PUT":
                    hashMap.insert(input[1], input[2]); // Insert key-value pair
                    break;
                case "GET":
                    String value = hashMap.search(input[1]); // Search for the value
                    System.out.println(value != null ? value : "NOT FOUND"); // Print the result
                    break;
                case "REMOVE":
                    hashMap.delete(input[1]); // Remove the key
                    break;
                case "CONTAINS":
                    System.out.println(hashMap.search(input[1]) != null ? "YES" : "NO"); // Check if key exists
                    break;
                case "SIZE":
                    System.out.println(hashMap.size()); // Print the current size
                    break;
                case "PRINT":
                    hashMap.display(); // Display all key-value pairs
                    break;
                default:
                    System.out.println("Invalid operation"); // Handle invalid operations
            }
        }
        scanner.close(); // Close the scanner
    }
}
