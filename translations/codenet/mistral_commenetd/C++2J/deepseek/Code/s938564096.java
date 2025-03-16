import java.util.Scanner; // Import the Scanner class to read input from the standard input stream

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the standard input stream

        int r = scanner.nextInt(); // Read an integer `r` from the standard input

        // Calculate and print the square of `r` to the standard output
        System.out.println(r * r);

        scanner.close(); // Close the Scanner object to free up resources
    }
}

