import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a new scanner for reading input
        Scanner sc = new Scanner(System.in);

        // Read two integers n and k from input
        int n = sc.nextInt();
        int k = sc.nextInt();

        // Initialize a variable to hold the total count
        long total = 0;

        // Calculate the total combinations from k to n+1
        for (int i = k; i <= n + 1; i++) {
            total += combi(n, i); // Add combinations for the current i
            total = total % (pow(10, 9) + 7); // Apply modulo to prevent overflow
        }

        // Print the final total
        System.out.println(total);
    }

    // combi calculates the number of combinations based on the given n and k
    public static long combi(int n, int k) {
        // Calculate the minimum and maximum possible values for combinations
        long min = (long) (k - 1) * k / 2;
        long max = (long) (2 * n - k + 1) * k / 2;
        // Return the count of combinations
        return max - min + 1;
    }

    // Pow calculates the power of a base raised to an exponent
    public static int pow(int base, int exponent) {
        int answer = 1;
        for (int i = 0; i < exponent; i++) {
            answer *= base;
        }
        return answer;
    }
}

// <END-OF-CODE>
