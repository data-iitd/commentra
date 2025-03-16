public class HashTable {
    static final int M = 1046527; // Size of the hash table
    static final int L = 14; // Maximum length of strings to be stored in the hash table
    static String[] H = new String[M]; // Hash Table to store strings

    // Function to convert a character to a corresponding integer value
    static int getChar(char ch) {
        if (ch == 'A') return 1; // A maps to 1
        else if (ch == 'C') return 2; // C maps to 2
        else if (ch == 'G') return 3; // G maps to 3
        else if (ch == 'T') return 4; // T maps to 4
        return 0; // Return 0 for any other character
    }

    // Convert a string into a unique integer key using a polynomial rolling hash
    static long getKey(String str) {
        long sum = 0, p = 1; // Initialize sum and power
        for (int i = 0; i < str.length(); i++) {
            sum += p * (getChar(str.charAt(i))); // Update sum with the character's value
            p *= 5; // Increase power of 5 for the next character
        }
        return sum; // Return the computed key
    }

    // Hash function h1: Computes the primary hash index
    static int h1(int key) {
        return key % M;
    }

    // Hash function h2: Computes the secondary hash index for collision resolution
    static int h2(int key) {
        return 1 + (key % (M - 1));
    }

    // Function to find a string in the hash table
    static boolean find(String str) {
        int i, hash, key;
        key = getKey(str); // Get the key for the string
        i = 0; // Initialize index for probing
        while (true) {
            // Compute the hash index using double hashing
            hash = (h1(key) + i * h2(key)) % M;
            if (H[hash] != null && H[hash].equals(str)) return true; // String found
            else if (H[hash] == null) return false; // Empty slot indicates string not found
            i++; // Increment index for next probe
        }
    }

    // Function to insert a string into the hash table
    static boolean insert(String str) {
        int i, hash, key;
        key = getKey(str); // Get the key for the string
        i = 0; // Initialize index for probing
        while (true) {
            // Compute the hash index using double hashing
            hash = (h1(key) + i * h2(key)) % M;
            if (H[hash] != null && H[hash].equals(str)) return true; // String already exists
            else if (H[hash] == null) { // If the slot is empty
                H[hash] = str; // Insert the string
                return false; // Insertion successful
            }
            i++; // Increment index for next probe
        }
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of commands
        scanner.nextLine(); // Consume newline

        // Initialize the hash table with empty strings
        for (int i = 0; i < M; i++) H[i] = null;

        // Process each command
        for (int i = 0; i < n; i++) {
            String[] command = scanner.nextLine().split(" "); // Read command and string
            String com = command[0];
            String str = command[1];

            // Check if the command is to insert a string
            if (com.equals("i")) {
                insert(str); // Insert the string into the hash table
            } else {
                // If the command is not insert, check if the string exists
                if (find(str)) {
                    System.out.println("yes"); // String found
                } else {
                    System.out.println("no"); // String not found
                }
            }
        }
    }
}
