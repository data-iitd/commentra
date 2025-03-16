import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        int ans = 0;
        int aPrev = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > i || a[i] > aPrev + 1) {
                System.out.println(-1);
                return;
            }
            if (a[i] == aPrev + 1) {
                ans++;
            } else {
                ans += a[i];
            }
            aPrev = a[i];
        }
        System.out.println(ans);
    }
}
