import java.util.Scanner; // Importing Scanner for input operations

public class Main { // Defining the main class
    private final int hashSize; // Declaring the size of the hash map
    private final LinkedList<K, V>[] buckets; // Declaring an array of linked lists for buckets
    private int size; // Declaring the size of the hash map

    @SuppressWarnings("unchecked") // Suppressing unchecked cast warnings
    public Main(int hashSize) { // Constructor to initialize the hash map
        this.hashSize = hashSize;
        this.buckets = new LinkedList[hashSize]; // Initializing the array of linked lists
        for (int i = 0; i < hashSize; i++) {
            buckets[i] = new LinkedList<>(); // Initializing each linked list in the array
        }
        this.size = 0; // Initializing the size of the hash map
    }

    private int computeHash(K key) { // Method to compute the hash for a given key
        if (key == null) {
            return 0; // Returning 0 if the key is null
        }
        int hash = key.hashCode() % hashSize; // Calculating the hash code
        return hash < 0 ? hash + hashSize : hash; // Handling negative hash values
    }

    public void insert(K key, V value) { // Method to insert a key-value pair into the hash map
        int hash = computeHash(key); // Computing the hash for the key
        if (buckets[hash].insert(key, value)) { // Inserting the key-value pair into the appropriate linked list
            size++; // Incrementing the size if the insertion is successful
        }
    }

    public void delete(K key) { // Method to delete a key-value pair from the hash map
        int hash = computeHash(key); // Computing the hash for the key
        if (buckets[hash].delete(key)) { // Deleting the key-value pair from the appropriate linked list
            size--; // Decrementing the size if the deletion is successful
        }
    }

    public V search(K key) { // Method to search for a value associated with a given key
        int hash = computeHash(key); // Computing the hash for the key
        Node<K, V> node = buckets[hash].findKey(key); // Finding the node with the given key
        return node != null ? node.getValue() : null; // Returning the value if found, otherwise null
    }

    public void display() { // Method to display the contents of each bucket in the hash map
        for (int i = 0; i < hashSize; i++) {
            System.out.printf("Bucket %d: %s%n", i, buckets[i].display()); // Printing each bucket
        }
    }

    public int size() { // Method to return the size of the hash map
        return size;
    }

    public static class LinkedList<K, V> { // Defining the nested linked list class
        private Node<K, V> head; // Declaring the head of the linked list

        public boolean insert(K key, V value) { // Method to insert a key-value pair into the linked list
            Node<K, V> existingNode = findKey(key); // Finding the node with the given key
            if (existingNode != null) { // If the key already exists
                existingNode.setValue(value); // Updating the value
                return false; // Returning false as the key already exists
            }
            Node<K, V> newNode = new Node<>(key, value); // Creating a new node
            newNode.setNext(head); // Setting the next node to the current head
            head = newNode; // Updating the head to the new node
            return true; // Returning true as the insertion is successful
        }

        public boolean delete(K key) { // Method to delete a key-value pair from the linked list
            if (head == null) {
                return false; // Returning false if the list is empty
            }
            if ((key == null && head.getKey() == null) || (head.getKey() != null && head.getKey().equals(key))) {
                head = head.getNext(); // Updating the head if the key is found at the head
                return true; // Returning true if the deletion is successful
            }
            Node<K, V> current = head; // Starting from the head
            while (current.getNext() != null) { // Traversing the list
                if ((key == null && current.getNext().getKey() == null) || (current.getNext().getKey() != null && current.getNext().getKey().equals(key))) {
                    current.setNext(current.getNext().getNext()); // Updating the next pointer to skip the node to be deleted
                    return true; // Returning true if the deletion is successful
                }
                current = current.getNext(); // Moving to the next node
            }
            return false; // Returning false if the key is not found
        }

        public Node<K, V> findKey(K key) { // Method to find a node with a given key in the linked list
            Node<K, V> current = head; // Starting from the head
            while (current != null) { // Traversing the list
                if ((key == null && current.getKey() == null) || (current.getKey() != null && current.getKey().equals(key))) {
                    return current; // Returning the node if the key is found
                }
                current = current.getNext(); // Moving to the next node
            }
            return null; // Returning null if the key is not found
        }

        public String display() { // Method to display the contents of the linked list
            StringBuilder sb = new StringBuilder(); // Using a StringBuilder for efficient string concatenation
            Node<K, V> current = head; // Starting from the head
            while (current != null) { // Traversing the list
                sb.append(current.getKey()).append("=").append(current.getValue()); // Appending the key-value pair
                current = current.getNext(); // Moving to the next node
                if (current != null) {
                    sb.append(" -> "); // Adding a separator between nodes
                }
            }
            return sb.length() > 0 ? sb.toString() : "null"; // Returning the string representation of the list
        }
    }

    public static class Node<K, V> { // Defining the nested node class
        private final K key; // Declaring the key
        private V value; // Declaring the value
        private Node<K, V> next; // Declaring the next node

        public Node(K key, V value) { // Constructor to initialize the node
            this.key = key;
            this.value = value;
        }

        public K getKey() { // Method to get the key
            return key;
        }

        public V getValue() { // Method to get the value
            return value;
        }

        public void setValue(V value) { // Method to set the value
            this.value = value;
        }

        public Node<K, V> getNext() { // Method to get the next node
            return next;
        }

        public void setNext(Node<K, V> next) { // Method to set the next node
            this.next = next;
        }
    }

    public static void main(String[] args) { // Main method to run the hash map operations
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input
        int hashSize = scanner.nextInt(); // Reading the size of the hash map
        Main<String, String> hashMap = new Main<>(hashSize); // Creating an instance of the hash map
        int operations = scanner.nextInt(); // Reading the number of operations
        scanner.nextLine(); // Consuming the newline character
        for (int i = 0; i < operations; i++) { // Looping through each operation
            String[] input = scanner.nextLine().split(" "); // Reading the input
            switch (input[0]) { // Performing the operation based on the first element of the input
                case "PUT":
                    hashMap.insert(input[1], input[2]); // Inserting a key-value pair
                    break;
                case "GET":
                    String value = hashMap.search(input[1]); // Searching for a value
                    System.out.println(value != null ? value : "NOT FOUND"); // Printing the value or "NOT FOUND"
                    break;
                case "REMOVE":
                    hashMap.delete(input[1]); // Deleting a key-value pair
                    break;
                case "CONTAINS":
                    System.out.println(hashMap.search(input[1]) != null ? "YES" : "NO"); // Checking if the key exists
                    break;
                case "SIZE":
                    System.out.println(hashMap.size()); // Printing the size of the hash map
                    break;
                case "PRINT":
                    hashMap.display(); // Displaying the contents of the hash map
                    break;
                default:
                    System.out.println("Invalid operation"); // Printing an error message for invalid operations
            }
        }
        scanner.close(); // Closing the Scanner
    }
}
