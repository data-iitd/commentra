import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        BigInteger lcm = BigInteger.ONE;
        for (int i = 0; i < n; i++) {
            lcm = lcm.multiply(BigInteger.valueOf(a[i])).divide(BigInteger.valueOf(gcd(lcm, BigInteger.valueOf(a[i]))));
        }
        BigInteger ans = lcm.multiply(BigInteger.valueOf(n)).mod(BigInteger.valueOf(1000000007));
        System.out.println(ans.mod(BigInteger.valueOf(1000000007)).intValue());
    }
    public static int gcd(BigInteger a, BigInteger b) {
        if (b.equals(BigInteger.ZERO)) {
            return a.intValue();
        }
        return gcd(b, a.mod(b));
    }
}

