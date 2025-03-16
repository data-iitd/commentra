
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * A Least Recently Used (LRU) Cache implementation.
 *
 * <p>An LRU cache is a fixed-size cache that maintains items in order of use. When the cache reaches
 * its capacity and a new item needs to be added, it removes the least recently used item first.
 * This implementation provides O(1) time complexity for both get and put operations.</p>
 *
 * <p>Features:</p>
 * <ul>
 *   <li>Fixed-size cache with configurable capacity</li>
 *   <li>Constant time O(1) operations for get and put</li>
 *   <li>Thread-unsafe - should be externally synchronized if used in concurrent environments</li>
 *   <li>Supports null values but not null keys</li>
 * </ul>
 *
 * <p>Implementation Details:</p>
 * <ul>
 *   <li>Uses a HashMap for O(1) key-value lookups</li>
 *   <li>Maintains a doubly-linked list for tracking access order</li>
 *   <li>The head of the list contains the least recently used item</li>
 *   <li>The tail of the list contains the most recently used item</li>
 * </ul>
 *
 * <p>Example usage:</p>
 * <pre>
 * LRUCache<String, Integer> cache = new LRUCache<>(3); // Create cache with capacity 3
 * cache.put("A", 1); // Cache: A=1
 * cache.put("B", 2); // Cache: A=1, B=2
 * cache.put("C", 3); // Cache: A=1, B=2, C=3
 * cache.get("A");    // Cache: B=2, C=3, A=1 (A moved to end)
 * cache.put("D", 4); // Cache: C=3, A=1, D=4 (B evicted)
 * </pre>
 *
 * @param <K> the type of keys maintained by this cache
 * @param <V> the type of mapped values
 */
public class LRUCache<K, V> {

    private final Map<K, Entry<K, V>> data = new HashMap<>();
    private Entry<K, V> head;
    private Entry<K, V> tail;
    private final int capacity;

    public LRUCache(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Capacity must be greater than 0.");
        }
        this.capacity = capacity;
    }

    /**
     * Returns the value to which the specified key is mapped, or null if this cache contains no
     * mapping for the key.
     *
     * @param key the key whose associated value is to be returned
     * @return the value to which the specified key is mapped, or null if this cache contains no
     * mapping for the key
     */
    public V get(K key) {
        if (!data.containsKey(key)) {
            return null;
        }
        final Entry<K, V> entry = data.get(key);
        moveToLast(entry);
        return entry.getValue();
    }

    /**
     * Associates the specified value with the specified key in this cache.
     *
     * @param key the key with which the specified value is to be associated
     * @param value the value to be associated with the specified key
     */
    public void put(K key, V value) {
        if (data.containsKey(key)) {
            final Entry<K, V> existingEntry = data.get(key);
            existingEntry.setValue(value);
            moveToLast(existingEntry);
            return;
        }

        if (data.size() == capacity) {
            data.remove(head.getKey());
            remove(head);
        }

        Entry<K, V> newEntry = new Entry<>(key, value);
        addLast(newEntry);
        data.put(key, newEntry);
    }

    /**
     * Moves the specified entry to the end of the list.
     *
     * @param entry the entry to move
     */
    private void moveToLast(Entry<K, V> entry) {
        if (entry == tail) {
            return;
        }
        remove(entry);
        addLast(entry);
    }

    private void remove(Entry<K, V> entry) {
        if (entry.getPrev() != null) {
            entry.getPrev().setNext(entry.getNext());
        } else {
            head = entry.getNext();
        }

        if (entry.getNext() != null) {
            entry.getNext().setPrev(entry.getPrev());
        } else {
            tail = entry.getPrev();
        }
    }

    private void addLast(Entry<K, V> entry) {
        if (tail != null) {
            tail.setNext(entry);
            entry.setPrev(tail);
        }
        tail = entry;
        if (head == null) {
            head = tail;
        }
    }

    private static class Entry<K, V> {
        private final K key;
        private V value;
        private Entry<K, V> prev;
        private Entry<K, V> next;

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
        LRUCache<Integer, String> lruCache = new LRUCache<>(capacity);

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
