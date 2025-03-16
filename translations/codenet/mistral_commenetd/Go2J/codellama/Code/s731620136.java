
// +build ignore

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        if (N < 4) {
            System.out.println(0);
            return;
        }
        String S = sc.next();
        int nr = 0, nb = 0, ng = 0;
        for (int i = 0; i < N; i++) {
            if (S.charAt(i) == 'R') {
                nr++;
            } else if (S.charAt(i) == 'B') {
                nb++;
            } else {
                ng++;
            }
        }
        int same = 0;
        for (int a = 1; a < N; a++) {
            int i = 0, j = a, k = 2 * a;
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

