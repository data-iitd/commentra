
import java.util.Scanner;

public class s105551633{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        int min = Long.toString(n).length();
        for (long i = 1; i * i <= n; i++) {
            if (n % i!= 0) {
                continue;
            }
            long a = i;
            long b = n / i;
            int digitA = Long.toString(a).length();
            int digitB = Long.toString(b).length();
            min = Math.min(min, Math.max(digitA, digitB));
        }
        System.out.println(min);
    }
}

