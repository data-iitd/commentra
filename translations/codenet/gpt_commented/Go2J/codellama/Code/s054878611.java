
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        System.out.println(solution(n, a));
    }

    public static int solution(int n, int[] a) {
        int[] memo = new int[100001];
        for (int i = 0; i < n; i++) {
            memo[a[i]]++;
            memo[a[i] + 1]++;
            memo[a[i] + 2]++;
        }
        int out = 0;
        for (int i = 0; i < memo.length; i++) {
            if (memo[i] > 0) {
                out = Math.max(out, memo[i]);
            }
        }
        return out;
    }
}

