import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    private ArrayList<LinkedList<Node>> buckets;
    private int size;

    // Constructor initializes the buckets and sets the initial size to 0.
    public Main() {
        buckets = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            buckets.add(new LinkedList<>());
        }
        size = 0;
    }

    // Adds a key-value pair to the hash map. If the key already exists, it updates the value.
    // If the load factor exceeds 0.5, it rehashes the map.
    public void put(K key, V value) {
        int hash = Math.abs(key.hashCode() % buckets.size());
        LinkedList<Node> nodes = buckets.get(hash);
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                node.val = value;
                return;
            }
        }
        nodes.add(new Node(key, value));
        size++;
        if ((float) size / buckets.size() > 0.5f) {
            reHash();
        }
    }

    // Doubles the size of the buckets and re-inserts all nodes into the new buckets.
    private void reHash() {
        ArrayList<LinkedList<Node>> oldBuckets = buckets;
        buckets = new ArrayList<>();
        size = 0;
        for (int i = 0; i < oldBuckets.size() * 2; i++) {
            buckets.add(new LinkedList<>());
        }
        for (LinkedList<Node> nodes : oldBuckets) {
            for (Node node : nodes) {
                put(node.key, node.val);
            }
        }
    }

    // Retrieves the value associated with a given key.
    public V get(K key) {
        int hash = Math.abs(key.hashCode() % buckets.size());
        LinkedList<Node> nodes = buckets.get(hash);
        for (Node node : nodes) {
            if (node.key.equals(key)) {
                return node.val;
            }
        }
        return null;
    }

    // Removes the key-value pair from the hash map.
    public void remove(K key) {
        int hash = Math.abs(key.hashCode() % buckets.size());
        LinkedList<Node> nodes = buckets.get(hash);
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

    // Checks if the key exists in the hash map.
    public boolean containsKey(K key) {
        return get(key) != null;
    }

    // Returns the current size of the hash map.
    public int size() {
        return this.size;
    }

    // Returns a string representation of the hash map.
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("{");
        for (LinkedList<Node> nodes : buckets) {
            for (Node node : nodes) {
                builder.append(node.key).append(" : ").append(node.val).append(", ");
            }
        }
        if (builder.length() > 1) {
            builder.setLength(builder.length() - 2);
        }
        builder.append("}");
        return builder.toString();
    }

    // Represents a key-value pair.
    private class Node {
        K key;
        V val;

        Node(K key, V val) {
            this.key = key;
            this.val = val;
        }
    }

    // Provides a command-line interface to interact with the hash map.
    public static void main(String[] args) {
        Main<String, String> map = new Main<>();
        Scanner sc = new Scanner(System.in);
        int operations = Integer.parseInt(sc.nextLine().trim());
        for (int i = 0; i < operations; i++) {
            String[] command = sc.nextLine().split(" ");
            switch (command[0].toUpperCase()) {
                case "PUT":
                    map.put(command[1], command[2]);
                    break;
                case "GET":
                    String value = map.get(command[1]);
                    System.out.println(value != null ? value : "NOT FOUND");
                    break;
                case "REMOVE":
                    map.remove(command[1]);
                    break;
                case "CONTAINS":
                    System.out.println(map.containsKey(command[1]) ? "YES" : "NO");
                    break;
                case "SIZE":
                    System.out.println(map.size());
                    break;
                case "PRINT":
                    System.out.println(map);
                    break;
                default:
                    System.out.println("INVALID COMMAND");
            }
        }
        sc.close();
    }
}
