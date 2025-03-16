
import java.util.LinkedList;
import java.util.Scanner;
public class GenericHashMapUsingArray<K, V> {
    private int size; 
    private LinkedList<Node>[] buckets; 
    public GenericHashMapUsingArray() {
        initBuckets(16);
        size = 0;
    }
    private void initBuckets(int n) {
        buckets = new LinkedList[n];
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new LinkedList<>();
        }
    }
    public void put(K key, V value) {
        int bucketIndex = hashFunction(key);
        LinkedList<Node> nodes = buckets[bucketIndex];
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                node.value = value;
                return;
            }
        }
        nodes.add(new Node(key, value));
        size++;
        if ((float) size / buckets.length > 0.75f) {
            reHash();
        }
    }
    public V get(K key) {
        int bucketIndex = hashFunction(key);
        LinkedList<Node> nodes = buckets[bucketIndex];
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                return node.value;
            }
        }
        return null;
    }
    public void remove(K key) {
        int bucketIndex = hashFunction(key);
        LinkedList<Node> nodes = buckets[bucketIndex];
        Node target = null;
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                target = node;
                break;
            }
        }
        if (target != null) {
            nodes.remove(target);
            size--;
        }
    }
    public boolean containsKey(K key) {
        return get(key) != null;
    }
    public int size() {
        return size;
    }
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("{");
        for (LinkedList<Node> nodes : buckets) {
            for (Node node : nodes) {
                builder.append(node.key).append(" : ").append(node.value).append(", ");
            }
        }
        if (builder.length() > 1) {
            builder.setLength(builder.length() - 2);
        }
        builder.append("}");
        return builder.toString();
    }
    private int hashFunction(K key) {
        return Math.floorMod(key.hashCode(), buckets.length);
    }
    private void reHash() {
        LinkedList<Node>[] oldBuckets = buckets;
        initBuckets(oldBuckets.length * 2);
        size = 0;
        for (LinkedList<Node> nodes : oldBuckets) {
            for (Node node : nodes) {
                put(node.key, node.value);
            }
        }
    }
    private class Node {
        private final K key;
        private V value;
        public Node(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        GenericHashMapUsingArray<String, String> hashMap = new GenericHashMapUsingArray<>();
        int operations = scanner.nextInt();
        scanner.nextLine(); 
        for (int i = 0; i < operations; i++) {
            String command = scanner.next();
            switch (command) {
                case "PUT": {
                    String key = scanner.next();
                    String value = scanner.next();
                    hashMap.put(key, value);
                    break;
                }
                case "GET": {
                    String key = scanner.next();
                    String value = hashMap.get(key);
                    System.out.println(value != null ? value : "NOT FOUND");
                    break;
                }
                case "REMOVE": {
                    String key = scanner.next();
                    hashMap.remove(key);
                    break;
                }
                case "CONTAINS": {
                    String key = scanner.next();
                    System.out.println(hashMap.containsKey(key) ? "YES" : "NO");
                    break;
                }
                case "SIZE": {
                    System.out.println(hashMap.size());
                    break;
                }
                case "PRINT": {
                    System.out.println(hashMap);
                    break;
                }
                default:
                    System.out.println("INVALID COMMAND");
            }
        }
        scanner.close();
    }
}
