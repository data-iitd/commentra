
package main;

import java.util.Scanner;

public class Main {

    public static void out(Object... x) {
        System.out.println(x);
    }

    public static int getInt() {
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }

    public static String getString() {
        Scanner sc = new Scanner(System.in);
        return sc.next();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.useDelimiter("\\s+");
        int n = getInt();
        int q = getInt();

        FenwickTree fw = new FenwickTree(n);
        for (int i = 0; i < n; i++) {
            int a = getInt();
            fw.add(i, a);
        }

        for (int i = 0; i < q; i++) {
            int t = getInt();
            if (t == 0) {
                int p = getInt();
                int x = getInt();
                fw.add(p, x);
            } else {
                int l = getInt();
                int r = getInt();
                out(fw.sum(l, r));
            }
        }
    }
}

class FenwickTree {
    int n;
    int[] data;

    public FenwickTree(int n) {
        this.n = n;
        data = new int[n];
    }

    public void add(int p, int x) {
        p++;
        while (p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
}

