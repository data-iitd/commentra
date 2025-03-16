import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to take input.
        int n = scanner.nextInt();  // Take an integer input from the user and store it in the variable `n`.
        
        for (int i = n; i > 0; i--) {  // Iterate from `n` down to 1, decrementing by 1 in each iteration.
            if (n % i == 0) {  // Check if `n` is divisible by `i`.
                n = i;  // Update `n` to `i` if `n` is divisible by `i`.
                System.out.print(i + " ");  // Print the value of `i` followed by a space.
            }
        }
        
        scanner.close();  // Close the scanner to prevent resource leaks.
    }
}

// <END-OF-CODE>
