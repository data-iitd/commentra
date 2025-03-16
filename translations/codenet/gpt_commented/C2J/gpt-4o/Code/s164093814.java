import java.util.Scanner;

public class HashTable {
    private static final int M = 1046527; // Size of the hash table
    private static final int L = 14; // Maximum length of strings to be stored in the hash table
    private String[] H = new String[M]; // Hash Table to store strings

    // Constructor to initialize the hash table with empty strings
    public HashTable() {
        for (int i = 0; i < M; i++) {
            H[i] = ""; // Initialize with empty strings
        }
    }

    // Function to convert a character to a corresponding integer value
    private int getChar(char ch) {
        switch (ch) {
            case 'A': return 1; // A maps to 1
            case 'C': return 2; // C maps to 2
            case 'G': return 3; // G maps to 3
            case 'T': return 4; // T maps to 4
            default: return 0; // Return 0 for any other character
        }
    }

    // Convert a string into a unique integer key using a polynomial rolling hash
    private long getKey(String str) {
        long sum = 0, p = 1; // Initialize sum and power
        for (int i = 0; i < str.length(); i++) {
            sum += p * getChar(str.charAt(i)); // Update sum with the character's value
            p *= 5; // Increase power of 5 for the next character
        }
        return sum; // Return the computed key
    }

    // Hash function h1: Computes the primary hash index
    private int h1(int key) {
        return key % M;
    }

    // Hash function h2: Computes the secondary hash index for collision resolution
    private int h2(int key) {
        return 1 + (key % (M - 1));
    }

    // Function to find a string in the hash table
    private boolean find(String str) {
        int i = 0; // Initialize index for probing
        long key = getKey(str); // Get the key for the string
        while (true) {
            // Compute the hash index using double hashing
            int hash = (int) ((h1((int) key) + i * h2((int) key)) % M);
            if (H[hash].equals(str)) return true; // String found
            else if (H[hash].isEmpty()) return false; // Empty slot indicates string not found
            i++; // Increment index for next probe
        }
    }

    // Function to insert a string into the hash table
    private boolean insert(String str) {
        int i = 0; // Initialize index for probing
        long key = getKey(str); // Get the key for the string
        while (true) {
            // Compute the hash index using double hashing
            int hash = (int) ((h1((int) key) + i * h2((int) key)) % M);
            if (H[hash].equals(str)) return true; // String already exists
            else if (H[hash].isEmpty()) { // If the slot is empty
                H[hash] = str; // Insert the string
                return false; // Insertion successful
            }
            i++; // Increment index for next probe
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashTable hashTable = new HashTable();
        int n = scanner.nextInt(); // Read the number of commands
        scanner.nextLine(); // Consume the newline

        // Process each command
        for (int i = 0; i < n; i++) {
            String command = scanner.next();
            String str = scanner.next(); // Read command and string

            // Check if the command is to insert a string
            if (command.charAt(0) == 'i') {
                hashTable.insert(str); // Insert the string into the hash table
            } else {
                // If the command is not insert, check if the string exists
                if (hashTable.find(str)) {
                    System.out.println("yes"); // String found
                } else {
                    System.out.println("no"); // String not found
                }
            }
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
