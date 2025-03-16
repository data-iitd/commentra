
import java.util.Scanner;

// Class representing a hash map with open addressing and linked list chaining
public class Main<K, V> {
    private final int hashSize; // Size of the hash table
    private LinkedList<K, V>[] buckets; // Array of linked lists for each bucket
    private int size; // Number of key-value pairs in the hash map

    // Constructor initializes an empty hash map with the given size
    @SuppressWarnings("unchecked")
    public Main(int hashSize) {
        this.hashSize = hashSize;
        this.buckets = new LinkedList[hashSize];
        for (int i = 0; i < hashSize; i++) {
            buckets[i] = new LinkedList<>(); // Initialize an empty linked list for each bucket
        }
        this.size = 0;
    }

    // Computes the hash code for the given key
    private int computeHash(K key) {
        if (key == null) {
            return 0;
        }
        int hash = key.hashCode() % hashSize;
        return hash < 0 ? hash + hashSize : hash;
    }

    // Inserts the given key-value pair into the hash map
    public void insert(K key, V value) {
        int hash = computeHash(key);
        if (buckets[hash].insert(key, value)) { // If the key was already present, update its value
            size++;
        }
    }

    // Deletes the given key-value pair from the hash map
    public void delete(K key) {
        int hash = computeHash(key);
        if (buckets[hash].delete(key)) { // If the key was present, decrement the size
            size--;
        }
    }

    // Searches for the value associated with the given key in the hash map
    public V search(K key) {
        int hash = computeHash(key);
        Node<K, V> node = buckets[hash].findKey(key);
        return node != null ? node.getValue() : null;
    }

    // Displays the contents of the hash map
    public void display() {
        for (int i = 0; i < hashSize; i++) {
            System.out.printf("Bucket %d: %s%n", i, buckets[i].display());
        }
    }

    // Returns the current size of the hash map
    public int size() {
        return size;
    }

    // Inner class representing a node in the hash map
    public static class LinkedList<K, V> {
        private Node<K, V> head; // Head of the linked list

        // Inserts the given key-value pair into the linked list
        public boolean insert(K key, V value) {
            Node<K, V> existingNode = findKey(key);
            if (existingNode != null) {
                existingNode.setValue(value); // If the key was already present, update its value
                return false;
            }
            Node<K, V> newNode = new Node<>(key, value);
            newNode.setNext(head);
            head = newNode;
            return true;
        }

        // Deletes the given key from the linked list
        public boolean delete(K key) {
            if (head == null) {
                return false;
            }
            if ((key == null && head.getKey() == null) || (head.getKey() != null && head.getKey().equals(key))) {
                head = head.getNext();
                return true;
            }
            Node<K, V> current = head;
            while (current.getNext() != null) {
                if ((key == null && current.getNext().getKey() == null) || (current.getNext().getKey() != null && current.getNext().getKey().equals(key))) {
                    current.setNext(current.getNext().getNext());
                    return true;
                }
                current = current.getNext();
            }
            return false;
        }

        // Searches for the node containing the given key in the linked list
        public Node<K, V> findKey(K key) {
            Node<K, V> current = head;
            while (current != null) {
                if ((key == null && current.getKey() == null) || (current.getKey() != null && current.getKey().equals(key))) {
                    return current;
                }
                current = current.getNext();
            }
            return null;
        }

        // Displays the contents of the linked list as a string
        public String display() {
            StringBuilder sb = new StringBuilder();
            Node<K, V> current = head;
            while (current != null) {
                sb.append(current.getKey()).append("=").append(current.getValue());
                current = current.getNext();
                if (current != null) {
                    sb.append(" -> ");
                }
            }
            return sb.length() > 0 ? sb.toString() : "null";
        }
    }

    // Inner class representing a node in the hash map
    public static class Node<K, V> {
        private final K key; // The key stored in the node
        private V value; // The value stored in the node
        private Node<K, V> next; // The next node in the linked list

        // Constructs a new node with the given key and value
        public Node(K key, V value) {
            this.key = key;
            this.value = value;
        }

        // Returns the key stored in the node
        public K getKey() {
            return key;
        }

        // Returns the value stored in the node
        public V getValue() {
            return value;
        }

        // Sets the value stored in the node to the given value
        public void setValue(V value) {
            this.value = value;
        }

        // Returns the next node in the linked list
        public Node<K, V> getNext() {
            return next;
        }

        // Sets the next node in the linked list to the given node
        public void setNext(Node<K, V> next) {
            this.next = next;
        }
    }

    // Main method for testing the hash map implementation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reads the size of the hash map from the input
        int hashSize = scanner.nextInt();
        Main<String, String> hashMap = new Main<>(hashSize); // Creates a new hash map with the given size

        // Reads the number of operations from the input
        int operations = scanner.nextInt();
        scanner.nextLine(); // Consumes the newline character

        // Performs the given operations on the hash map
        for (int i = 0; i < operations; i++) {
            String[] input = scanner.nextLine().split(" ");
            switch (input[0]) {
                case "PUT":
                    hashMap.insert(input[1], input[2]);
                    break;
                case "GET":
                    String value = hashMap.search(input[1]);
                    System.out.println(value != null ? value : "NOT FOUND");
                    break;
                case "REMOVE":
                    hashMap.delete(input[1]);
                    break;
                case "CONTAINS":
                    System.out.println(hashMap.search(input[1]) != null ? "YES" : "NO");
                    break;
                case "SIZE":
                    System.out.println(hashMap.size());
                    break;
                case "PRINT":
                    hashMap.display();
                    break;
                default:
                    System.out.println("Invalid operation");
            }
        }

        scanner.close();
    }
}