
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        if (sum % (n * (n + 1) / 2)) {
            System.out.println("NO");
        } else {
            int k = sum / (n * (n + 1) / 2);
            a[n] = a[0];
            int[] b = new int[n + 1];
            for (int i = 0; i < n + 1; i++) {
                b[i] = (k - a[i] + a[i + 1]) % n;
            }
            int count = 0;
            for (int i = 0; i < n + 1; i++) {
                if (b[i] < 0) {
                    count++;
                }
            }
            if (count == n) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}

