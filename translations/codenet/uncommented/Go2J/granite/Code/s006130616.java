
import java.util.Scanner;

public class s006130616{

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();

        int[][] a = new int[n][m];
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt();
            for (int j = 0; j < m; j++) {
                a[i][j] = scanner.nextInt();
            }
        }

        int ans = 1200001;
        int tot = 0;
        boolean ok = true;
        for (int bits = 0; bits < (1 << n); bits++) {
            tot = 0;
            ok = true;
            int[] skill = new int[m];
            for (int i = 0; i < n; i++) {
                if ((bits >> i) % 2 == 1) {
                    tot += p[i];
                    for (int j = 0; j < m; j++) {
                        skill[j] += a[i][j];
                    }
                }
            }

            for (int v : skill) {
                if (v < x) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                if (ans > tot) {
                    ans = tot;
                }
            }
        }

        if (ans!= 1200001) {
            System.out.println(ans);
        } else {
            System.out.println(-1);
        }
    }
}
