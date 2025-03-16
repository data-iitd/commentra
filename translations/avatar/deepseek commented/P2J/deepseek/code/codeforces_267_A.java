import java.util.Scanner;

public class SubtractionGame {
    public static int subtract(int a, int b) {
        // Check if a is greater than b
        if (a > b) {
            int total = 0;  // Initialize the total count of subtractions
            // Loop to subtract b from a until one of them becomes zero
            while (a > 0 && b > 0) {
                total += a / b;  // Count how many times b can be subtracted from a
                a = a % b;  // Update a to the remainder of a divided by b
                if (a > 0) {
                    total += b / a;  // Count how many times a can be subtracted from b
                    b = b % a;  // Update b to the remainder of b divided by a
                }
            }
            return total;  // Return the total count of subtractions
        }
        
        // If a is less than b, perform similar operations but subtract a from b
        if (a < b) {
            int total = 0;  // Initialize the total count of subtractions
            while (a > 0 && b > 0) {
                total += b / a;  // Count how many times a can be subtracted from b
                b = b % a;  // Update b to the remainder of b divided by a
                if (b > 0) {
                    total += a / b;  // Count how many times b can be subtracted from a
                    a = a % b;  // Update a to the remainder of a divided by b
                }
            }
            return total;  // Return the total count of subtractions
        }
        
        // If a and b are equal, return 1
        if (a == b) {
            return 1;
        }
        return 0; // Default return statement
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Read the number of pairs of integers
        int[] lst = new int[n];  // Initialize an array to store the results

        // Read n pairs of integers and compute the result using the subtract function
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            lst[i] = subtract(a, b);
        }

        // Print each element in the array
        for (int i : lst) {
            System.out.println(i);
        }
    }
}
