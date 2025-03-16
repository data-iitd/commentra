import java.util.Scanner; // Import Scanner class for input
import java.util.ArrayList; // Import ArrayList class for dynamic array

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read the number of digits
        int m = scanner.nextInt(); // Read the number of constraints
        int[] s = new int[m]; // Declare an array to store the positions of constraints
        int[] c = new int[m]; // Declare an array to store the values of constraints

        for (int i = 0; i < m; i++) {
            s[i] = scanner.nextInt() - 1; // Read the position and convert to 0-based index
            c[i] = scanner.nextInt(); // Read the value of the constraint
        }

        for (int i = 0; i < 1000; i++) {
            String st = Integer.toString(i); // Convert the current number to a string
            if (st.length() != n) { // Check if the length of the string is equal to the number of digits
                continue; // If not, continue to the next iteration
            }
            boolean valid = true; // Initialize a flag to true
            for (int j = 0; j < m; j++) {
                if (st.charAt(s[j]) == (char) (c[j] + '0')) { // Check if the digit at the constraint position matches the constraint value
                    // Do nothing (continue to the next iteration)
                } else {
                    valid = false; // If any constraint is not met, set the flag to false
                }
            }
            if (valid) { // Check if all constraints are met
                System.out.println(i); // Print the valid number
                return; // Exit the program
            }
        }
        System.out.println(-1); // If no valid number is found, print -1
    }
}
// <END-OF-CODE>
