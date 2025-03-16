
package main

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static final int MOD = 1000000007;

    private static int N;
    private static int[] p;

    private static int find(int n) {
        for (int i = 0; i < N; i++) {
            if (n == p[i]) {
                return 0;
            }
        }
        return 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        N = Integer.parseInt(st.nextToken());
        p = new int[200000];
        for (int i = 0; i < N; i++) {
            p[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i <= 100; i++) {
            if (find(Integer.parseInt(st.nextToken()) - i) == 1) {
                System.out.println(Integer.parseInt(st.nextToken()) - i);
                return;
            }
            if (find(Integer.parseInt(st.nextToken()) + i) == 1) {
                System.out.println(Integer.parseInt(st.nextToken()) + i);
                return;
            }
        }
    }
}

