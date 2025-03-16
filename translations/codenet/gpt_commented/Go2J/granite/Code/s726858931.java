
import java.util.Scanner;

public class s726858931{
    public static void main(String[] args) {
        // Initialize the scanner to read input from standard input
        Scanner sc = new Scanner(System.in);

        // Read the input string
        String s = sc.next();

        // Start checking for the first missing lowercase letter from 'a'
        char c = 'a';

        // Loop through all lowercase letters from 'a' to 'z'
        for (int j = 0; j < 26; j++) {
            boolean found = false; // Flag to check if the current letter is found in the input string
            // Check if the current letter exists in the input string
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == c) {
                    found = true; // Set the flag to true if the letter is found
                    break;
                }
            }
            // If the letter was not found, print it and exit
            if (!found) {
                System.out.println(c);
                return;
            }
            c++; // Move to the next letter
        }

        // If all letters from 'a' to 'z' are found, print "None"
        System.out.println("None");
    }
}

// ---- readfunc

// nextInt reads the next integer from the input
int nextInt() {
    return sc.nextInt();
}

// nextStr reads the next string from the input
String nextStr() {
    return sc.next();
}

// ---- main

public static void main(String[] args) {
    new s726858931().run();
}

void run() {
    // Initialize the scanner with a specific buffer size
    scanInit();

    // Read the input string
    String s = nextStr();

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        boolean found = false; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == c) {
                found = true; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (!found) {
            System.out.println(c);
            return;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    System.out.println("None");
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
void scanInit() {
    final int cap = 1000 * 1024; // Define the buffer capacity
    final char[] buf = new char[cap]; // Create a buffer of the specified capacity
    sc = new Scanner(buf); // Set the scanner's buffer
    sc.useDelimiter("\\s"); // Split the input by words
}

// nextInt reads the next integer from the input
int nextInt() {
    return sc.nextInt();
}

// nextStr reads the next string from the input
String nextStr() {
    return sc.next();
}

// ---- main

public static void main(String[] args) {
    new s726858931().run();
}

void run() {
    // Initialize the scanner with a specific buffer size
    scanInit();

    // Read the input string
    String s = nextStr();

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        boolean found = false; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == c) {
                found = true; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (!found) {
            System.out.println(c);
            return;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    System.out.println("None");
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
void scanInit() {
    final int cap = 1000 * 1024; // Define the buffer capacity
    final char[] buf = new char[cap]; // Create a buffer of the specified capacity
    sc = new Scanner(buf); // Set the scanner's buffer
    sc.useDelimiter("\\s"); // Split the input by words
}

// nextInt reads the next integer from the input
int nextInt() {
    return sc.nextInt();
}

// nextStr reads the next string from the input
String nextStr() {
    return sc.next();
}

// ---- main

public static void main(String[] args) {
    new s726858931().run();
}

void run() {
    // Initialize the scanner with a specific buffer size
    scanInit();

    // Read the input string
    String s = nextStr();

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        boolean found = false; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == c) {
                found = true; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (!found) {
            System.out.println(c);
            return;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    System.out.println("None");
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
void scanInit() {
    final int cap = 1000 * 1024; // Define the buffer capacity
    final char[] buf = new char[cap]; // Create a buffer of the specified capacity
    sc = new Scanner(buf); // Set the scanner's buffer
    sc.useDelimiter("\\s"); // Split the input by words
}

// nextInt reads the next integer from the input
int nextInt() {
    return sc.nextInt();
}

// nextStr reads the next string from the input
String nextStr() {
    return sc.next();
}

// ---- main

public static void main(String[] args) {
    new s726858931().run();
}

void run() {
    // Initialize the scanner with a specific buffer size
    scanInit();

    // Read the input string
    String s = nextStr();

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        boolean found = false; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == c) {
                found = true; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (!found) {
            System.out.println(c);
            return;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    System.out.println("None");
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
void scanInit() {
    final int cap = 1000 * 1024; // Define the buffer capacity
    final char[] buf = new char[cap]; // Create a buffer of the specified capacity
    sc = new Scanner(buf); // Set the scanner's buffer
    sc.useDelimiter("\\s"); // Split the input by words
}

// nextInt reads the next integer from the input
int nextInt() {
    return sc.nextInt();
}

// nextStr reads the next string from the input
String nextStr() {
    return sc.next();
}

// ---- main

public static void main(String[] args) {
    new s726858931().run();
}

void run() {
    // Initialize the scanner with a specific buffer size
    scanInit();

    // Read the input string
    String s = nextStr();

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        boolean found = false; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == c) {
                found = true; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (!found) {
            System.out.println(c);
            return;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    System.out.println("None");
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
void scanInit() {
    final int cap = 1000 * 1024; // Define the buffer capacity
    final char[] buf = new char[cap]; // Create a buffer of the specified capacity
    sc = new Scanner(buf); // Set the scanner's buffer
    sc.useDelimiter("\\s"); // Split the input by words
}

// nextInt reads the next integer from the input
int nextInt() {
    return sc.nextInt();
}

// nextStr reads the next string from the input
String nextStr() {
    return sc.next();
}

// ---- main

public static void main(String[] args) {
    new s726858931().run();
}

void run() {
    // Initialize the scanner with a specific buffer size
    scanInit();

    // Read the input string
    String s = nextStr();

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        boolean found = false; // Flag