
package main

import java.util.Scanner;

public class Main {
    public static void out(Object... obj) {
        System.out.println(String.valueOf(obj));
    }

    public static int getInt() {
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }

    public static String getString() {
        Scanner sc = new Scanner(System.in);
        return sc.next();
    }

    // min, max, asub, absなど基本関数
    public static int max(int a, int b) {
        if (a > b) {
            return a;
        }
        return b;
    }

    public static int min(int a, int b) {
        if (a < b) {
            return a;
        }
        return b;
    }

    public static int asub(int a, int b) {
        if (a > b) {
            return a - b;
        }
        return b - a;
    }

    public static int abs(int a) {
        if (a >= 0) {
            return a;
        }
        return -a;
    }

    public static void main(String[] args) {
        int N, C, K;
        N = getInt();
        C = getInt();
        K = getInt();
        int[] t = new int[N];
        for (int i = 0; i < N; i++) {
            t[i] = getInt();
        }

        sort(t);
        // out(t);
        int ans = 1;
        int cnt = 1;
        int end = t[0] + K;
        for (int i = 1; i < N; i++) {
            if (cnt < C && t[i] <= end) {
                cnt++;
                // out(t[i]);
            } else {
                // out("----");
                // out(t[i]);
                cnt = 1;
                end = t[i] + K;
                ans++;
            }
        }
        out(ans);
    }

    public static void sort(int[] t) {
        for (int i = 0; i < t.length; i++) {
            for (int j = i + 1; j < t.length; j++) {
                if (t[i] > t[j]) {
                    int tmp = t[i];
                    t[i] = t[j];
                    t[j] = tmp;
                }
            }
        }
    }
}

