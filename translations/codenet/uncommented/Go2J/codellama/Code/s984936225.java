
package main

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int Inf = (int) (1 << 62);
        int[] dist = new int[N];
        for (int i = 0; i < N; i++) {
            dist[i] = Inf;
        }
        dist[0] = 0;
        for (int loop = 0; loop < N; loop++) {
            for (int i = 0; i < M; i++) {
                if (dist[i] == Inf) {
                    continue;
                }
                if (dist[i + 1] > dist[i] + sc.nextInt()) {
                    dist[i + 1] = dist[i] + sc.nextInt();
                }
            }
        }
        int ans = dist[N - 1];
        boolean[] navigate = new boolean[N];
        for (int loop = 0; loop < N; loop++) {
            for (int i = 0; i < M; i++) {
                if (dist[i] == Inf) {
                    continue;
                }
                if (dist[i + 1] > dist[i] + sc.nextInt()) {
                    dist[i + 1] = dist[i] + sc.nextInt();
                    navigate[i + 1] = true;
                }
                if (navigate[i]) {
                    navigate[i + 1] = true;
                }
            }
        }

        if (navigate[N - 1]) {
            System.out.println("inf");
        } else {
            System.out.println(-ans);
        }
    }
}

