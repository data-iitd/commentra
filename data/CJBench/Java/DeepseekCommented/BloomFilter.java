
import java.util.BitSet;
import java.util.Scanner;
public class Main {
    private final int numberOfHashFunctions; // Number of hash functions used in the Bloom filter
    private final BitSet bitArray; // Bit array to store the Bloom filter bits
    private final Hash<T>[] hashFunctions; // Array to store the hash functions
    
    // Constructor to initialize the Bloom filter with given number of hash functions and bit array size
    public Main(int numberOfHashFunctions, int bitArraySize) {
        if (numberOfHashFunctions < 1 || bitArraySize < 1) {
            throw new IllegalArgumentException("Number of hash functions and bit array size must be greater than 0");
        }
        this.numberOfHashFunctions = numberOfHashFunctions;
        this.bitArray = new BitSet(bitArraySize); // Initialize the bit array with the given size
        this.hashFunctions = new Hash[numberOfHashFunctions]; // Initialize the array for hash functions
        initializeHashFunctions(); // Initialize the hash functions
    }
    
    // Method to initialize the hash functions
    private void initializeHashFunctions() {
        for (int i = 0; i < numberOfHashFunctions; i++) {
            hashFunctions[i] = new Hash<>(i); // Create and initialize each hash function
        }
    }
    
    // Method to insert a key into the Bloom filter
    public void insert(T key) {
        for (Hash<T> hash : hashFunctions) {
            int position = Math.abs(hash.compute(key) % bitArray.size()); // Compute the position in the bit array
            bitArray.set(position); // Set the bit at the computed position
        }
    }
    
    // Method to check if a key might be present in the Bloom filter
    public boolean contains(T key) {
        for (Hash<T> hash : hashFunctions) {
            int position = Math.abs(hash.compute(key) % bitArray.size()); // Compute the position in the bit array
            if (!bitArray.get(position)) { // If any bit is not set, the key is not in the filter
                return false;
            }
        }
        return true; // All bits are set, so the key might be in the filter
    }
    
    // Inner class to compute a hash value for a given key
    private static class Hash<T> {
        private final int index; // Index of the hash function
        
        // Constructor to initialize the hash function with an index
        Hash(int index) {
            this.index = index;
        }
        
        // Method to compute the hash value for a given key
        public int compute(T key) {
            return index * asciiString(String.valueOf(key)); // Compute the hash value using the key's ASCII sum
        }
        
        // Helper method to compute the ASCII sum of a string
        private int asciiString(String word) {
            int sum = 0;
            for (char c : word.toCharArray()) {
                sum += c;
            }
            return sum;
        }
    }
    
    // Main method to run the Bloom filter program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfHashFunctions = scanner.nextInt(); // Read the number of hash functions from input
        int bitArraySize = scanner.nextInt(); // Read the bit array size from input
        int numberOfElements = scanner.nextInt(); // Read the number of elements to insert from input
        Main<String> bloomFilter = new Main<>(numberOfHashFunctions, bitArraySize); // Create a Bloom filter instance
        for (int i = 0; i < numberOfElements; i++) {
            String element = scanner.next(); // Read each element to insert
            bloomFilter.insert(element); // Insert the element into the Bloom filter
        }
        String query = scanner.next(); // Read the query element from input
        boolean result = bloomFilter.contains(query); // Check if the query element is in the Bloom filter
        System.out.println("Element might be in the set: " + result); // Print the result
    }
}

These comments provide a clear understanding of each part of the code, making it easier to understand and maintain.