
import java.util.ArrayList;
import java.util.Comparable;
import java.util.Scanner;

public class Main<Key extends Comparable<Key>, Value> {

    // Declare instance variables
    private int hsize;
    private Key[] keys;
    private Value[] values;
    private int size;

    // Default constructor
    public Main() {
        this(16);
    }

    // Constructor with specified size
    @SuppressWarnings("unchecked")
    public Main(int size) {
        this.hsize = size;
        // Initialize keys and values arrays with specified size
        keys = (Key[]) new Comparable[size];
        values = (Value[]) new Object[size];
    }

    // Put method to add a key-value pair to the hash map
    public boolean put(Key key, Value value) {
        if (key == null) {
            // Return false if key is null
            return false;
        }
        if (size > hsize / 2) {
            // If size is more than half of hash map size, resize the hash map
            resize(2 * hsize);
        }
        int keyIndex = hash(key, hsize);
        // Search for the index where the key already exists
        for (; keys[keyIndex] != null; keyIndex = increment(keyIndex)) {
            if (key.equals(keys[keyIndex])) {
                // If key already exists, update its value and return true
                values[keyIndex] = value;
                return true;
            }
        }
        // If key doesn't exist, add it to the hash map and increment size
        keys[keyIndex] = key;
        values[keyIndex] = value;
        size++;
        return true;
    }

    // Get method to retrieve the value associated with a key
    public Value get(Key key) {
        if (key == null) {
            // Return null if key is null
            return null;
        }
        for (int i = hash(key, hsize); keys[i] != null; i = increment(i)) {
            if (key.equals(keys[i])) {
                // If key is found, return its value
                return values[i];
            }
        }
        // If key is not found, return null
        return null;
    }

    // Delete method to remove a key-value pair from the hash map
    public boolean delete(Key key) {
        if (key == null || !contains(key)) {
            // Return false if key is null or not found in the hash map
            return false;
        }
        int i = hash(key, hsize);
        // Find the index of the key in the hash map
        while (!key.equals(keys[i])) {
            i = increment(i);
        }
        // Set keys and values at the index to null and increment i
        keys[i] = null;
        values[i] = null;
        i = increment(i);
        // Rehash the deleted key and its corresponding value
        while (keys[i] != null) {
            Key keyToRehash = keys[i];
            Value valToRehash = values[i];
            keys[i] = null;
            values[i] = null;
            size--;
            // Put the rehashed key-value pair back into the hash map
            put(keyToRehash, valToRehash);
            i = increment(i);
        }
        size--;
        // If size is less than or equal to one-eighth of the hash map size, resize it
        if (size > 0 && size <= hsize / 8) {
            resize(hsize / 2);
        }
        // Return true if the key was successfully deleted
        return true;
    }

    // Check if a key exists in the hash map
    public boolean contains(Key key) {
        // Return true if the get method returns a non-null value
        return get(key) != null;
    }

    // Get the size of the hash map
    public int size() {
        // Return the size instance variable
        return size;
    }

    // Get an iterable of all the keys in the hash map
    public Iterable<Key> keys() {
        // Create an ArrayList to store the keys
        ArrayList<Key> listOfKeys = new ArrayList<>(size);
        // Iterate through each index in the hash map and add the keys to the ArrayList
        for (int i = 0; i < hsize; i++) {
            if (keys[i] != null) {
                listOfKeys.add(keys[i]);
            }
        }
        // Sort the keys in the ArrayList and return it
        listOfKeys.sort(Comparable::compareTo);
        return listOfKeys;
    }

    // Increment the index based on the hash map size
    private int increment(int i) {
        return (i + 1) % hsize;
    }

    // Resize the hash map with a new size
    private void resize(int newSize) {
        // Create a new Main object with the new size
        Main<Key, Value> tmp = new Main<>(newSize);
        // Iterate through each index in the old hash map and put the keys and values into the new hash map
        for (int i = 0; i < hsize; i++) {
            if (keys[i] != null) {
                tmp.put(keys[i], values[i]);
            }
        }
        // Replace the old hash map instance variables with the new ones
        this.keys = tmp.keys;
        this.values = tmp.values;
        this.hsize = newSize;
    }

    // Hash a key based on its hash code and the hash map size
    private int hash(Key key, int size) {
        return (key.hashCode() & 0x7fffffff) % size;
    }

    // Main method to read input and perform hash map operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int initialSize = scanner.nextInt();
        // Create a new Main object with the initial size
        Main<String, String> hashMap = new Main<>(initialSize);
        int operations = scanner.nextInt();
        scanner.nextLine(); 
        // Perform the specified number of operations
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