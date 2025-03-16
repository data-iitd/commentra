import java.util.Scanner;  // Step 1: Import the Scanner class for input.

public class Main {  // Step 2: Define the main class.
    public static void main(String[] args) {  // Step 3: Define the main method.
        int A, B, C, D, E, max;  // Step 4: Declare integer variables A, B, C, D, E, and max.

        Scanner scanner = new Scanner(System.in);  // Step 5: Create a Scanner object for input.
        A = scanner.nextInt();  // Step 6: Read the first integer A from the user.
        B = scanner.nextInt();  // Step 7: Read the second integer B from the user.

        C = A + B;  // Step 8: Calculate the sum of A and B, store it in C.
        D = A - B;  // Step 9: Calculate the difference between A and B, store it in D.
        E = A * B;  // Step 10: Calculate the product of A and B, store it in E.

        max = C;  // Step 11: Initialize max with the value of C.

        if (max < D) {  // Step 12: Compare max with D and update max if D is greater.
            max = D;
        }
        if (max < E) {  // Step 13: Compare max with E and update max if E is greater.
            max = E;
        }

        System.out.println(max);  // Step 14: Print the maximum value.
        scanner.close();  // Step 15: Close the scanner to prevent resource leaks.
    }  // End of main method.
}  // End of class.
