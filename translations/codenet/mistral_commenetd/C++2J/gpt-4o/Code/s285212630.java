import java.util.*;

public class Main {
    static final long INF = 1145141919;
    static final long MOD = 1000000007;
    static final int MAX_L = 22;

    static long N;
    static List<Pair<Long, Long>>[] G = new ArrayList[100000];
    static long[][] U = new long[MAX_L][100000];
    static long[] R = new long[100000];
    static long[] L = new long[100000];

    static {
        for (int i = 0; i < G.length; i++) {
            G[i] = new ArrayList<>();
        }
    }

    static class Pair<X, Y> {
        X first;
        Y second;

        Pair(X first, Y second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) {
        // Your code logic here
    }
}

// <END-OF-CODE>
