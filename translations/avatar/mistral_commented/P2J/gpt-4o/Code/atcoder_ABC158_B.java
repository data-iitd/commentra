import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Setting the modulus value
        final int MOD = 1000000007;

        // Creating a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Reading input values: N, A, and B
        int N = scanner.nextInt();
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        // Initializing the answer variable to 0
        long ans = 0;

        // Calculating the number of repetitions
        int rep = N / (A + B);

        // Adding the number of blocks that can be fully covered by A and B in one repetition
        ans += rep * A;

        // Calculating the remaining number of blocks
        int res = N - rep * (A + B);

        // Adding the number of blocks that can be covered by A in the remaining blocks
        ans += Math.min(res, A);

        // Printing the final answer
        System.out.println(ans);

        // Closing the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
