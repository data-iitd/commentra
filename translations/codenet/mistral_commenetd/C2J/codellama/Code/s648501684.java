
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextLong();
        long q = sc.nextLong();
        long[] arr = new long[n];
        for (long i = 0; i <= n; i++) {
            arr[i] = 0;
        }
        for (long i = 0; i < q; i++) {
            long temp = sc.nextLong();
            arr[temp] += 1;
        }
        for (long i = 1; i <= n; i++) {
            if (arr[i] > (q - k)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}

