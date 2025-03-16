
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

    public static int lowerBound(int[] a, int x) {
        int idx = java.util.Arrays.binarySearch(a, x);
        if (idx < 0) {
            idx = -idx - 1;
        }
        return idx;
    }

    public static int upperBound(int[] a, int x) {
        int idx = java.util.Arrays.binarySearch(a, x);
        if (idx < 0) {
            idx = -idx - 1;
        }
        return idx;
    }

    public static class Shop {
        public int a;
        public int b;

        public Shop(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    public static class Datas implements Comparable<Datas> {
        public int a;
        public int b;

        public Datas(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public int compareTo(Datas o) {
            return this.a - o.a;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.useDelimiter("\\s+");

        int N = sc.nextInt();
        int M = sc.nextInt();
        Datas[] s = new Datas[N];

        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            s[i] = new Datas(a, b);
        }
        java.util.Arrays.sort(s);

        int total = 0;
        for (Datas e : s) {
            int n = min(e.b, M);
            total += n * e.a;
            M -= n;
            if (M == 0) {
                break;
            }
        }
        out(total);
    }
}

