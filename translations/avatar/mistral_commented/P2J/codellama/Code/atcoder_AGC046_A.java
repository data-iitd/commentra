
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        BigInteger gcd_value = BigInteger.valueOf(360).gcd(BigInteger.valueOf(x));
        System.out.println(360 / gcd_value);
    }
}

