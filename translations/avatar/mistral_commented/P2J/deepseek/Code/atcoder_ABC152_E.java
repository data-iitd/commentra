import java.util.Scanner;

public class Main {
    // Importing the java.util.Scanner class for input.
    // Importing the java.math.BigInteger class for handling large integers.
    // Importing the java.util.Arrays class for sorting the array.

    // Defining a method gcd to calculate the greatest common divisor of two numbers a and b.
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Defining a method lcm to calculate the least common multiple of two numbers a and b.
    public static int lcm(int a, int b) {
        // Calculate the greatest common divisor of a and b using the gcd method.
        int g = gcd(a, b);
        // Return the product of a and b divided by their greatest common divisor.
        return a * b / g;
    }

    // Setting the value of MOD to 10^9 + 7.
    public static final int MOD = (int) (1e9 + 7);

    public static void main(String[] args) {
        // Reading the input N and storing the list A of N integers.
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Initializing the variable _lcm to 1.
        int _lcm = 1;

        // Iterating through each number a in the list A and updating the value of _lcm using the lcm method.
        for (int a : A) {
            // Update the value of _lcm using the lcm method.
            _lcm = lcm(_lcm, a);
        }

        // Calculating the answer ans using the formula _lcm * sum ( [ pow ( s , MOD - 2 , MOD ) for s in A ] ) % MOD.
        long ans = 0;
        long sum = 0;
        for (int s : A) {
            sum += pow(s, MOD - 2, MOD);
        }
        ans = _lcm * sum % MOD;

        // Printing the final answer.
        System.out.println(ans % MOD);
    }

    // Defining a method pow to calculate x raised to the power of y modulo z.
    public static long pow(long x, long y, long z) {
        long res = 1;
        x = x % z;
        while (y > 0) {
            if (y % 2 == 1) {
                res = (res * x) % z;
            }
            y = y >> 1;
            x = (x * x) % z;
        }
        return res;
    }
}
