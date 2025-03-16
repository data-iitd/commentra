import java.math.BigInteger;  // Importing the BigInteger class from the java.math package

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  // Creating a Scanner object for reading input

        int N = sc.nextInt();  // Read the number of elements in the list A
        int[] A = new int[N];  // Create an array A to store the elements of the list A
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();  // Read the next element of the list A
        }

        BigInteger _lcm = BigInteger.valueOf(1);  // Initialize _lcm to 1
        for (int a : A) {
            _lcm = _lcm.multiply(BigInteger.valueOf(a)).divide(BigInteger.valueOf(gcd(_lcm.intValue(), a)));  // Update _lcm to be the LCM of _lcm and the current element
        }

        BigInteger ans = _lcm.multiply(BigInteger.valueOf(Arrays.stream(A).map(s -> pow(s, MOD - 2, MOD)).sum())).mod(BigInteger.valueOf(MOD));  // Calculate ans as _lcm multiplied by the sum of modular inverses of each element in A modulo MOD

        System.out.println(ans.intValue());  // Print the result, ensuring it is within the modulo range
    }

    private static int gcd(int a, int b) {  // Define a function to calculate the greatest common divisor (GCD) of two numbers
        return b == 0? a : gcd(b, a % b);
    }

    private static int pow(int a, int b, int mod) {  // Define a function to calculate the modular exponentiation of a to the power of b modulo mod
        int ans = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    }
}

