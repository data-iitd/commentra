import java.util.ArrayList;
import java.util.Scanner;
public class Main {
    private int hsize; // Size of the hash table
    private Key[] keys; // Array to store keys
    private Value[] values; // Array to store values
    private int size; // Number of key-value pairs in the hash table

    // Default constructor initializes the hash table with a size of 16
    public Main() {
        this(16);
    }

    // Constructor that initializes the hash table with a specified size
    @SuppressWarnings("unchecked")
    public Main(int size) {
        this.hsize = size;
        keys = (Key[]) new Comparable[size];
        values = (Value[]) new Object[size];
    }

    // Inserts a key-value pair into the hash table
    public boolean put(Key key, Value value) {
        if (key == null) { // Check if the key is null
            return false;
        }
        if (size > hsize / 2) { // Check if the hash table needs to be resized
            resize(2 * hsize);
        }
        int keyIndex = hash(key, hsize); // Calculate the index for the key
        for (; keys[keyIndex] != null; keyIndex = increment(keyIndex)) { // Handle collisions by probing
            if (key.equals(keys[keyIndex])) { // If the key already exists, update the value
                values[keyIndex] = value;
                return true;
            }
        }
        keys[keyIndex] = key; // Insert the key-value pair
        values[keyIndex] = value;
        size++; // Increment the size of the hash table
        return true;
    }

    // Retrieves the value associated with a given key
    public Value get(Key key) {
        if (key == null) { // Check if the key is null
            return null;
        }
        for (int i = hash(key, hsize); keys[i] != null; i = increment(i)) { // Calculate the index for the key and search
            if (key.equals(keys[i])) { // If the key is found, return the associated value
                return values[i];
            }
        }
        return null; // If the key is not found, return null
    }

    // Removes a key-value pair from the hash table
    public boolean delete(Key key) {
        if (key == null || !contains(key)) { // Check if the key is null or not found
            return false;
        }
        int i = hash(key, hsize);
        while (!key.equals(keys[i])) { // Find the index of the key
            i = increment(i);
        }
        keys[i] = null; // Remove the key-value pair
        values[i] = null;
        i = increment(i);
        while (keys[i] != null) { // Rehash all keys in the hash table
            Key keyToRehash = keys[i];
            Value valToRehash = values[i];
            keys[i] = null;
            values[i] = null;
            size--;
            put(keyToRehash, valToRehash);
            i = increment(i);
        }
        size--; // Decrement the size of the hash table
        if (size > 0 && size <= hsize / 8) { // Check if the hash table needs to be resized
            resize(hsize / 2);
        }
        return true;
    }

    // Checks if a key is present in the hash table
    public boolean contains(Key key) {
        return get(key) != null; // Return true if the key is found, otherwise false
    }

    // Returns the number of key-value pairs in the hash table
    public int size() {
        return size;
    }

    // Returns an iterable collection of all keys in the hash table
    public Iterable<Key> keys() {
        ArrayList<Key> listOfKeys = new ArrayList<>(size);
        for (int i = 0; i < hsize; i++) {
            if (keys[i] != null) {
                listOfKeys.add(keys[i]);
            }
        }
        listOfKeys.sort(Comparable::compareTo); // Sort the keys
        return listOfKeys;
    }

    // Calculates the next index in the hash table
    private int increment(int i) {
        return (i + 1) % hsize;
    }

    // Resizes the hash table to a new size
    private void resize(int newSize) {
        Main<Key, Value> tmp = new Main<>(newSize);
        for (int i = 0; i < hsize; i++) {
            if (keys[i] != null) {
                tmp.put(keys[i], values[i]);
            }
        }
        this.keys = tmp.keys;
        this.values = tmp.values;
        this.hsize = newSize;
    }

    // Calculates the hash code for a given key
    private int hash(Key key, int size) {
        return (key.hashCode() & 0x7fffffff) % size;
    }

    // Entry point of the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int initialSize = scanner.nextInt();
        Main<String, String> hashMap = new Main<>(initialSize);
        int operations = scanner.nextInt();
        scanner.nextLine(); 
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
