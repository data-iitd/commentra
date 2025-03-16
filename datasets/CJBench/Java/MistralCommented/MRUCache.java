
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Initialize an empty hash map to store the data
    private final Map<K, Entry<K, V>> data = new HashMap<>();

    // Initialize head and tail pointers to null
    private Entry<K, V> head = null;
    private Entry<K, V> tail = null;

    // Set the cache capacity
    private final int capacity;

    // Constructor initializes the cache with the given capacity
    public Main(int capacity) {
        if (capacity <= 0) { // Check if capacity is greater than 0
            throw new IllegalArgumentException("Capacity must be greater than 0!");
        }
        this.capacity = capacity;
    }

    // Get the value associated with the given key
    public V get(K key) {
        if (!data.containsKey(key)) { // Check if the key is in the map
            return null;
        }
        final Entry<K, V> entry = data.get(key); // Get the entry for the key
        moveEntryToLast(entry); // Move the entry to the last position
        return entry.getValue(); // Return the value
    }

    // Add or update the value associated with the given key
    public void put(K key, V value) {
        if (data.containsKey(key)) { // Check if the key already exists
            final Entry<K, V> existingEntry = data.get(key);
            existingEntry.setValue(value); // Update the value
            moveEntryToLast(existingEntry); // Move the entry to the last position
            return;
        }
        if (data.size() == capacity) { // Check if the cache is full
            data.remove(tail.getKey()); // Remove the least recently used entry
            remove(tail); // Remove the entry from the linked list
        }
        Entry<K, V> newEntry = new Entry<>(null, null, key, value); // Create a new entry
        addNewEntry(newEntry); // Add the entry to the linked list
        data.put(key, newEntry); // Add the entry to the hash map
    }

    // Move the given entry to the last position in the linked list
    private void moveEntryToLast(Entry<K, V> entry) {
        if (tail == entry) { // If the entry is already at the last position, do nothing
            return;
        }
        remove(entry); // Remove the entry from its current position
        addNewEntry(entry); // Add the entry to the last position
    }

    // Remove the given entry from the linked list
    private void remove(Entry<K, V> entry) {
        if (entry.getPreEntry() != null) { // If the entry has a previous entry, update its next entry
            entry.getPreEntry().setNextEntry(entry.getNextEntry());
        } else { // If the entry is the head, update the head
            head = entry.getNextEntry();
        }
        if (entry.getNextEntry() != null) { // If the entry has a next entry, update its previous entry
            entry.getNextEntry().setPreEntry(entry.getPreEntry());
        } else { // If the entry is the tail, update the tail
            tail = entry.getPreEntry();
        }
    }

    // Add the given entry to the last position in the linked list
    private void addNewEntry(Entry<K, V> entry) {
        if (tail != null) { // If there is a tail, add the new entry after it
            tail.setNextEntry(entry);
            entry.setPreEntry(tail);
        } else { // If there is no tail, set the new entry as the head and tail
            head = tail = entry;
        }
    }

    // Define an inner static class for the cache entries
    private static class Entry<K, V> {
        // Initialize the previous and next pointers and the key-value pair
        private Entry<K, V> preEntry;
        private Entry<K, V> nextEntry;
        private final K key;
        private V value;

        // Constructor initializes the entry with the given previous and next entries, key, and value
        public Entry(Entry<K, V> preEntry, Entry<K, V> nextEntry, K key, V value) {
            this.preEntry = preEntry;
            this.nextEntry = nextEntry;
            this.key = key;
            this.value = value;
        }

        // Get the previous entry
        public Entry<K, V> getPreEntry() {
            return preEntry;
        }

        // Set the previous entry
        public void setPreEntry(Entry<K, V> preEntry) {
            this.preEntry = preEntry;
        }

        // Get the next entry
        public Entry<K, V> getNextEntry() {
            return nextEntry;
        }

        // Set the next entry
        public void setNextEntry(Entry<K, V> nextEntry) {
            this.nextEntry = nextEntry;
        }

        // Get the key
        public K getKey() {
            return key;
        }

        // Get the value
        public V getValue() {
            return value;
        }

        // Set the value
        public void setValue(V value) {
            this.value = value;
        }
    }

    // Main method reads input and calls the cache methods
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a scanner to read input
        int capacity = scanner.nextInt(); // Read the cache capacity
        int operations = scanner.nextInt(); // Read the number of operations
        Main<Integer, String> mruCache = new Main<>(capacity); // Create a new cache with the given capacity
        for (int i = 0; i < operations; i++) { // Iterate through the operations
            String operation = scanner.next(); // Read the operation type
            if (operation.equals("PUT")) { // If the operation is a put, read the key and value and call put
                int key = scanner.nextInt();
                String value = scanner.next();
                mruCache.put(key, value);
                System.out.println("Added: (" + key + ", " + value + ")");
            } else if (operation.equals("GET")) { // If the operation is a get, read the key and call get
                int key = scanner.nextInt();
                String result = mruCache.get(key);
                System.out.println("Retrieved: " + (result != null ? result : "null"));
            }
        }
        scanner.close(); // Close the scanner
    }
}