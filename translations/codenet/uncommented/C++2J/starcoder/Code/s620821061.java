import java.util.*;

public class Main {
    public static void main(String[] args) {
        while (true) {
            int n, m;
            Scanner sc = new Scanner(System.in);
            n = sc.nextInt();
            m = sc.nextInt();
            if (n == 0) break;
            bm.init();
            int[] a = new int[n];
            int[] b = new int[m];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            for (int i = 0; i < m; i++) {
                b[i] = sc.nextInt();
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (gcd(a[i], b[j])!= 1) {
                        bm.add(i, j);
                    }
                }
            }
            System.out.println(bm.exec());
        }
    }
}

