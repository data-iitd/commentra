import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare and initialize variables
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String s = scanner.next(); // Read a string from the standard input and store it in 's'
        int n = s.length(); // Get the length of the string 's' and store it in 'n'
        int[] v = new int[26]; // Declare and initialize an integer array 'v' of size 26 with zeroes

        // Read each character of the string 's' and increment the corresponding index in array 'v'
        for (int i = 0; i < n; i++) {
            v[s.charAt(i) - 'a']++; // Increment the index 's.charAt(i) - 'a' in array 'v'
        }

        // Initialize answer string to "Yes"
        String ans = "Yes";

        // Check if all elements in array 'v' are even
        for (int i = 0; i < 26; i++) {
            if (v[i] % 2 != 0) { // Check if the current index in array 'v' is odd
                ans = "No"; // If so, set the answer string to "No"
                break; // Exit the loop as soon as an odd number is found
            }
        }

        // Print the answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
