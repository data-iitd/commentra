import java.util.Scanner; // Step 1: Include the necessary import statement.

public class Main { // Step 2: Define the main class.
    public static void main(String[] args) { // Step 3: Define the main method.
        Scanner scanner = new Scanner(System.in); // Step 4: Create a Scanner object for input.
        int N = scanner.nextInt(); // Step 5: Read the first input value.
        int A = scanner.nextInt(); // Step 6: Read the second input value.
        System.out.println(N * N - A); // Step 7: Perform the required calculations and output the result.
        scanner.close(); // Step 8: Close the scanner.
    }
} // <END-OF-CODE>
