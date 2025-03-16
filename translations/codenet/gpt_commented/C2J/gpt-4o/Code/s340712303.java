import java.util.Scanner;

public class Main {
    // Declare global variables
    static final int N = 2000;
    static int num1, num2;
    static int[] math = new int[N + 1];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, ans, sum = 0; // Declare variables for input and calculations

        // Initialize the first element of the math array to 1
        math[0] = 1;

        // Read the number of elements for the first set
        num1 = scanner.nextInt();

        // Loop to read each element and update the possible sums
        for (int i = 0; i < num1; i++) {
            a = scanner.nextInt(); // Read the current element
            sum += a; // Update the total sum

            // Update the math array to reflect the new possible sums
            for (int j = sum - a; j >= 0; j--) {
                if (math[j] == 1) {
                    math[j + a] = 1; // Mark the new sum as possible
                }
            }
        }

        // Read the number of queries for possible sums
        num2 = scanner.nextInt();

        // Loop to check if each queried sum is possible
        for (int i = 0; i < num2; i++) {
            ans = scanner.nextInt(); // Read the queried sum
            // Check if the queried sum is possible and print the result
            if (math[ans] == 1) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
