
import java.util.Scanner;
public class HashMap<K, V> {
    private final int hashSize;
    private final LinkedList<K, V>[] buckets;
    private int size; 
    @SuppressWarnings("unchecked")
    public HashMap(int hashSize) {
        this.hashSize = hashSize;
        this.buckets = new LinkedList[hashSize];
        for (int i = 0; i < hashSize; i++) {
            buckets[i] = new LinkedList<>();
        }
        this.size = 0;
    }
    private int computeHash(K key) {
        if (key == null) {
            return 0;
        }
        int hash = key.hashCode() % hashSize;
        return hash < 0 ? hash + hashSize : hash;
    }
    public void insert(K key, V value) {
        int hash = computeHash(key);
        if (buckets[hash].insert(key, value)) {
            size++;
        }
    }
    public void delete(K key) {
        int hash = computeHash(key);
        if (buckets[hash].delete(key)) {
            size--;
        }
    }
    public V search(K key) {
        int hash = computeHash(key);
        Node<K, V> node = buckets[hash].findKey(key);
        return node != null ? node.getValue() : null;
    }
    public void display() {
        for (int i = 0; i < hashSize; i++) {
            System.out.printf("Bucket %d: %s%n", i, buckets[i].display());
        }
    }
    public int size() {
        return size;
    }
    public static class LinkedList<K, V> {
        private Node<K, V> head;
        public boolean insert(K key, V value) {
            Node<K, V> existingNode = findKey(key);
            if (existingNode != null) {
                existingNode.setValue(value);
                return false;
            }
            Node<K, V> newNode = new Node<>(key, value);
            newNode.setNext(head);
            head = newNode;
            return true;
        }
        public boolean delete(K key) {
            if (head == null) {
                return false;
            }
            if ((key == null && head.getKey() == null) || (head.getKey() != null && head.getKey().equals(key))) {
                head = head.getNext();
                return true;
            }
            Node<K, V> current = head;
            while (current.getNext() != null) {
                if ((key == null && current.getNext().getKey() == null) || (current.getNext().getKey() != null && current.getNext().getKey().equals(key))) {
                    current.setNext(current.getNext().getNext());
                    return true;
                }
                current = current.getNext();
            }
            return false;
        }
        public Node<K, V> findKey(K key) {
            Node<K, V> current = head;
            while (current != null) {
                if ((key == null && current.getKey() == null) || (current.getKey() != null && current.getKey().equals(key))) {
                    return current;
                }
                current = current.getNext();
            }
            return null;
        }
        public String display() {
            StringBuilder sb = new StringBuilder();
            Node<K, V> current = head;
            while (current != null) {
                sb.append(current.getKey()).append("=").append(current.getValue());
                current = current.getNext();
                if (current != null) {
                    sb.append(" -> ");
                }
            }
            return sb.length() > 0 ? sb.toString() : "null";
        }
    }
    public static class Node<K, V> {
        private final K key;
        private V value;
        private Node<K, V> next;
        public Node(K key, V value) {
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
        public Node<K, V> getNext() {
            return next;
        }
        public void setNext(Node<K, V> next) {
            this.next = next;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int hashSize = scanner.nextInt();
        HashMap<String, String> hashMap = new HashMap<>(hashSize);
        int operations = scanner.nextInt();
        scanner.nextLine(); 
        for (int i = 0; i < operations; i++) {
            String[] input = scanner.nextLine().split(" ");
            switch (input[0]) {
                case "PUT":
                    hashMap.insert(input[1], input[2]);
                    break;
                case "GET":
                    String value = hashMap.search(input[1]);
                    System.out.println(value != null ? value : "NOT FOUND");
                    break;
                case "REMOVE":
                    hashMap.delete(input[1]);
                    break;
                case "CONTAINS":
                    System.out.println(hashMap.search(input[1]) != null ? "YES" : "NO");
                    break;
                case "SIZE":
                    System.out.println(hashMap.size());
                    break;
                case "PRINT":
                    hashMap.display();
                    break;
                default:
                    System.out.println("Invalid operation");
            }
        }
        scanner.close();
    }
}
