import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    private final Map<K, Entry<K, V>> data = new HashMap<>(); // Stores the entries in the cache
    private Entry<K, V> head; // Head of the doubly linked list
    private Entry<K, V> tail; // Tail of the doubly linked list
    private final int capacity; // Capacity of the cache

    public Main(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Capacity must be greater than 0.");
        }
        this.capacity = capacity;
    }

    public V get(K key) {
        if (!data.containsKey(key)) { // Check if the key exists in the cache
            return null;
        }
        final Entry<K, V> entry = data.get(key);
        moveToLast(entry); // Move the accessed entry to the end of the list
        return entry.getValue();
    }

    public void put(K key, V value) {
        if (data.containsKey(key)) { // Check if the key already exists
            final Entry<K, V> existingEntry = data.get(key);
            existingEntry.setValue(value); // Update the value
            moveToLast(existingEntry); // Move the existing entry to the end
            return;
        }
        if (data.size() == capacity) { // Check if the cache is full
            data.remove(head.getKey()); // Remove the least recently used entry
            remove(head); // Remove the entry from the list
        }
        Entry<K, V> newEntry = new Entry<>(key, value);
        addLast(newEntry); // Add the new entry to the end of the list
        data.put(key, newEntry); // Add the entry to the map
    }

    private void moveToLast(Entry<K, V> entry) {
        if (entry == tail) { // If the entry is already at the end, do nothing
            return;
        }
        remove(entry); // Remove the entry from its current position
        addLast(entry); // Add the entry to the end of the list
    }

    private void remove(Entry<K, V> entry) {
        if (entry.getPrev() != null) { // Update the previous entry's next pointer
            entry.getPrev().setNext(entry.getNext());
        } else { // If the entry is the head, update the head
            head = entry.getNext();
        }
        if (entry.getNext() != null) { // Update the next entry's previous pointer
            entry.getNext().setPrev(entry.getPrev());
        } else { // If the entry is the tail, update the tail
            tail = entry.getPrev();
        }
    }

    private void addLast(Entry<K, V> entry) {
        if (tail != null) { // If the list is not empty, update the tail's next pointer
            tail.setNext(entry);
            entry.setPrev(tail);
        }
        tail = entry; // Update the tail to the new entry
        if (head == null) { // If the list is empty, set the head to the new entry
            head = tail;
        }
    }

    private static class Entry<K, V> {
        private final K key; // Key of the entry
        private V value; // Value of the entry
        private Entry<K, V> prev; // Previous entry in the list
        private Entry<K, V> next; // Next entry in the list

        Entry(K key, V value) {
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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int capacity = scanner.nextInt();
        int operations = scanner.nextInt();
        Main<Integer, String> lruCache = new Main<>(capacity);
        for (int i = 0; i < operations; i++) {
            String operation = scanner.next();
            if (operation.equals("PUT")) {
                int key = scanner.nextInt();
                String value = scanner.next();
                lruCache.put(key, value);
                System.out.println("Added: (" + key + ", " + value + ")");
            } else if (operation.equals("GET")) {
                int key = scanner.nextInt();
                String result = lruCache.get(key);
                System.out.println("Retrieved: " + (result != null ? result : "null"));
            }
        }
        scanner.close();
    }
}
