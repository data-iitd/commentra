import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Map to store the key-value pairs along with their linked list entries
    private final Map<K, Entry<K, V>> data = new HashMap<>();
    // Pointers to the head and tail of the doubly linked list
    private Entry<K, V> head;
    private Entry<K, V> tail;
    // Maximum capacity of the cache
    private final int capacity;

    // Constructor to initialize the cache with a specified capacity
    public Main(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Capacity must be greater than 0!");
        }
        this.capacity = capacity;
    }

    // Method to retrieve a value by key
    public V get(K key) {
        // Return null if the key does not exist in the cache
        if (!data.containsKey(key)) {
            return null;
        }
        // Get the entry associated with the key
        final Entry<K, V> entry = data.get(key);
        // Move the accessed entry to the end of the linked list (most recently used)
        moveEntryToLast(entry);
        return entry.getValue();
    }

    // Method to add a new key-value pair or update an existing key
    public void put(K key, V value) {
        // If the key already exists, update its value and move it to the end
        if (data.containsKey(key)) {
            final Entry<K, V> existingEntry = data.get(key);
            existingEntry.setValue(value);
            moveEntryToLast(existingEntry);
            return;
        }
        // If the cache is at capacity, remove the least recently used entry
        if (data.size() == capacity) {
            data.remove(tail.getKey());
            remove(tail);
        }
        // Create a new entry for the key-value pair
        Entry<K, V> newEntry = new Entry<>(null, null, key, value);
        // Add the new entry to the linked list
        addNewEntry(newEntry);
        // Store the new entry in the map
        data.put(key, newEntry);
    }

    // Helper method to move an entry to the end of the linked list
    private void moveEntryToLast(Entry<K, V> entry) {
        // If the entry is already the tail, no need to move it
        if (tail == entry) {
            return;
        }
        // Remove the entry from its current position
        remove(entry);
        // Add the entry to the end of the linked list
        addNewEntry(entry);
    }

    // Helper method to remove an entry from the linked list
    private void remove(Entry<K, V> entry) {
        // Update the previous entry's next pointer if it exists
        if (entry.getPreEntry() != null) {
            entry.getPreEntry().setNextEntry(entry.getNextEntry());
        } else {
            // If there is no previous entry, update the head
            head = entry.getNextEntry();
        }
        // Update the next entry's previous pointer if it exists
        if (entry.getNextEntry() != null) {
            entry.getNextEntry().setPreEntry(entry.getPreEntry());
        } else {
            // If there is no next entry, update the tail
            tail = entry.getPreEntry();
        }
    }

    // Helper method to add a new entry to the end of the linked list
    private void addNewEntry(Entry<K, V> entry) {
        // If there is an existing tail, link it to the new entry
        if (tail != null) {
            tail.setNextEntry(entry);
            entry.setPreEntry(tail);
        }
        // Update the tail to the new entry
        tail = entry;
        // If the list was empty, set the head to the new entry
        if (head == null) {
            head = tail;
        }
    }

    // Inner class representing an entry in the cache
    private static class Entry<K, V> {
        private Entry<K, V> preEntry; // Pointer to the previous entry
        private Entry<K, V> nextEntry; // Pointer to the next entry
        private final K key; // Key of the entry
        private V value; // Value of the entry

        // Constructor for the Entry class
        public Entry(Entry<K, V> preEntry, Entry<K, V> nextEntry, K key, V value) {
            this.preEntry = preEntry;
            this.nextEntry = nextEntry;
            this.key = key;
            this.value = value;
        }

        // Getters and setters for the entry's properties
        public Entry<K, V> getPreEntry() {
            return preEntry;
        }
        public void setPreEntry(Entry<K, V> preEntry) {
            this.preEntry = preEntry;
        }
        public Entry<K, V> getNextEntry() {
            return nextEntry;
        }
        public void setNextEntry(Entry<K, V> nextEntry) {
            this.nextEntry = nextEntry;
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
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the capacity of the cache
        int capacity = scanner.nextInt();
        // Read the number of operations to perform
        int operations = scanner.nextInt();
        // Create an instance of the cache with the specified capacity
        Main<Integer, String> mruCache = new Main<>(capacity);
        
        // Loop through the number of operations
        for (int i = 0; i < operations; i++) {
            String operation = scanner.next();
            // Handle the PUT operation
            if (operation.equals("PUT")) {
                int key = scanner.nextInt();
                String value = scanner.next();
                mruCache.put(key, value);
                System.out.println("Added: (" + key + ", " + value + ")");
            } 
            // Handle the GET operation
            else if (operation.equals("GET")) {
                int key = scanner.nextInt();
                String result = mruCache.get(key);
                System.out.println("Retrieved: " + (result != null ? result : "null"));
            }
        }
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
