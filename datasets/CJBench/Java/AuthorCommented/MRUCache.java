
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Represents a Most Recently Used (MRU) Cache.
 * <p>
 * In contrast to the Least Recently Used (LRU) strategy, the MRU caching policy
 * evicts the most recently accessed items first. This class provides methods to
 * store key-value pairs and manage cache eviction based on this policy.
 *
 * For more information, refer to:
 * <a href="https://en.wikipedia.org/wiki/Cache_replacement_policies#Most_recently_used_(MRU)">MRU on Wikipedia</a>.
 *
 * @param <K> the type of keys maintained by this cache
 * @param <V> the type of values associated with the keys
 */
public class MRUCache<K, V> {

    private final Map<K, Entry<K, V>> data = new HashMap<>();
    private Entry<K, V> head;
    private Entry<K, V> tail;
    private final int capacity;

    
    public MRUCache(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Capacity must be greater than 0!");
        }
        this.capacity = capacity;
    }

    /**
     * Retrieves the value associated with the specified key.
     *
     * @param key the key whose associated value is to be returned
     * @return the value associated with the specified key, or null if the key does not exist
     */
    public V get(K key) {
        if (!data.containsKey(key)) {
            return null;
        }
        final Entry<K, V> entry = data.get(key);
        moveEntryToLast(entry);
        return entry.getValue();
    }

    /**
     * Associates the specified value with the specified key in the cache.
     * If the key already exists, its value is updated and the entry is moved to the most recently used position.
     * If the cache is full, the most recently used entry is evicted before adding the new entry.
     *
     * @param key   the key with which the specified value is to be associated
     * @param value the value to be associated with the specified key
     */
    public void put(K key, V value) {
        if (data.containsKey(key)) {
            final Entry<K, V> existingEntry = data.get(key);
            existingEntry.setValue(value);
            moveEntryToLast(existingEntry);
            return;
        }

        if (data.size() == capacity) {
            data.remove(tail.getKey());
            remove(tail);
        }

        Entry<K, V> newEntry = new Entry<>(null, null, key, value);
        addNewEntry(newEntry);
        data.put(key, newEntry);
    }

    /**
     * Moves the specified entry to the most recently used position in the cache.
     *
     * @param entry the entry to be moved
     */
    private void moveEntryToLast(Entry<K, V> entry) {
        if (tail == entry) {
            return;
        }
        remove(entry);
        addNewEntry(entry);
    }

    private void remove(Entry<K, V> entry) {
        if (entry.getPreEntry() != null) {
            entry.getPreEntry().setNextEntry(entry.getNextEntry());
        } else {
            head = entry.getNextEntry();
        }

        if (entry.getNextEntry() != null) {
            entry.getNextEntry().setPreEntry(entry.getPreEntry());
        } else {
            tail = entry.getPreEntry();
        }
    }

    /**
     * Adds a new entry to the cache and updates the head and tail pointers accordingly.
     *
     * @param newEntry the new entry to be added
     */
    private void addNewEntry(Entry<K, V> entry) {
        if (tail != null) {
            tail.setNextEntry(entry);
            entry.setPreEntry(tail);
        }
        tail = entry;
        if (head == null) {
            head = tail;
        }
    }

    /**
     * A nested class representing an entry in the cache, which holds a key-value pair
     * and references to the previous and next entries in the linked list structure.
     *
     * @param <I> the type of the key
     * @param <J> the type of the value
     */
    private static class Entry<K, V> {
        private Entry<K, V> preEntry;
        private Entry<K, V> nextEntry;
        private final K key;
        private V value;

        public Entry(Entry<K, V> preEntry, Entry<K, V> nextEntry, K key, V value) {
            this.preEntry = preEntry;
            this.nextEntry = nextEntry;
            this.key = key;
            this.value = value;
        }

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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int capacity = scanner.nextInt();
        int operations = scanner.nextInt();
        MRUCache<Integer, String> mruCache = new MRUCache<>(capacity);

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
