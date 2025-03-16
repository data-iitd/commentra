import java.util.Scanner;

public class Main {
    // Initialize a new scanner to read input from standard input
    private static final Scanner sc = new Scanner(System.in);

    // next reads the next line of input and returns it as a string
    private static String next() {
        return sc.next(); // Return the scanned text
    }

    // nextInt reads the next line of input, converts it to an integer, and returns it
    private static int nextInt() {
        return Integer.parseInt(next()); // Convert the scanned text to an integer
    }

    public static void main(String[] args) {
        // Read two integers, sum them, and compare the result with a third integer
        if (nextInt() + nextInt() >= nextInt()) {
            System.out.println("Yes"); // Print "Yes" if the sum is greater than or equal to the third integer
        } else {
            System.out.println("No"); // Print "No" otherwise
        }
    }
}

// <END-OF-CODE>
