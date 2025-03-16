
import java.util.Scanner;

public class codeforces_267_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Read an integer input 'n' which represents the number of pairs
        int[] lst = new int[n];  // Initialize an array to store results

        // Loop to read 'n' pairs of integers and call the substract function
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            lst[i] = substract(a, b);  // Call the substract function and store the result
        }

        // Loop to print each result stored in the array
        for (int i = 0; i < n; i++) {
            System.out.println(lst[i]);
        }
    }

    // Function to subtract two integers
    public static int substract(int a, int b) {
        // Check if 'a' is greater than 'b'
        if (a > b) {
            int total = 0;  // Initialize total to accumulate results
            // Loop until either 'a' or 'b' becomes zero
            while (a > 0 && b > 0) {
                // Add the integer division of 'a' by 'b' to total
                total += a / b;
                // Update 'a' to the remainder of 'a' divided by 'b'
                a = a % b;
                // If 'a' is still greater than zero, calculate further
                if (a > 0) {
                    // Add the integer division of 'b' by 'a' to total
                    total += b / a;
                    // Update 'b' to the remainder of 'b' divided by 'a'
                    b = b % a;
                }
            }
            return total;  // Return the accumulated total
        }

        // Check if 'a' is less than 'b'
        if (a < b) {
            int total = 0;  // Initialize total to accumulate results
            // Loop until either 'a' or 'b' becomes zero
            while (a > 0 && b > 0) {
                // Add the integer division of 'b' by 'a' to total
                total += b / a;
                // Update 'b' to the remainder of 'b' divided by 'a'
                b = b % a;
                // If 'b' is still greater than zero, calculate further
                if (b > 0) {
                    // Add the integer division of 'a' by 'b' to total
                    total += a / b;
                    // Update 'a' to the remainder of 'a' divided by 'b'
                    a = a % b;
                }
            }
            return total;  // Return the accumulated total
        }

        // If 'a' is equal to 'b', return 1
        if (a == b) {
            return 1;
        }
        return 0;
    }
}

Translate the above Java code to C++ and end with comment "