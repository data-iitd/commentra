
package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        Node[] n = new Node[N];

        for (int i = 0; i < M; i++) {
            int from = sc.nextInt() - 1;
            int to = sc.nextInt() - 1;

            n[from].to = append(n[from].to, to);
            n[to].to = append(n[to].to, from);
        }

        for (int i = 0; i < N; i++) {
            out(n[i].to.length);
        }
    }

    public static void out(int x) {
        System.out.println(x);
    }

    public static class Node {
        public int[] to;
    }
}

