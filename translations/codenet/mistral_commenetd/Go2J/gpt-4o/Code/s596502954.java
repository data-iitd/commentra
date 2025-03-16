import java.util.Scanner;

public class Main {
    // Initialize a new scanner for reading input from stdin
    private static Scanner sc = new Scanner(System.in);

    // Function to read a single word as a string from the input
    private static String next() {
        // Comment: Scans the next token, storing it as a single word
        return sc.next();
    }

    // Function to read an integer from the input
    private static int nextInt() {
        // Comment: Scans the next token as a single word and converts it to an integer
        return Integer.parseInt(next());
    }

    // Function to read a float from the input
    private static double nextFloat() {
        // Comment: Parses the next token as a float value
        return Double.parseDouble(next());
    }

    // Function to read n integers from the input and return as an array
    private static int[] nextInts(int n) {
        int[] array = new int[n];
        // Comment: Creates an array of size n and initializes it with zero values
        for (int i = 0; i < n; i++) {
            array[i] = nextInt();
            // Comment: Reads the next integer from the input and assigns it to the current index of the array
        }
        return array;
    }

    // Main function
    public static void main(String[] args) {
        // Read the first three integers from the input
        int a = nextInt();
        int b = nextInt();
        int c = nextInt();

        // Check if the condition is true
        if (a + b >= c) {
            // If true, print "Yes" to the output
            System.out.println("Yes");
        } else {
            // If false, print "No" to the output
            System.out.println("No");
        }
    }
}

// <END-OF-CODE>
