
package main;

import java.util.Scanner;

public class Main {

    public static void out(Object... x) {
        System.out.println(x);
    }

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

    public static <T> T[] append(T[] a, T e) {
        T[] b = (T[]) new Object[a.length + 1];
        System.arraycopy(a, 0, b, 0, a.length);
        b[a.length] = e;
        return b;
    }
}

class Node {
    int[] to;
}

