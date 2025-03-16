
package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner();
        int x = sc.nextInt();
        int y = sc.nextInt();
        int[][] a = new int[][]{{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
        int xt = 0;
        int yt = 0;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                if (a[i][j] == x) {
                    xt = i;
                }
                if (a[i][j] == y) {
                    yt = i;
                }
            }
        }
        if (xt == yt) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    static class Scanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}

