import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer n from the standard input
        int n = scanner.nextInt();
        
        // Iterate from 1 to n (inclusive)
        for (int i = 1; i <= n; i++) {
            int a = i;
            
            // Check if the current number i is divisible by 3
            if (a % 3 == 0) {
                System.out.print(" " + i);
            } else {
                // Check each digit of i to see if it contains the digit 3
                while (a > 0) {
                    if (a % 10 == 3) {
                        System.out.print(" " + i);
                        break; // Exit the loop if we found the digit 3
                    }
                    a = a / 10;
                }
            }
        }
        
        // Print a newline character
        System.out.println();
        
        scanner.close();
    }
}

// <END-OF-CODE>
