// Package declaration
import java.util.Scanner; // Importing the Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        // Variable declaration and initialization
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Reading the integer input
        String s = scanner.next(); // Reading the string input

        // Variable declaration and initialization for maximum count and current count
        int max = 0;
        int cnt = 0;

        // Iterating through each character in the string 's'
        for (char r : s.toCharArray()) {
            // Checking if the character is 'I'
            if (r == 'I') {
                // Incrementing the current count
                cnt++;
            } else {
                // Decrementing the current count
                cnt--;
            }

            // Updating the maximum count if the current count is greater
            if (cnt > max) {
                max = cnt;
            }
        }

        // Printing the maximum count
        System.out.println(max);
        
        // Closing the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
