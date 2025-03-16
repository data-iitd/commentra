
import java.util.LinkedList;
import java.util.Scanner;

/**
 * A generic implementation of a hash map using an array of linked lists for collision resolution.
 * This class provides a way to store key-value pairs efficiently, allowing for average-case
 * constant time complexity for insertion, deletion, and retrieval operations.
 */
public class GenericHashMapUsingArray<K, V> {

    private int size; // Total number of key-value pairs
    private LinkedList<Node>[] buckets; // Array of linked lists (buckets) for storing entries

    /**
     * Constructs a new empty hash map with an initial capacity of 16.
     */
    public GenericHashMapUsingArray() {
        initBuckets(16);
        size = 0;
    }

    /**
     * Initializes the buckets for the hash map with the specified number of buckets.
     *
     * @param n the number of buckets to initialize
     */
    private void initBuckets(int n) {
        buckets = new LinkedList[n];
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new LinkedList<>();
        }
    }

    /**
     * Associates the specified value with the specified key in this map.
     * If the map previously contained a mapping for the key, the old value is replaced.
     *
     * @param key the key with which the specified value is to be associated
     * @param value the value to be associated with the specified key
     */
    public void put(K key, V value) {
        int bucketIndex = hashFunction(key);
        LinkedList<Node> nodes = buckets[bucketIndex];
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                node.value = value;
                return;
            }
        }
        nodes.add(new Node(key, value));
        size++;

        // Rehash if load factor exceeds 0.75
        if ((float) size / buckets.length > 0.75f) {
            reHash();
        }
    }

    /**
     * Returns the value to which the specified key is mapped, or null if this map contains no mapping for the key.
     *
     * @param key the key whose associated value is to be returned
     * @return the value associated with the specified key, or null if no mapping exists
     */
    public V get(K key) {
        int bucketIndex = hashFunction(key);
        LinkedList<Node> nodes = buckets[bucketIndex];
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                return node.value;
            }
        }
        return null;
    }

    /**
     * Removes the mapping for the specified key from this map if present.
     *
     * @param key the key whose mapping is to be removed from the map
     */
    public void remove(K key) {
        int bucketIndex = hashFunction(key);
        LinkedList<Node> nodes = buckets[bucketIndex];
        Node target = null;
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                target = node;
                break;
            }
        }
        if (target != null) {
            nodes.remove(target);
            size--;
        }
    }

    /**
     * Returns true if this map contains a mapping for the specified key.
     *
     * @param key the key whose presence in this map is to be tested
     * @return true if this map contains a mapping for the specified key
     */
    public boolean containsKey(K key) {
        return get(key) != null;
    }

    /**
     * Returns the number of key-value pairs in this map.
     *
     * @return the number of key-value pairs
     */
    public int size() {
        return size;
    }

    /**
     * Returns a string representation of the hash map.
     *
     * @return a string representation of the hash map
     */
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("{");
        for (LinkedList<Node> nodes : buckets) {
            for (Node node : nodes) {
                builder.append(node.key).append(" : ").append(node.value).append(", ");
            }
        }
        if (builder.length() > 1) {
            builder.setLength(builder.length() - 2);
        }
        builder.append("}");
        return builder.toString();
    }

    /**
     * Computes the bucket index for the given key.
     *
     * @param key the key whose bucket index is to be computed
     * @return the bucket index
     */
    private int hashFunction(K key) {
        return Math.floorMod(key.hashCode(), buckets.length);
    }

    /**
     * Rehashes the map by doubling the number of buckets and reinserting all entries.
     */
    private void reHash() {
        LinkedList<Node>[] oldBuckets = buckets;
        initBuckets(oldBuckets.length * 2);
        size = 0;
        for (LinkedList<Node> nodes : oldBuckets) {
            for (Node node : nodes) {
                put(node.key, node.value);
            }
        }
    }

    /**
     * Represents a key-value pair (node) in the hash map.
     */
    private class Node {
        private final K key;
        private V value;

        public Node(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }

    /**
     * Main method to demonstrate the hash map functionality.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        GenericHashMapUsingArray<String, String> hashMap = new GenericHashMapUsingArray<>();

        // Read the number of operations
        int operations = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Perform operations
        for (int i = 0; i < operations; i++) {
            String command = scanner.next();
            switch (command) {
                case "PUT": {
                    String key = scanner.next();
                    String value = scanner.next();
                    hashMap.put(key, value);
                    break;
                }
                case "GET": {
                    String key = scanner.next();
                    String value = hashMap.get(key);
                    System.out.println(value != null ? value : "NOT FOUND");
                    break;
                }
                case "REMOVE": {
                    String key = scanner.next();
                    hashMap.remove(key);
                    break;
                }
                case "CONTAINS": {
                    String key = scanner.next();
                    System.out.println(hashMap.containsKey(key) ? "YES" : "NO");
                    break;
                }
                case "SIZE": {
                    System.out.println(hashMap.size());
                    break;
                }
                case "PRINT": {
                    System.out.println(hashMap);
                    break;
                }
                default:
                    System.out.println("INVALID COMMAND");
            }
        }

        scanner.close();
    }
}
