import java.util.Scanner;  // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int A, B, flag = 0;  // Declare integer variables A, B, and flag
        A = scanner.nextInt();  // Read input value for A
        B = scanner.nextInt();  // Read input value for B

        // Loop through numbers 1 to 3 to check if the product of A, B, and i is odd
        for (int i = 1; i <= 3; ++i) {
            if ((A * B * i) % 2 == 1) {  // Check if the product is odd
                flag = 1;  // Set flag to 1 if an odd product is found
                break;  // Break out of the loop
            }
        }

        if (flag == 1) {
            System.out.println("Yes");  // Print "Yes" if an odd product was found
        } else {
            System.out.println("No");  // Print "No" if no odd product was found
        }

        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
