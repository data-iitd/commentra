package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int N = sc.nextInt();
        int[] dp = new int[H+10001];
        for (int l = 1; l < H+10001; l++) {
            dp[l] = 2100000000;
        }
        int amax = 0;
        for (int i = 0; i < N; i++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            if (A >= amax) {
                amax = A;
            }
            dp[A] = Math.min(dp[A], B);
            for (int j = A+1; j <= H+A+1; j++) {
                dp[j] = Math.min(dp[j], dp[j-A]+B);
            }
        }
        System.out.println(min(dp[H:H+amax+1]));
    }

    public static int min(int... n) {
        if (n.length == 0) {
            throw new RuntimeException("len == 0");
        }
        int r = n[0];
        for (int i = 1; i < n.length; i++) {
            if (n[i] <= r) {
                r = n[i];
            }
        }
        return r;
    }
}

