import java.util.Scanner;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        BigInteger gcd = Arrays.stream(a).mapToObj(BigInteger::valueOf).reduce(BigInteger::gcd).get();
        System.out.println(gcd);
    }
}

