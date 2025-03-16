import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    // Function to calculate the greatest common divisor (GCD)
    public static BigInteger gcd(BigInteger a, BigInteger b) {
        return a.gcd(b);
    }

    // Function to calculate the least common multiple (LCM)
    public static BigInteger lcm(BigInteger a, BigInteger b) {
        return a.multiply(b).divide(gcd(a, b));
    }

    public static void main(String[] args) {
        final BigInteger MOD = BigInteger.valueOf(10).pow(9).add(BigInteger.valueOf(7));
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        BigInteger[] A = new BigInteger[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextBigInteger();
        }

        BigInteger _lcm = BigInteger.ONE;
        for (BigInteger a : A) {
            _lcm = lcm(_lcm, a);
        }

        BigInteger ans = _lcm.multiply(sumModularInverses(A, MOD)).mod(MOD);
        System.out.println(ans.mod(MOD));
    }

    // Function to calculate the sum of modular inverses
    public static BigInteger sumModularInverses(BigInteger[] A, BigInteger MOD) {
        BigInteger sum = BigInteger.ZERO;
        for (BigInteger s : A) {
            sum = sum.add(s.modPow(MOD.subtract(BigInteger.valueOf(2)), MOD));
        }
        return sum;
    }
}
