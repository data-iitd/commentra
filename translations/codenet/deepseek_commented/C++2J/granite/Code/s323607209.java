
import java.util.Scanner;  // Import the Scanner class for input/output

public class s323607209{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object
        int n = scanner.nextInt();  // Read the first integer input
        int k = scanner.nextInt();  // Read the second integer input
        long l = 0, r = 0;  // Declare long variables for counting

        if (k % 2 == 0) {  // Check if k is even
            for (int i = 1; i <= n; i++) {  // Iterate from 1 to n
                if (i % k == k / 2)  // Check if i modulo k equals k/2
                    l++;  // Increment l if condition is true
                else if (i % k == 0)  // Check if i modulo k equals 0
                    r++;  // Increment r if condition is true
            }
            System.out.println(l * l * l + r * r * r);  // Print the result of l^3 + r^3
        } else {  // If k is odd
            for (int i = 1; i <= n; i++) {  // Iterate from 1 to n
                if (i % k == 0)  // Check if i modulo k equals 0
                    r++;  // Increment r if condition is true
            }
            System.out.println(r * r * r);  // Print the result of r^3
        }

        scanner.close();  // Close the Scanner object
    }
}

Translate the above Java code to Python and end with comment "