import java.util.Scanner;

public class Main {
    // Utility functions for input and mathematical operations

    // maxInt returns the maximum of two integers
    public static int maxInt(int a, int b) {
        return Math.max(a, b);
    }

    // minInt returns the minimum of two integers
    public static int minInt(int a, int b) {
        return Math.min(a, b);
    }

    // absInt returns the absolute value of an integer
    public static int absInt(int a) {
        return Math.abs(a);
    }

    // sumInts returns the sum of an array of integers
    public static int sumInts(int[] x) {
        int total = 0;
        for (int v : x) {
            total += v;
        }
        return total;
    }

    // gcd calculates the greatest common divisor of two integers
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    // lcm calculates the least common multiple of two integers
    public static int lcm(int x, int y) {
        return x * y / gcd(x, y);
    }

    // Main function
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Read the number of 'S' and 'c'
        int N = sc.nextInt();
        int M = sc.nextInt();
        int tmp = minInt(N, M / 2); // Calculate the minimum of N and half of M
        int ans = 0;
        ans += tmp; // Add the temporary value to the answer
        N -= tmp; // Decrease N by the temporary value
        M -= tmp * 2; // Decrease M by twice the temporary value
        // Output the final answer, which includes the remaining M divided by 4
        System.out.println(ans + M / 4);
        sc.close();
    }
}

// <END-OF-CODE>
