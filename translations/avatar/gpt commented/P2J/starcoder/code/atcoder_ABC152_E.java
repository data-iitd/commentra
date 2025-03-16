import java.math.BigInteger;  // Import the BigInteger class from the java.math package
import java.util.Scanner;  // Import the Scanner class from the java.util package

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  // Create a Scanner object to read input from stdin

        int N = sc.nextInt();  // Read the number of elements from user input
        int[] A = new int[N];  // Create an array of integers to store the elements
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();  // Read a list of integers from user input
        }

        BigInteger _lcm = BigInteger.valueOf(1);  // Initialize the variable to store the LCM of the list
        for (int a : A) {
            _lcm = _lcm.multiply(BigInteger.valueOf(a)).divide(BigInteger.valueOf(gcd(_lcm.intValue(), a)));
        }

        BigInteger ans = _lcm.multiply(BigInteger.valueOf(Arrays.stream(A).map(s -> pow(s, MOD - 2, MOD)).sum())).mod(BigInteger.valueOf(MOD));  // Calculate the final answer using the LCM and the modular inverses of the elements in A

        System.out.println(ans.intValue());  // Print the result, ensuring it is within the bounds of MOD
    }

    private static int gcd(int a, int b) {
        // Calculate the greatest common divisor (GCD) of two numbers a and b
        return b == 0? a : gcd(b, a % b);
    }

    private static int pow(int a, int b, int MOD) {
        // Calculate the modular exponentiation of a to the power of b
        int ans = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }
}

