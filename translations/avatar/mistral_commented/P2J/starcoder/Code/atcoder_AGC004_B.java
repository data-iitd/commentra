
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int x = sc.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int[][] b = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int k = i - j;
                if (k < 0) {
                    k += n;
                }
                int m = a[k];
                for (int l = 0; l < n; l++) {
                    m = Math.min(m, a[i - l]);
                }
                b[j][i] = m;
            }
        }

        int m = 1000000000;
        for (int i = 0; i < n; i++) {
            int sum_row = 0;
            for (int j = 0; j < n; j++) {
                sum_row += b[j][i];
            }
            sum_row += x * i;
            m = Math.min(m, sum_row);
        }

        System.out.println(m);
    }
}

