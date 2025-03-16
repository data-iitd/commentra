import java.util.Scanner;

public class Main {
    // Method to calculate the maximum of three integers
    public static int max(int a, int b, int c) {
        return Math.max(a, Math.max(b, c));
    }

    // Method to calculate the power of a number
    public static int pow(int x, int y) {
        int res = 1; // Initialize the result to 1
        for (int i = 0; i < y; i++) { // Iterate y times
            res *= x; // Multiply the result by x
        }
        return res; // Return the result
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize a new Scanner for input

        // Read input values
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();

        // Find the maximum value among A, B, and C
        int ma = max(A, B, C);

        // Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
        int rest = 0;
        if (ma == A) {
            rest += B + C;
        } else if (ma == B) {
            rest += A + C;
        } else {
            rest += A + B;
        }

        // Calculate the final answer
        int answer = pow(ma, K) + rest;

        // Print the answer to the output
        System.out.println(answer);
    }
}
// <END-OF-CODE>
