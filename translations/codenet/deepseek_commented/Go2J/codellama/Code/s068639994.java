
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int[] ls = new int[n];
        for (int i = 0; i < n; i++) {
            ls[i] = Integer.parseInt(tokenizer.nextToken());
        }
        int[] lsRev = new int[n];
        for (int i = 0; i < n; i++) {
            lsRev[i] = ls[n - i - 1];
        }
        Arrays.sort(ls);
        Arrays.sort(lsRev);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int p = Math.min(ls[i], ls[j]);
                int q = Math.max(ls[i], ls[j]);
                int x = q - p;
                int y = q + p;
                int l = Arrays.binarySearch(ls, x);
                int r = n - Arrays.binarySearch(lsRev, y);
                int sum = r - l;
                if (i >= l && i <= r) {
                    sum--;
                }
                if (j >= l && j <= r) {
                    sum--;
                }
                sum = Math.max(0, sum);
                ans += sum;
            }
        }
        ans /= 3;
        System.out.println(ans);
    }
}

