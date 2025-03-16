import java.util.Scanner;

public class HashTable {
    private static final int M = 1046527; // Define the size of the hash table
    private static final int L = 14; // Define the length of each string in the hash table
    private String[] H = new String[M]; // Declare a 1D array named H as the hash table

    public HashTable() {
        for (int i = 0; i < M; i++) {
            H[i] = ""; // Initialize the hash table with empty strings
        }
    }

    private int getChar(char ch) {
        // A helper function to convert a single character into its corresponding integer value
        switch (ch) {
            case 'A': return 1;
            case 'C': return 2;
            case 'G': return 3;
            case 'T': return 4;
            default: return 0;
        }
    }

    // A function to convert a string into an integer value
    private long getKey(String str) {
        long sum = 0, p = 1;
        for (int i = 0; i < str.length(); i++) {
            sum += p * getChar(str.charAt(i));
            p *= 5;
        }
        return sum;
    }

    // A helper function to calculate the first hash index
    private int h1(int key) {
        return key % M;
    }

    // A helper function to calculate the second hash index
    private int h2(int key) {
        return 1 + (key % (M - 1));
    }

    // A function to check if a string is already present in the hash table
    private boolean find(String str) {
        int i = 0;
        int key = (int) getKey(str); // Calculate the key for the given string
        while (true) {
            int hash = (h1(key) + i * h2(key)) % M;
            if (H[hash].equals(str)) {
                return true; // String found
            } else if (H[hash].isEmpty()) {
                return false; // Empty slot, string not found
            }
            i++;
        }
    }

    // A function to insert a string into the hash table
    private void insert(String str) {
        int i = 0;
        int key = (int) getKey(str); // Calculate the key for the given string
        while (true) {
            int hash = (h1(key) + i * h2(key)) % M;
            if (H[hash].isEmpty()) {
                H[hash] = str; // Copy the string into the empty index
                return;
            }
            i++;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashTable hashTable = new HashTable();
        int n = scanner.nextInt(); // Read the number of operations
        scanner.nextLine(); // Consume the newline

        for (int i = 0; i < n; i++) {
            String command = scanner.next();
            String str = scanner.next(); // Read a command and a string

            if (command.charAt(0) == 'i') {
                // If the command is 'insert', insert the string into the hash table
                hashTable.insert(str);
            } else {
                // If the command is 'find', check if the string is present in the hash table
                if (hashTable.find(str)) {
                    System.out.println("yes");
                } else {
                    System.out.println("no");
                }
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
