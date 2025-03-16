
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
        if (sum % (n * (n + 1) / 2) != 0) {
            System.out.println("NO");
        } else {
            int k = sum / (n * (n + 1) / 2);
            a = append(a, a[0]);
            for (int i = 1; i < n; i++) {
                if ((k - a[i] + a[i - 1]) % n != 0 || (k - a[i] + a[i - 1]) / n < 0) {
                    System.out.println("NO");
                    return;
                }
            }
            System.out.println("YES");
        }
    }

    public static int[] append(int[] a, int x) {
        int[] b = new int[a.length + 1];
        for (int i = 0; i < a.length; i++) {
            b[i] = a[i];
        }
        b[a.length] = x;
        return b;
    }
}

