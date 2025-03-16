
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int[] h = new int[n];
        boolean[] good = new boolean[n];

        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
            good[i] = true;
        }

        for (int i = 0; i < m; i++) {
            int ai = sc.nextInt() - 1;
            int bi = sc.nextInt() - 1;

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

