import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String s = scanner.next(); // Read input from the user and store it in the string variable 's'
        int a = -1, z = -1; // Declare two integer variables to store the positions of 'A' and 'Z'

        // The first for loop iterates through the string to find the position of the first occurrence of 'A'
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A') {
                a = i; // Assign the position of 'A' to variable 'a' and break the loop
                break;
            }
        }

        // The second for loop iterates through the string in reverse to find the position of the last occurrence of 'Z'
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == 'Z') {
                z = i; // Assign the position of 'Z' to variable 'z' and break the loop
                break;
            }
        }

        // Calculate the length of the substring between the first 'A' and the last 'Z' and print it
        System.out.println(z - a + 1); // Print the result
        scanner.close(); // Close the scanner
    } // End of main method
} // End of class
// <END-OF-CODE>
