import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next(); // Read a string from the standard input

        boolean flag = false; // Initialize a boolean flag to false

        for (int i = 0; i < s.length(); i++) { // Iterate through each character in the string 's'
            if (i % 2 == 0) { // Check if the current index 'i' is even
                char c = s.charAt(i); // Get the character at the even index
                if (c != 'R' && c != 'U' && c != 'D') { // Check if the character is not 'R', 'U', or 'D'
                    flag = true; // Set the flag to true
                    break; // Exit the loop
                }
            } else { // If the current index 'i' is odd
                char c = s.charAt(i); // Get the character at the odd index
                if (c != 'L' && c != 'U' && c != 'D') { // Check if the character is not 'L', 'U', or 'D'
                    flag = true; // Set the flag to true
                    break; // Exit the loop
                }
            }
        }

        if (flag) { // If the flag is true, indicating an invalid character was found
            System.out.println("No"); // Output "No" to the standard output
        } else { // If no invalid character was found
            System.out.println("Yes"); // Output "Yes" to the standard output
        }
    }
}
