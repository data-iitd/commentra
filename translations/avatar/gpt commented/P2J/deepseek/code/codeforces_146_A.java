import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of elements
        int n = scanner.nextInt();
        
        // Read a string input and convert it to a character array
        String input = scanner.next();
        char[] number = input.toCharArray();
        
        // Initialize two variables to hold the sums of the two halves
        int h1 = 0;  // Sum of the first half
        int h2 = 0;  // Sum of the second half
        boolean x = false;  // Flag to check if any number is not 4 or 7
        
        // Iterate through the character array
        for (int i = 0; i < n; i++) {
            // Check if the current character is neither '4' nor '7'
            if (number[i] != '4' && number[i] != '7') {
                System.out.println("NO");  // Print "NO" if an invalid character is found
                x = true;  // Set the flag to indicate an invalid character was found
                break;  // Exit the loop since we found an invalid character
            }
            
            // Sum the first half of the characters
            if (i < n / 2) {
                h1 += number[i] - '0';  // Convert char to int and add to h1
            } else {
                // Sum the second half of the characters
                h2 += number[i] - '0';  // Convert char to int and add to h2
            }
        }
        
        // After checking all characters, determine if the sums of both halves are equal
        if (!x) {  // Proceed only if no invalid characters were found
            if (h1 == h2) {
                System.out.println("YES");  // Print "YES" if the sums are equal
            } else {
                System.out.println("NO");  // Print "NO" if the sums are not equal
            }
        }
        
        scanner.close();
    }
}
