import java.util.Scanner;

public class Main {
    // Function to calculate combinations C(N, K)
    public static double combi(int N, int K) {
        double a = 1;
        // Calculate the numerator of the combination formula
        for (int i = 0; i < K; i++) {
            a *= N - i;
        }
        // Calculate the denominator of the combination formula
        for (int j = 0; j < K; j++) {
            a /= j + 1;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read two integers N and P from input
        int N = scanner.nextInt();
        int P = scanner.nextInt();

        // Read a list of integers from input
        int[] lis = new int[N];
        for (int i = 0; i < N; i++) {
            lis[i] = scanner.nextInt();
        }

        // Create a list to hold the parity (0 or 1) of each number
        int[] ls = new int[N];
        for (int i = 0; i < N; i++) {
            ls[i] = lis[i] % 2;
        }

        // Count the number of 1s (odd numbers) and 0s (even numbers) in the list
        int one = 0;
        int zero = 0;
        for (int num : ls) {
            if (num == 1) {
                one++;
            } else {
                zero++;
            }
        }

        // Initialize variables to count patterns
        double pattern_a = 0;
        double pattern_b = 0;

        // Calculate the total number of patterns for the even numbers
        for (int j = 0; j <= zero; j++) {
            pattern_b += combi(zero, j);
        }

        // Initialize a variable to track the number of odd numbers used
        int time = 0;

        // Loop through all possible counts of odd numbers used
        while (time <= one) {
            // Check if the current count of odd numbers is congruent to P modulo 2
            if (time % 2 == P) {
                // If it is, add the number of combinations to pattern_a
                pattern_a += combi(one, time);
            }
            time++;
        }

        // Print the final result, which is the product of pattern_a and pattern_b
        System.out.println((long) (pattern_a * pattern_b));
    }
}
