import java.util.Scanner;  // Import the Scanner class for input

public class Main {  // Define the main class
    public static void main(String[] args) {  // Main method
        int i;  // Declare an integer variable 'i'
        char[] S = new char[6];  // Declare a character array 'S' of size 6

        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        String input = scanner.next();  // Read a string from the standard input
        for (i = 0; i < input.length() && i < S.length; i++) {  // Iterate through each character in the string
            S[i] = input.charAt(i);  // Store each character in the array 'S'
        }

        for (i = 0; i < S.length - 1; i++) {  // Iterate through the array 'S'
            if (S[i] == 'A' && S[i + 1] == 'C') {  // Check if the current character is 'A' and the next character is 'C'
                System.out.println("Yes");  // If so, print 'Yes' to the standard output
                return;  // And exit the method
            }
        }

        System.out.println("No");  // If no pair of 'AC' is found, print 'No' to the standard output
    }  // End of the main method
}  // End of the main class
// <END-OF-CODE>
