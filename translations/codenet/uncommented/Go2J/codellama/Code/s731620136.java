
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        int N = sc.nextInt();
        String S = sc.next();

        if (N == 0) {
        }

        if (N < 4) {
            pw.println(0);
            pw.flush();
            return;
        }

        int nr = 0;
        int nb = 0;
        int ng = 0;
        for (int i = 0; i < N; i++) {
            if (S.charAt(i) == 'R') {
                nr++;
            }

            if (S.charAt(i) == 'B') {
                nb++;
            }

            if (S.charAt(i) == 'G') {
                ng++;
            }
        }

        int same = 0;
        // int etot = 0;
        for (int a = 1; a < N; a++) {
            int i = 0;
            int j = 1 * a;
            int k = 2 * a;
            if (k >= N) {
                break;
            }
            for (; k < N; k++) {
                // etot++;
                // System.out.printf("(%4d) [%2d] (%3d, %3d, %3d)", etot, a, i, j, k);
                if (S.charAt(i) != S.charAt(j) && S.charAt(i) != S.charAt(k) && S.charAt(j) != S.charAt(k)) {
                    same++;
                    // System.out.printf(" (%4d)", same);
                }
                // System.out.println();
                i++;
                j++;
                k++;
            }
        }

        int tot = nr * nb * ng;

        // int sum = 0;
        // int sum2 = 0;
        // for (int k = 2; k < N; k++) {
        //     for (int j = 1; j < k; j++) {
        //         for (int i = 0; i < j; i++) {
        //             if (j - i == k - j) {
        //                 if (S.charAt(i) != S.charAt(j) && S.charAt(i) != S.charAt(k) && S.charAt(j) != S.charAt(k)) {
        //                     sum2++;
        //                 }
        //                 continue;
        //             }

        //             if (S.charAt(i) != S.charAt(j) && S.charAt(i) != S.charAt(k) && S.charAt(j) != S.charAt(k)) {
        //                 sum++;
        //             }
        //         }
        //     }
        // }

        // System.out.println(tot + " " + same + " " + sum + " " + sum2);
        pw.println(tot - same);
        pw.flush();
    }
}

