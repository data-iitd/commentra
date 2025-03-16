import java.util.Scanner;

public class HashTable {
    private static final int M = 1046527; // Size of the hash table
    private static final int L = 14;       // Maximum length of strings
    private String[] H = new String[M];    // Hash Table

    // Constructor to initialize the hash table
    public HashTable() {
        for (int i = 0; i < M; i++) {
            H[i] = ""; // Initialize with empty strings
        }
    }

    // Convert a character to an integer value
    private int getChar(char ch) {
        switch (ch) {
            case 'A': return 1;
            case 'C': return 2;
            case 'G': return 3;
            case 'T': return 4;
            default: return 0;
        }
    }

    // Convert a string into an integer value
    private long getKey(String str) {
        long sum = 0, p = 1;
        for (int i = 0; i < str.length(); i++) {
            sum += p * getChar(str.charAt(i));
            p *= 5;
        }
        return sum;
    }

    // First hash function
    private int h1(int key) {
        return key % M;
    }

    // Second hash function
    private int h2(int key) {
        return 1 + (key % (M - 1));
    }

    // Search for a string in the hash table
    private boolean find(String str) {
        int i = 0;
        long key = getKey(str);
        while (true) {
            int hash = (h1((int) key) + i * h2((int) key)) % M;
            if (H[hash].equals(str)) {
                return true;
            } else if (H[hash].isEmpty()) {
                return false;
            }
            i++;
        }
    }

    // Insert a string into the hash table
    private boolean insert(String str) {
        int i = 0;
        long key = getKey(str);
        while (true) {
            int hash = (h1((int) key) + i * h2((int) key)) % M;
            if (H[hash].equals(str)) {
                return true;
            } else if (H[hash].isEmpty()) {
                H[hash] = str;
                return false;
            }
            i++;
        }
    }

    // Main function to handle commands
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashTable hashTable = new HashTable();

        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            String command = scanner.next();
            String str = scanner.next();

            if (command.charAt(0) == 'i') {
                hashTable.insert(str);
            } else {
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
