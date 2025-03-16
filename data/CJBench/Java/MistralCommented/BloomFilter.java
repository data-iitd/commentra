
import java.util.BitSet;
import java.util.Scanner;

public class Main<T> {
    // The number of hash functions used in the Bloom filter
    private final int numberOfHashFunctions;

    // The bit array used to store the hash values
    private final BitSet bitArray;

    // An array of hash functions
    private final Hash<T>[] hashFunctions;

    /**
     * Constructor for the Main class.
     *
     * @param numberOfHashFunctions The number of hash functions to use in the Bloom filter
     * @param bitArraySize         The size of the bit array
     */
    public Main(int numberOfHashFunctions, int bitArraySize) {
        // Check if the number of hash functions and bit array size are greater than 0
        if (numberOfHashFunctions < 1 || bitArraySize < 1) {
            throw new IllegalArgumentException("Number of hash functions and bit array size must be greater than 0");
        }

        this.numberOfHashFunctions = numberOfHashFunctions;
        this.bitArray = new BitSet(bitArraySize);
        this.hashFunctions = new Hash[numberOfHashFunctions];

        // Initialize the hash functions
        initializeHashFunctions();
    }

    /**
     * Initializes the hash functions.
     */
    private void initializeHashFunctions() {
        for (int i = 0; i < numberOfHashFunctions; i++) {
            // Create a new hash function and add it to the array
            hashFunctions[i] = new Hash<>(i);
        }
    }

    /**
     * Inserts a key into the Bloom filter.
     *
     * @param key The key to be inserted
     */
    public void insert(T key) {
        for (Hash<T> hash : hashFunctions) {
            // Compute the position in the bit array where the hash value should be set
            int position = Math.abs(hash.compute(key) % bitArray.size());

            // Set the bit at the computed position
            bitArray.set(position);
        }
    }

    /**
     * Checks if a key is in the Bloom filter.
     *
     * @param key The key to be checked
     * @return true if the key might be in the set, false otherwise
     */
    public boolean contains(T key) {
        for (Hash<T> hash : hashFunctions) {
            // Compute the position in the bit array where the hash value should be checked
            int position = Math.abs(hash.compute(key) % bitArray.size());

            // If the bit at the computed position is not set, the key is not in the set
            if (!bitArray.get(position)) {
                return false;
            }
        }

        // If all bits are set, the key might be in the set
        return true;
    }

    /**
     * An inner class representing a hash function.
     */
    private static class Hash<T> {
        // The index of the hash function
        private final int index;

        /**
         * Constructor for the Hash class.
         *
         * @param index The index of the hash function
         */
        Hash(int index) {
            this.index = index;
        }

        /**
         * Computes the hash value for a given key.
         *
         * @param key The key to be hashed
         * @return The hash value
         */
        public int compute(T key) {
            // Hash the key using a simple hash function (ASCII value of the key's string representation)
            return index * asciiString(String.valueOf(key));
        }

        /**
         * Computes the ASCII value of a given string.
         *
         * @param word The string to be hashed
         * @return The ASCII value of the string
         */
        private int asciiString(String word) {
            int sum = 0;
            for (char c : word.toCharArray()) {
                sum += c;
            }
            return sum;
        }
    }

    /**
     * Main method for running the Bloom filter example.
     *
     * @param args Command line arguments (not used in this example)
     */
    public static void main(String[] args) {
        // Create a scanner to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Read the number of hash functions, bit array size, and number of elements to be inserted from the console
        int numberOfHashFunctions = scanner.nextInt();
        int bitArraySize = scanner.nextInt();
        int numberOfElements = scanner.nextInt();

        // Create a new Bloom filter with the given parameters
        Main<String> bloomFilter = new Main<>(numberOfHashFunctions, bitArraySize);

        // Insert elements into the Bloom filter
        for (int i = 0; i < numberOfElements; i++) {
            String element = scanner.next();
            bloomFilter.insert(element);
        }

        // Read a query from the console and check if it might be in the set
        String query = scanner.next();
        boolean result = bloomFilter.contains(query);
        System.out.println("Element might be in the set: " + result);

        // Close the scanner
        scanner.close();
    }
}