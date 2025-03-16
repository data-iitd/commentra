
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
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
    public V get(K key) {
        if (!data.containsKey(key)) {
            return null;
        }
        final Entry<K, V> entry = data.get(key);
        moveToLast(entry);
        return entry.getValue();
    }
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
