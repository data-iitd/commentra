
import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

    // Initialize an empty graph with given size
    static class Graph0n {
        private ArrayList<Node0n> dt = new ArrayList<>();

        Graph0n(int sz) {
            for (int i = 0; i < sz; i++) {
                Node0n node1 = new Node0n();
                dt.add(node1);
            }
        }

        // Add an edge between two nodes
        public void add(int vn, int val) {
            dt.get(vn).add(val);
        }

        // Add a bidirectional edge between two nodes
        public void add2(int vn, int val) {
            dt.get(vn).add(val);
            dt.get(val).add(vn);
        }

        // Get the value at the given index of the given node
        public int get(int vn, int index) {
            return dt.get(vn).get(index);
        }

        // Get all the neighbors of the given node
        public ArrayList<Integer> get(int vn) {
            return dt.get(vn).getAll();
        }

        // Get the size of the given node's neighbor list
        public int sizeOf(int vn) {
            return dt.get(vn).size();
        }

        // Clear all the neighbor lists of all nodes
        public void clear() {
            for (int i = 0; i < dt.size(); i++) {
                dt.get(i).clear();
            }
        }
    }

    // A simple node class without weight
    static class Node0n {
        private ArrayList<Integer> next_vs = new ArrayList<>();

        public void add(int val) {
            next_vs.add(val);
        }

        public int get(int ad) {
            return next_vs.get(ad);
        }

        public ArrayList<Integer> getAll() {
            return next_vs;
        }

        public int size() {
            return next_vs.size();
        }

        public void clear() {
            next_vs.clear();
        }
    }

    // A simple edge class without weight
    static class Edge {
        int from, v2;

        public Edge(int vn) {
            this.v2 = vn;
        }

        public Edge(int cm, int vn) {
            this.from = cm;
            this.v2 = vn;
        }
    }

    // A simple edge class with two weights
    static class Edge2 {
        int v2;
        long cost1, cost2;

        public Edge2(int vn, long w1, long w2) {
            this.v2 = vn;
            this.cost1 = w1;
            this.cost2 = w2;
        }
    }

    // A custom comparator for sorting edges based on their weights
    static class Comparator_Edge implements Comparator<Edge> {
        public int compare(Edge a, Edge b) {
            if (a.weight > b.weight) return -1;
            else if (a.weight < b.weight) return 1;
            else return b.v2 - a.v2;
        }
    }

    // A custom comparator for sorting edges based on their destination nodes
    static class V2Comp implements Comparator<Edge> {
        public int compare(Edge a, Edge b) {
            if (a.v2 > b.v2) return -1;
            else if (a.v2 < b.v2) return 1;
            else if (a.weight > b.weight) return -1;
            else if (a.weight < b.weight) return 1;
            else return 0;
        }
    }

    // A custom comparator for sorting edges in reverse order based on their destination nodes
    static class antiV2 implements Comparator<Edge> {
        public int compare(Edge a, Edge b) {
            if (a.v2 > b.v2) return 1;
            else if (a.v2 < b.v2) return -1;
            else if (a.weight > b.weight) return -1;
            else if (a.weight < b.weight) return 1;
            else return 0;
        }
    }

    // A simple vector class
    static class Vector {
        int x, y;

        public Vector(int sx, int sy) {
            this.x = sx;
            this.y = sy;
        }
    }

    // Some algorithms I like: cumulative sum and UF tree
    // PriorityQueue can output elements in non-sorted order by default
    // long bitwise operations should use 1L instead of int or long literal

    public static void main(String[] args) throws Exception {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int n = sc.nexI();
        String s = sc.next();
        boolean[] flaged = new boolean[n];
        fill(flaged, false);

        long pop1st = 0L;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') {
                flaged[i] = true;
                pop1st++;
            }
        }

        long surp1 = 0;
        for (int i = 0; i < n; i++) {
            surp1 *= 2L;
            if (flaged[i]) surp1++;
            surp1 %=(pop1st + 1L);
        }

        long surp9 = 0L;
        if (pop1st > 1) {
            for (int i = 0; i < n; i++) {
                surp9 *= 2L;
                if (flaged[i]) surp9++;
                surp9 %=(pop1st - 1L);
            }
        }

        for (int p = 0; p < n; p++) {
            if (flaged[p]) {
                if (pop1st == 1) {
                    out.println(0);
                    continue;
                }
                long dw = surp9;

                long dif = pow10E97(2, n - p - 1, pop1st - 1);
                dw -= dif;
                dw += (pop1st - 1L);
                dw %=(pop1st - 1L);

                int ans = 1;
                while (dw != 0) {
                    if (dw < 0) out.println(1 / 0);
                    int count = countFlaged(dw);
                    dw %= count;
                    ans++;
                }
                out.println(ans);
            } else {
                long dw = surp1;

                long dif = pow10E97(2, n - p - 1, pop1st + 1);
                dw += dif;
                dw %=(pop1st + 1L);

                int ans = 1;
                while (dw != 0) {
                    if (dw < 0) out.println(1 / 0);
                    int count = countFlaged(dw);
                    dw %= count;
                    ans++;
                }
                out.println(ans);
            }
        }

        out.flush();
    }

    // Some constants and utility functions
    private static int INF = (int) 1e8;
    private static long INFL = (long) 1e17;
    private static long e97 = (long) 1e9 + 7;

    void assertion(boolean b) { if (!b) throw new AssertionError(); }

    private static int abs(int a) { return (a >= 0) ? a : -a; }
    private static long abs(long a) { return (a >= 0) ? a : -a; }
    private static double abs(double a) { return (a >= 0) ? a : -a; }

    private static int min(int a, int b) { return (a > b) ? b : a; }
    private static long min(long a, long b) { return (a > b) ? b : a; }
    private static double min(double a, double b) { return (a > b) ? b : a; }

    private static int max(int a, int b) { return (a > b) ? a : b; }
    private static long max(long a, long b) { return (a > b) ? a : b; }
    private static double max(double a, double b) { return (a > b) ? a : b; }

    private static int minN(int... ins) {
        int min = ins[0];
        for (int i = 1; i < ins.length; i++) {
            if (ins[i] < min) min = ins[i];
        }
        return min;
    }
    private static int maxN(int... ins) {
        int max = ins[0];
        for (int i = 1; i < ins.length; i++) {
            if (ins[i] > max) max = ins[i];
        }
        return max;
    }
    private static long minN(long... ins) {
        long min = ins[0];
        for (int i = 1; i < ins.length; i++) {
            if (ins[i] < min) min = ins[i];
        }
        return min;
    }
    private static long maxN(long... ins) {
        long max = ins[0];
        for (int i = 1; i < ins.length; i++) {
            if (ins[i] > max) max = ins[i];
        }
        return max;
    }

    private static int minExAd(int[] dt, int ad) {
        int min = INF;
        for (int i = 0; i < dt.length; i++) {
            if (i != ad && dt[i] < min) min = dt[i];
        }
        return min;
    }
    private static long minExAd(long[] dt, int ad) {
        long min = INFL;
        for (int i = 0; i < dt.length; i++) {
            if (i != ad && dt[i] < min) min = dt[i];
        }
        return min;
    }
    private static int minExVal(int[] dt, int ex_val) {
        int min = INF;
        for (int i = 0; i < dt.length; i++) {
            if (dt[i] != ex_val && dt[i] < min) min = dt[i];
        }
        return min;
    }
    private static long minExVal(long[] dt, long ex_val) {
        long min = INFL;
        for (int i = 0; i < dt.length; i++) {
            if (dt[i] != ex_val && dt[i] < min) min = dt[i];
        }
        return min;
    }
    private static int maxExAd(int[] dt, int ad) {
        int max = -INF;
        for (int i = 0; i < dt.length; i++) {
            if (i != ad && dt[i] > max) max = dt[i];
        }
        return max;
    }
    private static long maxExAd(long[] dt, int ad) {
        long max = -INFL;
        for (int i = 0; i < dt.length; i++) {
            if (i != ad && dt[i] > max) max = dt[i];
        }
        return max;
    }
    private static int maxExVal(int[] dt, int ex_val) {
        int max = -INF;
        for (int i = 0; i < dt.length; i++) {
            if (dt[i] != ex_val && dt[i] > max) max = dt[i];
        }
        return max;
    }
    private static long maxExVal(long[] dt, long ex_val) {
        long max = -INFL;
        for (int i = 0; i < dt.length; i++) {
            if (dt[i] != ex_val && dt[i] > max) max = dt[i];
        }
        return max;
    }

    private static int sumA(int[] dt) {
        int sum = 0;
        for (int e : dt) sum += e;
        return sum;
    }
    private static long sumA(long[] dt) {
        long sum = 0;
        for (long e : dt) sum += e;
        return sum;
    }
    private static int sumA(List<Integer> dt) {
        int sum = 0;
        for (long e : dt) sum += e;
        return sum;
    }

    private static boolean same3(long a, long b, long c) {
        if (a != b) return false;
        if (b != c) return false;
    }
}