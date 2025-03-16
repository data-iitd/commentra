import java.util.Scanner;

public class Combinations {
    
    // Function to calculate combinations C(N, K)
    public static long combi(int N, int K) {
        long a = 1;
        // Calculate the numerator of the combination formula
        for (int i = 0; i < K; i++) {
            a *= (N - i);
        }
        // Calculate the denominator of the combination formula
        for (int j = 0; j < K; j++) {
            a /= (j + 1);
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers N and P from input
        int N = scanner.nextInt();
        int P = scanner.nextInt();
        
        // Initialize the answer variable
        long ans = 0;

        // Read a list of integers from input
        int[] lis = new int[N];
        for (int i = 0; i < N; i++) {
            lis[i] = scanner.nextInt();
        }

        // Count the number of 1s (odd numbers) and 0s (even numbers) in the list
        int one = 0;
        int zero = 0;

        for (int a : lis) {
            if (a % 2 == 0) {
                zero++;
            } else {
                one++;
            }
        }

        // Initialize variables to count patterns
        long pattern_a = 0;
        long pattern_b = 0;

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
        System.out.println(pattern_a * pattern_b);
        
        scanner.close();
    }
}

// <END-OF-CODE>
