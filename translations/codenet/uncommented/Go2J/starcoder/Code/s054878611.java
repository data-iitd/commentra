package main;

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
        int[] memo = new int[100000 + 2];
        for (int num : a) {
            memo[num]++;
            memo[num + 1]++;
            memo[num + 2]++;
        }
        int out = 0;
        for (int num : memo) {
            if (num > 0) {
                out = Math.max(out, num);
            }
        }
        return out;
    }
}

