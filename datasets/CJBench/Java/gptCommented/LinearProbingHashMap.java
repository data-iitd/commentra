import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // Size of the hash table
    private int hsize;
    // Array to store keys
    private Key[] keys;
    // Array to store values
    private Value[] values;
    // Current number of elements in the hash table
    private int size;

    // Default constructor initializing with a default size
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

    // Method to insert a key-value pair into the hash table
    public boolean put(Key key, Value value) {
        // Return false if the key is null
        if (key == null) {
            return false;
        }
        // Resize the hash table if it is more than half full
        if (size > hsize / 2) {
            resize(2 * hsize);
        }
        // Calculate the index for the key
        int keyIndex = hash(key, hsize);
        // Handle collisions using linear probing
        for (; keys[keyIndex] != null; keyIndex = increment(keyIndex)) {
            // Update the value if the key already exists
            if (key.equals(keys[keyIndex])) {
                values[keyIndex] = value;
                return true;
            }
        }
        // Insert the new key-value pair
        keys[keyIndex] = key;
        values[keyIndex] = value;
        size++;
        return true;
    }

    // Method to retrieve a value associated with a key
    public Value get(Key key) {
        // Return null if the key is null
        if (key == null) {
            return null;
        }
        // Search for the key using linear probing
        for (int i = hash(key, hsize); keys[i] != null; i = increment(i)) {
            if (key.equals(keys[i])) {
                return values[i]; // Return the associated value
            }
        }
        return null; // Return null if the key is not found
    }

    // Method to delete a key-value pair from the hash table
    public boolean delete(Key key) {
        // Return false if the key is null or does not exist
        if (key == null || !contains(key)) {
            return false;
        }
        // Find the index of the key to be deleted
        int i = hash(key, hsize);
        while (!key.equals(keys[i])) {
            i = increment(i);
        }
        // Remove the key and value
        keys[i] = null;
        values[i] = null;
        i = increment(i);
        // Rehash the subsequent keys
        while (keys[i] != null) {
            Key keyToRehash = keys[i];
            Value valToRehash = values[i];
            keys[i] = null;
            values[i] = null;
            size--;
            put(keyToRehash, valToRehash); // Reinsert the key-value pair
            i = increment(i);
        }
        size--;
        // Resize the hash table if it is less than one-eighth full
        if (size > 0 && size <= hsize / 8) {
            resize(hsize / 2);
        }
        return true;
    }

    // Method to check if a key exists in the hash table
    public boolean contains(Key key) {
        return get(key) != null;
    }

    // Method to return the current number of elements in the hash table
    public int size() {
        return size;
    }

    // Method to return an iterable collection of keys in the hash table
    public Iterable<Key> keys() {
        ArrayList<Key> listOfKeys = new ArrayList<>(size);
        for (int i = 0; i < hsize; i++) {
            if (keys[i] != null) {
                listOfKeys.add(keys[i]); // Add non-null keys to the list
            }
        }
        listOfKeys.sort(Comparable::compareTo); // Sort the keys
        return listOfKeys;
    }

    // Helper method to increment the index for linear probing
    private int increment(int i) {
        return (i + 1) % hsize; // Wrap around using modulo
    }

    // Method to resize the hash table to a new size
    private void resize(int newSize) {
        Main<Key, Value> tmp = new Main<>(newSize); // Create a new hash table
        for (int i = 0; i < hsize; i++) {
            if (keys[i] != null) {
                tmp.put(keys[i], values[i]); // Reinsert existing key-value pairs
            }
        }
        this.keys = tmp.keys; // Update the keys array
        this.values = tmp.values; // Update the values array
        this.hsize = newSize; // Update the hash table size
    }

    // Method to compute the hash index for a given key
    private int hash(Key key, int size) {
        return (key.hashCode() & 0x7fffffff) % size; // Ensure non-negative index
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int initialSize = scanner.nextInt(); // Read initial size of the hash table
        Main<String, String> hashMap = new Main<>(initialSize); // Create a new hash map
        int operations = scanner.nextInt(); // Read number of operations
        scanner.nextLine(); // Consume the newline character
        // Process each operation
        for (int i = 0; i < operations; i++) {
            String[] input = scanner.nextLine().split(" ");
            String command = input[0].toUpperCase(); // Read the command
            switch (command) {
                case "PUT":
                    hashMap.put(input[1], input[2]); // Insert key-value pair
                    break;
                case "GET":
                    String value = hashMap.get(input[1]); // Retrieve value
                    System.out.println(value != null ? value : "NOT FOUND");
                    break;
                case "DELETE":
                    boolean deleted = hashMap.delete(input[1]); // Delete key-value pair
                    System.out.println(deleted ? "DELETED" : "NOT FOUND");
                    break;
                case "CONTAINS":
                    System.out.println(hashMap.contains(input[1]) ? "YES" : "NO"); // Check existence
                    break;
                case "SIZE":
                    System.out.println(hashMap.size()); // Print current size
                    break;
                case "KEYS":
                    for (String key : hashMap.keys()) {
                        System.out.print(key + " "); // Print all keys
                    }
                    System.out.println();
                    break;
                default:
                    System.out.println("INVALID COMMAND"); // Handle invalid commands
            }
        }
        scanner.close(); // Close the scanner
    }
}
