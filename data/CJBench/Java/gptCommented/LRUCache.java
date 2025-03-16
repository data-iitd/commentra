import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Map to store the key-value pairs and maintain the order of access
    private final Map<K, Entry<K, V>> data = new HashMap<>();
    // Pointers to the head and tail of the doubly linked list
    private Entry<K, V> head;
    private Entry<K, V> tail;
    // Maximum capacity of the cache
    private final int capacity;

    // Constructor to initialize the cache with a specified capacity
    public Main(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Capacity must be greater than 0.");
        }
        this.capacity = capacity;
    }

    // Method to retrieve a value by key
    public V get(K key) {
        // Return null if the key does not exist
        if (!data.containsKey(key)) {
            return null;
        }
        // Get the entry and move it to the end (most recently used)
        final Entry<K, V> entry = data.get(key);
        moveToLast(entry);
        return entry.getValue();
    }

    // Method to add or update a key-value pair in the cache
    public void put(K key, V value) {
        // If the key already exists, update its value and move it to the end
        if (data.containsKey(key)) {
            final Entry<K, V> existingEntry = data.get(key);
            existingEntry.setValue(value);
            moveToLast(existingEntry);
            return;
        }
        // If the cache is at capacity, remove the least recently used entry
        if (data.size() == capacity) {
            data.remove(head.getKey());
            remove(head);
        }
        // Create a new entry and add it to the cache
        Entry<K, V> newEntry = new Entry<>(key, value);
        addLast(newEntry);
        data.put(key, newEntry);
    }

    // Helper method to move an entry to the end of the linked list
    private void moveToLast(Entry<K, V> entry) {
        // If the entry is already the tail, do nothing
        if (entry == tail) {
            return;
        }
        // Remove the entry from its current position and add it to the end
        remove(entry);
        addLast(entry);
    }

    // Helper method to remove an entry from the linked list
    private void remove(Entry<K, V> entry) {
        // Update the previous entry's next pointer
        if (entry.getPrev() != null) {
            entry.getPrev().setNext(entry.getNext());
        } else {
            head = entry.getNext(); // Update head if removing the first entry
        }
        // Update the next entry's previous pointer
        if (entry.getNext() != null) {
            entry.getNext().setPrev(entry.getPrev());
        } else {
            tail = entry.getPrev(); // Update tail if removing the last entry
        }
    }

    // Helper method to add an entry to the end of the linked list
    private void addLast(Entry<K, V> entry) {
        // Link the new entry to the current tail
        if (tail != null) {
            tail.setNext(entry);
            entry.setPrev(tail);
        }
        tail = entry; // Update the tail to the new entry
        // If the list was empty, set the head to the new entry
        if (head == null) {
            head = tail;
        }
    }

    // Inner class representing an entry in the cache
    private static class Entry<K, V> {
        private final K key; // Key of the entry
        private V value; // Value of the entry
        private Entry<K, V> prev; // Pointer to the previous entry
        private Entry<K, V> next; // Pointer to the next entry

        // Constructor to create a new entry
        Entry(K key, V value) {
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

        // Getter for the previous entry
        public Entry<K, V> getPrev() {
            return prev;
        }

        // Setter for the previous entry
        public void setPrev(Entry<K, V> prev) {
            this.prev = prev;
        }

        // Getter for the next entry
        public Entry<K, V> getNext() {
            return next;
        }

        // Setter for the next entry
        public void setNext(Entry<K, V> next) {
            this.next = next;
        }
    }

    // Main method to run the cache operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the capacity of the cache
        int capacity = scanner.nextInt();
        // Read the number of operations to perform
        int operations = scanner.nextInt();
        // Create an instance of the LRU cache
        Main<Integer, String> lruCache = new Main<>(capacity);
        
        // Process each operation
        for (int i = 0; i < operations; i++) {
            String operation = scanner.next();
            if (operation.equals("PUT")) {
                // Read key and value for PUT operation
                int key = scanner.nextInt();
                String value = scanner.next();
                lruCache.put(key, value);
                System.out.println("Added: (" + key + ", " + value + ")");
            } else if (operation.equals("GET")) {
                // Read key for GET operation
                int key = scanner.nextInt();
                String result = lruCache.get(key);
                System.out.println("Retrieved: " + (result != null ? result : "null"));
            }
        }
        // Close the scanner
        scanner.close();
    }
}
