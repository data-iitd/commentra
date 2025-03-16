
import java.util.Scanner;

/**
 * A generic HashMap implementation that uses separate chaining with linked lists
 * to handle collisions. The class supports basic operations such as insert, delete,
 * and search, as well as displaying the contents of the hash map.
 *
 * @param <K> the type of keys maintained by this map
 * @param <V> the type of mapped values
 */
public class HashMap<K, V> {
    private final int hashSize;
    private final LinkedList<K, V>[] buckets;
    private int size; // Tracks the total number of key-value pairs in the hash map

    /**
     * Constructs a HashMap with the specified hash size.
     *
     * @param hashSize the number of buckets in the hash map
     */
    @SuppressWarnings("unchecked")
    public HashMap(int hashSize) {
        this.hashSize = hashSize;
        this.buckets = new LinkedList[hashSize];
        for (int i = 0; i < hashSize; i++) {
            buckets[i] = new LinkedList<>();
        }
        this.size = 0;
    }

    /**
     * Computes the hash code for the specified key.
     *
     * @param key the key for which the hash code is to be computed
     * @return the hash code corresponding to the key
     */
    private int computeHash(K key) {
        if (key == null) {
            return 0;
        }
        int hash = key.hashCode() % hashSize;
        return hash < 0 ? hash + hashSize : hash;
    }

    /**
     * Inserts the specified key-value pair into the hash map.
     *
     * @param key   the key to be inserted
     * @param value the value to be associated with the key
     */
    public void insert(K key, V value) {
        int hash = computeHash(key);
        if (buckets[hash].insert(key, value)) {
            size++;
        }
    }

    /**
     * Deletes the key-value pair associated with the specified key from the hash map.
     *
     * @param key the key whose key-value pair is to be deleted
     */
    public void delete(K key) {
        int hash = computeHash(key);
        if (buckets[hash].delete(key)) {
            size--;
        }
    }

    /**
     * Searches for the value associated with the specified key in the hash map.
     *
     * @param key the key whose associated value is to be returned
     * @return the value associated with the specified key, or null if the key does not exist
     */
    public V search(K key) {
        int hash = computeHash(key);
        Node<K, V> node = buckets[hash].findKey(key);
        return node != null ? node.getValue() : null;
    }

    /**
     * Displays the contents of the hash map, showing each bucket and its key-value pairs.
     */
    public void display() {
        for (int i = 0; i < hashSize; i++) {
            System.out.printf("Bucket %d: %s%n", i, buckets[i].display());
        }
    }

    /**
     * Gets the number of key-value pairs in the hash map.
     *
     * @return the number of key-value pairs
     */
    public int size() {
        return size;
    }

    /**
     * A nested static class that represents a linked list used for separate chaining in the hash map.
     */
    public static class LinkedList<K, V> {
        private Node<K, V> head;

        /**
         * Inserts the specified key-value pair into the linked list.
         *
         * @param key   the key to be inserted
         * @param value the value to be associated with the key
         * @return true if a new node was inserted, false if the key already existed
         */
        public boolean insert(K key, V value) {
            Node<K, V> existingNode = findKey(key);
            if (existingNode != null) {
                existingNode.setValue(value);
                return false;
            }
            Node<K, V> newNode = new Node<>(key, value);
            newNode.setNext(head);
            head = newNode;
            return true;
        }

        /**
         * Deletes the node associated with the specified key from the linked list.
         *
         * @param key the key whose associated node is to be deleted
         * @return true if a node was deleted, false otherwise
         */
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

        /**
         * Finds the node associated with the specified key in the linked list.
         *
         * @param key the key to search for
         * @return the node associated with the specified key, or null if not found
         */
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

        /**
         * Displays the contents of the linked list as a string.
         *
         * @return a string representation of the linked list
         */
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

    /**
     * A nested static class representing a node in the linked list.
     */
    public static class Node<K, V> {
        private final K key;
        private V value;
        private Node<K, V> next;

        public Node(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public void setValue(V value) {
            this.value = value;
        }

        public Node<K, V> getNext() {
            return next;
        }

        public void setNext(Node<K, V> next) {
            this.next = next;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int hashSize = scanner.nextInt();
        HashMap<String, String> hashMap = new HashMap<>(hashSize);

        int operations = scanner.nextInt();
        scanner.nextLine(); // consume newline

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
