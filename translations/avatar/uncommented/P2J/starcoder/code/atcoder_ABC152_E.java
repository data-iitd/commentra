import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        BigInteger ans = BigInteger.valueOf(1);
        for (int i = 0; i < n; i++) {
            ans = ans.multiply(BigInteger.valueOf(a[i])).mod(BigInteger.valueOf(1000000007));
        }
        System.out.println(ans);
    }
}
