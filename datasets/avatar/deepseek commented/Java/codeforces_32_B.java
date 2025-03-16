import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Initialize a Scanner object to read input from the user
        char[] n = in.next().toCharArray(); // Read the input string and convert it to a character array
        boolean s = false; // Initialize a boolean variable to keep track of the state

        // Process each character in the character array
        for (int i = 0; i < n.length; i++) {
            if (n[i] == '.') { // Check if the current character is a dot
                if (s) { // If the state is true
                    System.out.print(1); // Print '1' and reset the state to false
                    s = false;
                } else { // If the state is false
                    System.out.print(0); // Print '0' and set the state to false
                    s = false;
                }
            } else { // If the current character is not a dot
                if (s) { // If the state is true
                    System.out.print(2); // Print '2' and reset the state to false
                    s = false;
                } else { // If the state is false
                    s = true; // Set the state to true
                }
            }
        }
        in.close(); // Close the Scanner object
    }
}
