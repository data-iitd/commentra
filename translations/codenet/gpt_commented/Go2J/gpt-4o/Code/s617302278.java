import java.util.Scanner;

public class Main {
    // Initialize a new scanner for reading input from standard input
    private static final Scanner sc = new Scanner(System.in);

    // Method to read a line of text from stdin and return it as a string
    private static String nextLine() {
        return sc.nextLine();
    }

    // Method to read a line of integers separated by spaces from stdin
    // and return them as an array of integers
    private static int[] nextIntsLine() {
        String[] tmp = nextLine().split(" "); // Split the line into individual string components
        int[] integers = new int[tmp.length]; // Create an array to hold the integers
        for (int i = 0; i < tmp.length; i++) {
            integers[i] = Integer.parseInt(tmp[i]); // Convert each string to an integer
        }
        return integers; // Return the array of integers
    }

    // Main method where the program execution begins
    public static void main(String[] args) {
        int[] tmp = nextIntsLine(); // Read a line of integers
        int x = tmp[0]; // Store the first integer in variable x
        int i = 1; // Initialize counter
        int sum = 0; // Initialize sum
        while (true) {
            sum += i; // Incrementally add to sum
            if (sum >= x) { // Check if sum has reached or exceeded x
                break; // Exit the loop if condition is met
            }
            i++; // Increment counter
        }
        System.out.println(i); // Print the result
    }
}

// <END-OF-CODE>
