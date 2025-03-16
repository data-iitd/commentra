import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] h = new int[n];
        boolean[] good = new boolean[n];
        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt();
            good[i] = true;
        }
        for (int i = 0; i < m; i++) {
            int ai = scanner.nextInt() - 1;
            int bi = scanner.nextInt() - 1;
            if (h[ai] > h[bi]) {
                good[bi] = false;
            } else if (h[ai] < h[bi]) {
                good[ai] = false;
            } else {
                good[ai] = false;
                good[bi] = false;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (good[i]) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
