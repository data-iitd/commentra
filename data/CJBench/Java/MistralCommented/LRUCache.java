
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Initialize an empty HashMap to store the data
    private final Map<K, Entry<K, V>> data = new HashMap<>();

    // Initialize head and tail pointers to null
    private Entry<K, V> head = null;
    private Entry<K, V> tail = null;

    // Set the capacity of the cache
    private final int capacity;

    // Constructor to initialize the cache with the given capacity
    public Main(int capacity) {
        // Check if capacity is greater than 0
        if (capacity <= 0) {
            throw new IllegalArgumentException("Capacity must be greater than 0.");
        }
        // Set the capacity of the cache
        this.capacity = capacity;
    }

    // Get the value associated with the given key
    public V get(K key) {
        // Check if the key exists in the cache
        if (!data.containsKey(key)) {
            // If not, return null
            return null;
        }
        // If the entry containing the key is at the tail, move it to the front
        final Entry<K, V> entry = data.get(key);
        moveToLast(entry);
        // Return the value associated with the key
        return entry.getValue();
    }

    // Add or update the value associated with the given key
    public void put(K key, V value) {
        // Check if the key already exists in the cache
        if (data.containsKey(key)) {
            // If it does, update its value and move it to the end
            final Entry<K, V> existingEntry = data.get(key);
            existingEntry.setValue(value);
            moveToLast(existingEntry);
            return;
        }
        // If the cache is full, remove the least recently used entry and add the new one
        if (data.size() == capacity) {
            data.remove(head.getKey());
            remove(head);
        }
        // Create a new entry with the given key and value
        Entry<K, V> newEntry = new Entry<>(key, value);
        // Add the new entry to the end of the cache
        addLast(newEntry);
        // Add the new entry to the HashMap
        data.put(key, newEntry);
    }

    // Move the given entry to the end of the cache
    private void moveToLast(Entry<K, V> entry) {
        // If the entry is already at the end, return
        if (entry == tail) {
            return;
        }
        // Remove the entry from its current position
        remove(entry);
        // Add the entry to the end of the cache
        addLast(entry);
    }

    // Remove the given entry from the cache
    private void remove(Entry<K, V> entry) {
        // If the previous entry exists, set its next pointer to the next entry
        if (entry.getPrev() != null) {
            entry.getPrev().setNext(entry.getNext());
        } else {
            // If the entry is the head, set the head to the next entry
            head = entry.getNext();
        }
        // If the next entry exists, set its previous pointer to the previous entry
        if (entry.getNext() != null) {
            entry.getNext().setPrev(entry.getPrev());
        } else {
            // If the entry is the tail, set the tail to the previous entry
            tail = entry.getPrev();
        }
    }

    // Add the given entry to the end of the cache
    private void addLast(Entry<K, V> entry) {
        // If the tail exists, set its next pointer to the new entry
        if (tail != null) {
            tail.setNext(entry);
            // Set the new entry's previous pointer to the tail
            entry.setPrev(tail);
        } else {
            // If the cache is empty, set the head and tail to the new entry
            head = tail = entry;
        }
    }

    // Define an inner class to represent an entry in the cache
    private static class Entry<K, V> {
        // Initialize the key, value, previous, and next pointers
        private final K key;
        private V value;
        private Entry<K, V> prev;
        private Entry<K, V> next;

        // Constructor to initialize an entry with the given key and value
        Entry(K key, V value) {
            this.key = key;
            this.value = value;
        }

        // Getters and setters for the key, value, previous, and next pointers
        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public void setValue(V value) {
            this.value = value;
        }

        public Entry<K, V> getPrev() {
            return prev;
        }

        public void setPrev(Entry<K, V> prev) {
            this.prev = prev;
        }

        public Entry<K, V> getNext() {
            return next;
        }

        public void setNext(Entry<K, V> next) {
            this.next = next;
        }
    }

    // Main method to read input and test the LRUCache implementation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the capacity of the cache
        int capacity = scanner.nextInt();
        // Read the number of operations to perform
        int operations = scanner.nextInt();
        // Create an instance of the LRUCache with the given capacity
        Main<Integer, String> lruCache = new Main<>(capacity);
        // Perform the given operations on the cache
        for (int i = 0; i < operations; i++) {
            String operation = scanner.next();
            // If the operation is "PUT", add a new entry to the cache with the given key and value
            if (operation.equals("PUT")) {
                int key = scanner.nextInt();
                String value = scanner.next();
                lruCache.put(key, value);
                System.out.println("Added: (" + key + ", " + value + ")");
            } else if (operation.equals("GET")) {
                // If the operation is "GET", retrieve the value associated with the given key and print it
                int key = scanner.nextInt();
                String result = lruCache.get(key);
                System.out.println("Retrieved: " + (result != null ? result : "null"));
            }
        }
        // Close the scanner
        scanner.close();
    }
}