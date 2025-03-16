import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of elements
        int n = scanner.nextInt();
        
        // Read a list of integers from input
        int[] number = new int[n];
        for (int i = 0; i < n; i++) {
            number[i] = scanner.nextInt();
        }
        
        // Initialize two variables to hold the sums of the two halves
        int h1 = 0;  // Sum of the first half
        int h2 = 0;  // Sum of the second half
        boolean isValid = true; // Flag to check if any number is not 4 or 7
        
        // Iterate through the list of numbers
        for (int i = 0; i < n; i++) {
            // Check if the current number is neither 4 nor 7
            if (number[i] != 4 && number[i] != 7) {
                System.out.println("NO");  // Print "NO" if an invalid number is found
                isValid = false;           // Set the flag to indicate an invalid number was found
                break;                     // Exit the loop since we found an invalid number
            }
            
            // Sum the first half of the numbers
            if (i < n / 2) {
                h1 += number[i];
            } else {
                // Sum the second half of the numbers
                h2 += number[i];
            }
        }
        
        // After checking all numbers, determine if the sums of both halves are equal
        if (isValid) {  // Proceed only if no invalid numbers were found
            if (h1 == h2) {
                System.out.println("YES");  // Print "YES" if the sums are equal
            } else {
                System.out.println("NO");   // Print "NO" if the sums are not equal
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
