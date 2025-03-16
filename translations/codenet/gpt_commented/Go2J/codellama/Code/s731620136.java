
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S = sc.next();

        if (N == 0) {
            System.out.println(0);
            return;
        }

        if (N < 4) {
            System.out.println(0);
            return;
        }

        int nr = 0, nb = 0, ng = 0;
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
        for (int a = 1; a < N; a++) {
            int i = 0;
            int j = a;
            int k = 2 * a;
            if (k >= N) {
                break;
            }
            while (k < N) {
                if (S.charAt(i) != S.charAt(j) && S.charAt(i) != S.charAt(k) && S.charAt(j) != S.charAt(k)) {
                    same++;
                }
                i++;
                j++;
                k++;
            }
        }

        int tot = nr * nb * ng;
        System.out.println(tot - same);
    }
}

