import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // A HashMap to store the entries in the cache
    private final Map<K, Entry<K, V>> data = new HashMap<>();
    // Reference to the most recently used entry
    private Entry<K, V> head;
    // Reference to the least recently used entry
    private Entry<K, V> tail;
    // The capacity of the cache
    private final int capacity;

    // Constructor to initialize the cache with a given capacity
    public Main(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Capacity must be greater than 0!");
        }
        this.capacity = capacity;
    }

    // Method to retrieve a value from the cache based on the key
    public V get(K key) {
        if (!data.containsKey(key)) {
            return null;
        }
        final Entry<K, V> entry = data.get(key);
        moveEntryToLast(entry); // Move the accessed entry to the most recently used position
        return entry.getValue();
    }

    // Method to add or update an entry in the cache
    public void put(K key, V value) {
        if (data.containsKey(key)) {
            final Entry<K, V> existingEntry = data.get(key);
            existingEntry.setValue(value); // Update the value of the existing entry
            moveEntryToLast(existingEntry); // Move the existing entry to the most recently used position
            return;
        }
        if (data.size() == capacity) {
            data.remove(tail.getKey()); // Remove the least recently used entry
            remove(tail); // Remove the least recently used entry from the list
        }
        Entry<K, V> newEntry = new Entry<>(null, null, key, value);
        addNewEntry(newEntry); // Add the new entry to the cache
        data.put(key, newEntry); // Add the new entry to the HashMap
    }

    // Helper method to move an entry to the most recently used position
    private void moveEntryToLast(Entry<K, V> entry) {
        if (tail == entry) {
            return; // The entry is already the most recently used
        }
        remove(entry); // Remove the entry from its current position
        addNewEntry(entry); // Add the entry to the most recently used position
    }

    // Helper method to remove an entry from the cache
    private void remove(Entry<K, V> entry) {
        if (entry.getPreEntry() != null) {
            entry.getPreEntry().setNextEntry(entry.getNextEntry()); // Update the previous entry's next pointer
        } else {
            head = entry.getNextEntry(); // Update the head if the entry is the first one
        }
        if (entry.getNextEntry() != null) {
            entry.getNextEntry().setPreEntry(entry.getPreEntry()); // Update the next entry's previous pointer
        } else {
            tail = entry.getPreEntry(); // Update the tail if the entry is the last one
        }
    }

    // Helper method to add a new entry to the cache
    private void addNewEntry(Entry<K, V> entry) {
        if (tail != null) {
            tail.setNextEntry(entry); // Set the next pointer of the current tail
            entry.setPreEntry(tail); // Set the previous pointer of the new entry
        }
        tail = entry; // Update the tail to the new entry
        if (head == null) {
            head = tail; // If the head is null, set it to the new entry
        }
    }

    // Private static class to represent each entry in the cache
    private static class Entry<K, V> {
        private Entry<K, V> preEntry; // Reference to the previous entry
        private Entry<K, V> nextEntry; // Reference to the next entry
        private final K key; // The key of the entry
        private V value; // The value of the entry

        // Constructor to initialize the entry
        public Entry(Entry<K, V> preEntry, Entry<K, V> nextEntry, K key, V value) {
            this.preEntry = preEntry;
            this.nextEntry = nextEntry;
            this.key = key;
            this.value = value;
        }

        // Getter for the previous entry
        public Entry<K, V> getPreEntry() {
            return preEntry;
        }

        // Setter for the previous entry
        public void setPreEntry(Entry<K, V> preEntry) {
            this.preEntry = preEntry;
        }

        // Getter for the next entry
        public Entry<K, V> getNextEntry() {
            return nextEntry;
        }

        // Setter for the next entry
        public void setNextEntry(Entry<K, V> nextEntry) {
            this.nextEntry = nextEntry;
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
    }

    // Main method to read input and perform operations on the cache
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int capacity = scanner.nextInt();
        int operations = scanner.nextInt();
        Main<Integer, String> mruCache = new Main<>(capacity);
        for (int i = 0; i < operations; i++) {
            String operation = scanner.next();
            if (operation.equals("PUT")) {
                int key = scanner.nextInt();
                String value = scanner.next();
                mruCache.put(key, value);
                System.out.println("Added: (" + key + ", " + value + ")");
            } else if (operation.equals("GET")) {
                int key = scanner.nextInt();
                String result = mruCache.get(key);
                System.out.println("Retrieved: " + (result != null ? result : "null"));
            }
        }
        scanner.close();
    }
}
