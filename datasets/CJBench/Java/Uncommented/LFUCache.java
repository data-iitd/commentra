
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
public class LFUCache<K, V> {
    private class Node {
        private final K key;
        private V value;
        private int frequency;
        private Node previous;
        private Node next;
        Node(K key, V value, int frequency) {
            this.key = key;
            this.value = value;
            this.frequency = frequency;
        }
    }
    private Node head;
    private Node tail;
    private final Map<K, Node> cache;
    private final int capacity;
    public LFUCache(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Capacity must be greater than zero.");
        }
        this.capacity = capacity;
        this.cache = new HashMap<>();
    }
    public V get(K key) {
        Node node = cache.get(key);
        if (node == null) {
            return null;
        }
        removeNode(node);
        node.frequency += 1;
        addNodeWithUpdatedFrequency(node);
        return node.value;
    }
    public void put(K key, V value) {
        if (cache.containsKey(key)) {
            Node node = cache.get(key);
            node.value = value;
            node.frequency += 1;
            removeNode(node);
            addNodeWithUpdatedFrequency(node);
        } else {
            if (cache.size() >= capacity) {
                cache.remove(this.head.key);
                removeNode(head);
            }
            Node node = new Node(key, value, 1);
            addNodeWithUpdatedFrequency(node);
            cache.put(key, node);
        }
    }
    private void addNodeWithUpdatedFrequency(Node node) {
        if (tail != null && head != null) {
            Node temp = this.head;
            while (temp != null) {
                if (temp.frequency > node.frequency) {
                    if (temp == head) {
                        node.next = temp;
                        temp.previous = node;
                        this.head = node;
                        break;
                    } else {
                        node.next = temp;
                        node.previous = temp.previous;
                        temp.previous.next = node;
                        temp.previous = node;
                        break;
                    }
                } else {
                    temp = temp.next;
                    if (temp == null) {
                        tail.next = node;
                        node.previous = tail;
                        node.next = null;
                        tail = node;
                        break;
                    }
                }
            }
        } else {
            tail = node;
            head = tail;
        }
    }
    private void removeNode(Node node) {
        if (node.previous != null) {
            node.previous.next = node.next;
        } else {
            this.head = node.next;
        }
        if (node.next != null) {
            node.next.previous = node.previous;
        } else {
            this.tail = node.previous;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int capacity = scanner.nextInt();
        int operations = scanner.nextInt();
        LFUCache<Integer, String> lfuCache = new LFUCache<>(capacity);
        for (int i = 0; i < operations; i++) {
            String operation = scanner.next();
            if (operation.equals("PUT")) {
                int key = scanner.nextInt();
                String value = scanner.next();
                lfuCache.put(key, value);
                System.out.println("Added: (" + key + ", " + value + ")");
            } else if (operation.equals("GET")) {
                int key = scanner.nextInt();
                String result = lfuCache.get(key);
                System.out.println("Retrieved: " + (result != null ? result : "null"));
            }
        }
        scanner.close();
    }
}
