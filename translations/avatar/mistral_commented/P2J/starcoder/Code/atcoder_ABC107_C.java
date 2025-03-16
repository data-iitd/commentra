
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();

        int[] lst = new int[N];
        int[] lst_p = new int[N];
        int[] lst_m = new int[N];

        for (int i = 0; i < N; i++) {
            lst[i] = sc.nextInt();
        }

        int p = 0, m = 0, x = 0, y = N - 1;
        int lastx = 0, lasty = 0;

        for (int i = 0; i < N; i++) {
            if (lst[i] == 0) {
                K--;
            } else if (lst[i] > 0) {
                lst_p[lastx++] = lst[i];
            } else {
                lst_m[lasty++] = lst[i];
            }
        }

        int ans = 1000000000;

        for (int j = 0; j <= K; j++) {
            if (j > lastx || K - j > lasty) {
                continue;
            }

            if (j == 0) {
                p = 0;
            } else {
                p = lst_p[j - 1];
            }

            if (K - j == 0) {
                m = 0;
            } else {
                m = lst_m[lasty - (K - j)];
            }

            ans = Math.min(ans, Math.min(2 * p + Math.abs(m), p + 2 * Math.abs(m)));
        }

        System.out.println(ans);
    }
}

