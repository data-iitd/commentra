import java.util.Scanner;

// Pair class to hold two values of any type
class Pair {
    Object p1, p2;

    Pair(Object p1, Object p2) {
        this.p1 = p1;
        this.p2 = p2;
    }
}

public class Main {
    // Constants for buffer sizes
    private static final int INITIAL_BUF_SIZE = 10000; // Initial buffer size for scanner
    private static final int MAX_BUF_SIZE = 100000000; // Maximum buffer size for scanner

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read two integers N and K from input
        int N = readInt(scanner);
        int K = readInt(scanner);

        // Convert the number N from base 10 to base K
        String s = tenToN(N, K);

        // Print the length of the resulting string
        System.out.println(s.length());
    }

    // Function to convert a number from base 10 to base N
    private static String tenToN(int number, int n) {
        StringBuilder s = new StringBuilder(); // StringBuilder to hold the result
        int tmp = number; // Temporary variable to hold the current number

        do {
            // Prepend the remainder of the division to the result string
            s.insert(0, i2s(tmp % n));
            tmp /= n; // Divide the temporary number by the base
        } while (tmp >= n);

        return s.toString(); // Return the converted string
    }

    // Function to read an integer from input
    private static int readInt(Scanner scanner) {
        return Integer.parseInt(scanner.next()); // Convert the input to an integer
    }

    // Function to convert an integer to a string
    private static String i2s(int i) {
        return Integer.toString(i); // Convert integer to string
    }
}

// <END-OF-CODE>
