import java.util.BitSet;
import java.util.Scanner;

public class Main {
    // Number of hash functions to be used in the Bloom filter
    private final int numberOfHashFunctions;
    // Bit array to represent the Bloom filter
    private final BitSet bitArray;
    // Array to hold the hash functions
    private final Hash<T>[] hashFunctions;

    // Constructor to initialize the Bloom filter with the specified number of hash functions and bit array size
    public Main(int numberOfHashFunctions, int bitArraySize) {
        // Validate input parameters to ensure they are greater than 0
        if (numberOfHashFunctions < 1 || bitArraySize < 1) {
            throw new IllegalArgumentException("Number of hash functions and bit array size must be greater than 0");
        }
        this.numberOfHashFunctions = numberOfHashFunctions;
        this.bitArray = new BitSet(bitArraySize);
        this.hashFunctions = new Hash[numberOfHashFunctions];
        // Initialize the hash functions
        initializeHashFunctions();
    }

    // Method to initialize the hash functions based on the number of hash functions specified
    private void initializeHashFunctions() {
        for (int i = 0; i < numberOfHashFunctions; i++) {
            hashFunctions[i] = new Hash<>(i);
        }
    }

    // Method to insert a key into the Bloom filter
    public void insert(T key) {
        // For each hash function, compute the position and set the corresponding bit in the bit array
        for (Hash<T> hash : hashFunctions) {
            int position = Math.abs(hash.compute(key) % bitArray.size());
            bitArray.set(position);
        }
    }

    // Method to check if a key might be in the Bloom filter
    public boolean contains(T key) {
        // For each hash function, check if the corresponding bit is set in the bit array
        for (Hash<T> hash : hashFunctions) {
            int position = Math.abs(hash.compute(key) % bitArray.size());
            if (!bitArray.get(position)) {
                return false; // If any bit is not set, the key is definitely not in the set
            }
        }
        return true; // If all bits are set, the key might be in the set
    }

    // Inner class to represent a hash function
    private static class Hash<T> {
        // Index of the hash function
        private final int index;

        // Constructor to initialize the hash function with its index
        Hash(int index) {
            this.index = index;
        }

        // Method to compute the hash value for a given key
        public int compute(T key) {
            return index * asciiString(String.valueOf(key));
        }

        // Method to compute the ASCII sum of the characters in a string
        private int asciiString(String word) {
            int sum = 0;
            for (char c : word.toCharArray()) {
                sum += c; // Sum the ASCII values of each character
            }
            return sum;
        }
    }

    // Main method to run the Bloom filter program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of hash functions, bit array size, and number of elements to insert
        int numberOfHashFunctions = scanner.nextInt();
        int bitArraySize = scanner.nextInt();
        int numberOfElements = scanner.nextInt();
        
        // Create a new Bloom filter instance
        Main<String> bloomFilter = new Main<>(numberOfHashFunctions, bitArraySize);
        
        // Insert elements into the Bloom filter
        for (int i = 0; i < numberOfElements; i++) {
            String element = scanner.next();
            bloomFilter.insert(element);
        }
        
        // Read a query element to check its presence in the Bloom filter
        String query = scanner.next();
        boolean result = bloomFilter.contains(query);
        
        // Output the result of the query
        System.out.println("Element might be in the set: " + result);
    }
}
