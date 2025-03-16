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
            a = java.util.Arrays.copyOf(a, n + 1);
            a[n] = a[0];
            int sum1 = 0;
            for (int i = 1; i < n + 1; i++) {
                sum1 += (k - a[i - 1] + a[i]) % n;
            }
            if (sum1 || java.util.Arrays.stream(a).map(x -> (k - a[i - 1] + a[i]) / n).anyMatch(x -> x < 0)) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }
    }
}

