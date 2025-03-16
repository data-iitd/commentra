
import java.util.*; // Import the necessary libraries
import java.io.*; // Import the necessary libraries

public class s509329039{ // Define the main class
    public static void main(String[] args) throws IOException { // Define the main method
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Create a BufferedReader object to read input from the user
        String[] input = br.readLine().split(" "); // Read the number of digits and the number of constraints from the user
        int n = Integer.parseInt(input[0]); // Convert the number of digits to an integer
        int m = Integer.parseInt(input[1]); // Convert the number of constraints to an integer
        int[] s = new int[m]; // Create an array to store the positions of constraints
        int[] c = new int[m]; // Create an array to store the values of constraints
        for (int i = 0; i < m; i++) { // Read the positions and values of constraints from the user
            input = br.readLine().split(" ");
            s[i] = Integer.parseInt(input[0]) - 1; // Convert the position of the constraint to 0-based index
            c[i] = Integer.parseInt(input[1]); // Convert the value of the constraint to an integer
        }
        for (int i = 0; i < 1000; i++) { // Iterate through all possible numbers
            String st = String.valueOf(i); // Convert the current number to a string
            if (st.length()!= n) { // Check if the length of the string is equal to the number of digits
                continue; // If not, continue to the next iteration
            }
            //System.out.println(st); // Print the current number (for debugging purposes)
            boolean f = true; // Initialize a flag to true
            for (int j = 0; j < m; j++) { // Check if all constraints are met
                if (st.charAt(s[j]) - '0' == c[j]) { // Check if the digit at the constraint position matches the constraint value
                    // Do nothing (continue to the next iteration)
                } else {
                    f = false; // If any constraint is not met, set the flag to false
                }
            }
            if (f) { // Check if all constraints are met
                System.out.println(i); // Print the valid number
                return; // Exit the program
            }
        }
        System.out.println(-1); // If no valid number is found, print -1
    }
}
