
import java.util.Arrays; // Import the Arrays class from the java.util package
import java.util.Scanner; // Import the Scanner class from the java.util package

public class s954770518{
    public static void main(String[] args) {
        int[] s = new int[11]; // Declare an array to store the input numbers
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the console

        // Step 3: Read input numbers into the array
        for(int i = 0; i < 10; i++) {
            s[i] = scanner.nextInt(); // Read input and store it in the array
        }

        // Step 4: Sort the array
        Arrays.sort(s); // Sort the array in ascending order

        // Step 5: Print the last four numbers of the sorted array
        for(int i = 9; i > 6; i--) {
            System.out.println(s[i]); // Print the last four numbers
        }

        scanner.close(); // Close the Scanner object to release system resources
    }
}
