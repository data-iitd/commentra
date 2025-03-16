import java.util.LinkedList;
import java.util.Scanner;
public class Main {
    private int size; 
    private LinkedList<Node>[] buckets; 
    public Main() {
        initBuckets(16); // Initialize buckets with size 16 and set size to 0
        size = 0;
    }
    private void initBuckets(int n) {
        buckets = new LinkedList[n]; // Initialize the bucket array
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new LinkedList<>(); // Initialize each bucket as a new LinkedList
        }
    }
    public void put(K key, V value) {
        int bucketIndex = hashFunction(key); // Calculate the bucket index for the given key
        LinkedList<Node> nodes = buckets[bucketIndex];
        for (Node node : nodes) { // Check if the key already exists in the bucket
            if (node.key.equals(key)) {
                node.value = value; // Update the value if the key exists
                return;
            }
        }
        nodes.add(new Node(key, value)); // Add a new node if the key does not exist
        size++;
        if ((float) size / buckets.length > 0.75f) {
            reHash(); // Rehash if the load factor exceeds 0.75
        }
    }
    public V get(K key) {
        int bucketIndex = hashFunction(key); // Calculate the bucket index for the given key
        LinkedList<Node> nodes = buckets[bucketIndex];
        for (Node node : nodes) { // Search the bucket for the key
            if (node.key.equals(key)) {
                return node.value; // Return the value if the key is found
            }
        }
        return null; // Return null if the key is not found
    }
    public void remove(K key) {
        int bucketIndex = hashFunction(key); // Calculate the bucket index for the given key
        LinkedList<Node> nodes = buckets[bucketIndex];
        Node target = null;
        for (Node node : nodes) { // Search the bucket for the key
            if (node.key.equals(key)) {
                target = node; // Set the target node to be removed
                break;
            }
        }
        if (target != null) {
            nodes.remove(target); // Remove the target node
            size--;
        }
    }
    public boolean containsKey(K key) {
        return get(key) != null; // Check if the key exists by calling get and checking if the value is not null
    }
    public int size() {
        return size; // Return the current size of the hash map
    }
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("{");
        for (LinkedList<Node> nodes : buckets) { // Iterate through all buckets
            for (Node node : nodes) {
                builder.append(node.key).append(" : ").append(node.value).append(", "); // Append key-value pairs to the StringBuilder
            }
        }
        if (builder.length() > 1) {
            builder.setLength(builder.length() - 2); // Remove the last comma and space
        }
        builder.append("}");
        return builder.toString();
    }
    private int hashFunction(K key) {
        return Math.floorMod(key.hashCode(), buckets.length); // Calculate the bucket index using the key's hash code and the size of the bucket array
    }
    private void reHash() {
        LinkedList<Node>[] oldBuckets = buckets;
        initBuckets(oldBuckets.length * 2); // Initialize a new bucket array with double the size
        size = 0;
        for (LinkedList<Node> nodes : oldBuckets) { // Re-insert all existing nodes
            for (Node node : nodes) {
                put(node.key, node.value);
            }
        }
    }
    private class Node {
        private final K key;
        private V value;
        public Node(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main<String, String> hashMap = new Main<>();
        int operations = scanner.nextInt();
        scanner.nextLine(); 
        for (int i = 0; i < operations; i++) {
            String command = scanner.next();
            switch (command) {
                case "PUT": {
                    String key = scanner.next();
                    String value = scanner.next();
                    hashMap.put(key, value); // Insert a key-value pair
                    break;
                }
                case "GET": {
                    String key = scanner.next();
                    String value = hashMap.get(key);
                    System.out.println(value != null ? value : "NOT FOUND"); // Print the value or "NOT FOUND" if the key does not exist
                    break;
                }
                case "REMOVE": {
                    String key = scanner.next();
                    hashMap.remove(key); // Remove the key-value pair
                    break;
                }
                case "CONTAINS": {
                    String key = scanner.next();
                    System.out.println(hashMap.containsKey(key) ? "YES" : "NO"); // Check if the key exists and print "YES" or "NO"
                    break;
                }
                case "SIZE": {
                    System.out.println(hashMap.size()); // Print the size of the hash map
                    break;
                }
                case "PRINT": {
                    System.out.println(hashMap); // Print the string representation of the hash map
                    break;
                }
                default:
                    System.out.println("INVALID COMMAND");
            }
        }
        scanner.close();
    }
}
