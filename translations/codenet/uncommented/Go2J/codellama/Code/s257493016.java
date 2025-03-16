package main

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
        dp[j] = Math.min(dp[j], dp[j-A] + B);
      }
    }
    System.out.println(min(dp, H, amax));
  }

  public static int min(int[] dp, int H, int amax) {
    int r = 2100000000;
    for (int i = H; i >= H-amax+1; i--) {
      r = Math.min(r, dp[i]);
    }
    return r;
  }
}

