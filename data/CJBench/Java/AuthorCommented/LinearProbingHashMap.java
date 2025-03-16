
import java.util.ArrayList;
import java.util.Scanner;

/**
 * This class implements a hash table using linear probing to resolve collisions.
 * Linear probing is a collision resolution method where each slot in the hash table is checked in a sequential manner
 * until an empty slot is found.
 *
 * <p>
 * The class allows for storing key-value pairs, where both the key and value are generic types.
 * The key must be of a type that implements the Comparable interface to ensure that the keys can be compared for sorting.
 * </p>
 *
 * <p>
 * This implementation supports basic operations such as:
 * <ul>
 *     <li><b>put(Key key, Value value)</b>: Adds a key-value pair to the hash table. If the key already exists, its value is updated.</li>
 *     <li><b>get(Key key)</b>: Retrieves the value associated with the given key.</li>
 *     <li><b>delete(Key key)</b>: Removes the key and its associated value from the hash table.</li>
 *     <li><b>contains(Key key)</b>: Checks if the hash table contains a given key.</li>
 *     <li><b>size()</b>: Returns the number of key-value pairs in the hash table.</li>
 *     <li><b>keys()</b>: Returns an iterable collection of keys stored in the hash table.</li>
 * </ul>
 * </p>
 *
 * <p>
 * The internal size of the hash table is automatically resized when the load factor exceeds 0.5 or falls below 0.125,
 * ensuring efficient space utilization.
 * </p>
 *
 * @see <a href="https://en.wikipedia.org/wiki/Linear_probing">Linear Probing Hash Table</a>
 *
 * @param <Key> the type of keys maintained by this map
 * @param <Value> the type of mapped values
 */
public class LinearProbingHashMap<Key extends Comparable<Key>, Value> {
    private int hsize;
    private Key[] keys;
    private Value[] values;
    private int size;

    // Default constructor initializes the table with a default size of 16
    public LinearProbingHashMap() {
        this(16);
    }

    @SuppressWarnings("unchecked")
    // Constructor to initialize the hash table with a specified size
    public LinearProbingHashMap(int size) {
        this.hsize = size;
        keys = (Key[]) new Comparable[size];
        values = (Value[]) new Object[size];
    }

    public boolean put(Key key, Value value) {
        if (key == null) {
            return false;
        }

        if (size > hsize / 2) {
            resize(2 * hsize);
        }

        int keyIndex = hash(key, hsize);
        for (; keys[keyIndex] != null; keyIndex = increment(keyIndex)) {
            if (key.equals(keys[keyIndex])) {
                values[keyIndex] = value;
                return true;
            }
        }

        keys[keyIndex] = key;
        values[keyIndex] = value;
        size++;
        return true;
    }

    public Value get(Key key) {
        if (key == null) {
            return null;
        }

        for (int i = hash(key, hsize); keys[i] != null; i = increment(i)) {
            if (key.equals(keys[i])) {
                return values[i];
            }
        }

        return null;
    }

    public boolean delete(Key key) {
        if (key == null || !contains(key)) {
            return false;
        }

        int i = hash(key, hsize);
        while (!key.equals(keys[i])) {
            i = increment(i);
        }

        keys[i] = null;
        values[i] = null;

        i = increment(i);
        while (keys[i] != null) {
            Key keyToRehash = keys[i];
            Value valToRehash = values[i];
            keys[i] = null;
            values[i] = null;
            size--;
            put(keyToRehash, valToRehash);
            i = increment(i);
        }

        size--;
        if (size > 0 && size <= hsize / 8) {
            resize(hsize / 2);
        }

        return true;
    }

    public boolean contains(Key key) {
        return get(key) != null;
    }

    public int size() {
        return size;
    }

    public Iterable<Key> keys() {
        ArrayList<Key> listOfKeys = new ArrayList<>(size);
        for (int i = 0; i < hsize; i++) {
            if (keys[i] != null) {
                listOfKeys.add(keys[i]);
            }
        }
        listOfKeys.sort(Comparable::compareTo);
        return listOfKeys;
    }

    private int increment(int i) {
        return (i + 1) % hsize;
    }

    private void resize(int newSize) {
        LinearProbingHashMap<Key, Value> tmp = new LinearProbingHashMap<>(newSize);
        for (int i = 0; i < hsize; i++) {
            if (keys[i] != null) {
                tmp.put(keys[i], values[i]);
            }
        }

        this.keys = tmp.keys;
        this.values = tmp.values;
        this.hsize = newSize;
    }

    private int hash(Key key, int size) {
        return (key.hashCode() & 0x7fffffff) % size;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int initialSize = scanner.nextInt();
        LinearProbingHashMap<String, String> hashMap = new LinearProbingHashMap<>(initialSize);

        int operations = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        for (int i = 0; i < operations; i++) {
            String[] input = scanner.nextLine().split(" ");
            String command = input[0].toUpperCase();

            switch (command) {
                case "PUT":
                    hashMap.put(input[1], input[2]);
                    break;
                case "GET":
                    String value = hashMap.get(input[1]);
                    System.out.println(value != null ? value : "NOT FOUND");
                    break;
                case "DELETE":
                    boolean deleted = hashMap.delete(input[1]);
                    System.out.println(deleted ? "DELETED" : "NOT FOUND");
                    break;
                case "CONTAINS":
                    System.out.println(hashMap.contains(input[1]) ? "YES" : "NO");
                    break;
                case "SIZE":
                    System.out.println(hashMap.size());
                    break;
                case "KEYS":
                    for (String key : hashMap.keys()) {
                        System.out.print(key + " ");
                    }
                    System.out.println();
                    break;
                default:
                    System.out.println("INVALID COMMAND");
            }
        }

        scanner.close();
    }
}
