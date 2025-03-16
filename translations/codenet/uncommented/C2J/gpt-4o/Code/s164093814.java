import java.util.Scanner;

public class HashTable {
    private static final int M = 1046527; // your task
    private static final int L = 14;
    private String[] H = new String[M]; // Hash Table

    public HashTable() {
        for (int i = 0; i < M; i++) {
            H[i] = ""; // Initialize the hash table
        }
    }

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
        long sum = 0;
        long p = 1;
        for (int i = 0; i < str.length(); i++) {
            sum += p * getChar(str.charAt(i));
            p *= 5;
        }
        return sum;
    }

    private int h1(int key) {
        return key % M;
    }

    private int h2(int key) {
        return 1 + (key % (M - 1));
    }

    private boolean find(String str) {
        int i = 0;
        int key = (int) getKey(str);
        while (true) {
            int hash = (h1(key) + i * h2(key)) % M;
            if (H[hash].equals(str)) {
                return true;
            } else if (H[hash].isEmpty()) {
                return false;
            }
            i++;
        }
    }

    private boolean insert(String str) {
        int i = 0;
        int key = (int) getKey(str);
        while (true) {
            int hash = (h1(key) + i * h2(key)) % M;
            if (H[hash].equals(str)) {
                return true;
            } else if (H[hash].isEmpty()) {
                H[hash] = str;
                return false;
            }
            i++;
        }
    }

    public static void main(String[] args) {
        HashTable hashTable = new HashTable();
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

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
