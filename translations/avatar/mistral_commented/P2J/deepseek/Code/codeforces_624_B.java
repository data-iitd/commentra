import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        Arrays.sort(a);
        long ans = 0;
        long pre = Integer.MAX_VALUE;
        for (int j = n - 1; j >= 0; j--) {
            ans += Math.max(0, Math.min(pre - 1, a[j]));
            pre = Math.min(pre - 1, a[j]);
        }
        System.out.println(ans);
    }
}

