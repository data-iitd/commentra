import java.util.Scanner;

public class Main {
    public static int task4(int A, int B, int n) {
        // The function `task4` is designed to find the value of `X` such that `A * (X ^ n) == B`.
        for (int X = -1000; X <= 1000; X++) {
            // It iterates over the range from -1000 to 1000 for `X`.
            if (A * Math.pow(X, n) == B) {
                // For each value of `X`, it checks if the equation `A * (X ^ n) == B` holds true.
                return X;
                // If a solution is found, it returns the value of `X`.
            }
        }
        return Integer.MIN_VALUE; // Using Integer.MIN_VALUE to indicate "No solution"
        // If no solution is found after the loop, it returns Integer.MIN_VALUE.
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        // The main part of the code takes input for `A`, `B`, and `n`.
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);
        int n = Integer.parseInt(input[2]);
        // Converts them to integers.

        int result = task4(A, B, n);
        if (result == Integer.MIN_VALUE) {
            System.out.println("No solution");
        } else {
            System.out.println(result);
        }
        // Finally, it prints the result returned by the `task4` function.
    }
}
// <END-OF-CODE>
