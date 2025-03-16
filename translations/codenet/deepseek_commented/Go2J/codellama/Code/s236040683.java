
package main;

import java.util.Scanner;

public class Main {

    public static void out(Object... x) {
        System.out.println(x);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of nodes (N) and the number of edges (M)
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Initialize a slice of Node with N elements
        Node[] n = new Node[N];

        // Read M pairs of edges and populate the adjacency list for each node
        for (int i = 0; i < M; i++) {
            int from = sc.nextInt() - 1;
            int to = sc.nextInt() - 1;
            n[from].to = append(n[from].to, to);
            n[to].to = append(n[to].to, from);
        }

        // Print the size of the adjacency list for each node
        for (int i = 0; i < N; i++) {
            out(n[i].to.length);
        }
    }

    public static <T> T[] append(T[] a, T x) {
        T[] b = (T[]) new Object[a.length + 1];
        System.arraycopy(a, 0, b, 0, a.length);
        b[a.length] = x;
        return b;
    }
}

class Node {
    int[] to;
}

