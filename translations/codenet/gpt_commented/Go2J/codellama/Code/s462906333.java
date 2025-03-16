
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int ans = Integer.MAX_VALUE;
        for (int k = 0; k < n; k++) {
            int kans = 0;
            for (int i = 0; i < n; i++) {
                if (i - k < 0) {
                    a[i] = Math.min(a[i], a[n + i - k]);
                } else {
                    a[i] = Math.min(a[i], a[i - k]);
                }
                kans += a[i];
            }
            ans = Math.min(ans, kans + k * x);
        }
        System.out.println(ans);
    }
}

