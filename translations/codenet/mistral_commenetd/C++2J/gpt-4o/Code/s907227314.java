import java.util.Scanner;

public class Main { // The main class of the program
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        String s = scanner.next(); // Read a string input from the standard input stream and store it in the s variable

        int a = -1, z = -1; // Declare two integer variables named a and z and initialize them to -1

        for (int i = 0; i < s.length(); i++) { // This for loop iterates through each character in the string s
            if (s.charAt(i) == 'A') { // Check if the current character is 'A'
                a = i; // If it is, assign the index of the character to the variable a
                break; // Exit the loop once 'A' is found
            }
        }

        for (int i = s.length() - 1; i >= 0; i--) { // This for loop iterates through the string in reverse order
            if (s.charAt(i) == 'Z') { // Check if the current character is 'Z'
                z = i; // If it is, assign the index of the character to the variable z
                break; // Exit the loop once 'Z' is found
            }
        }

        System.out.println(z - a + 1); // Output the difference between the indices of 'Z' and 'A' plus one

        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
