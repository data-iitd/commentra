import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tokenizer = new StringTokenizer("");

    static String nextLine() throws IOException {
        return reader.readLine();
    }

    static int[] nextIntArray() throws IOException {
        String[] parts = nextLine().split(" ");
        int[] result = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            result[i] = Integer.parseInt(parts[i]) - 1;
        }
        return result;
    }

    static int[] par, rank;

    public static void main(String[] args) throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[] p = nextIntArray();
        initialize(n);
        for (int i = 0; i < m; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            unite(x, y);
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (same(i, p[i])) {
                s++;
            }
        }
        System.out.println(s);
    }

    static void initialize(int n) {
        par = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    static int root(int i) {
        if (par[i] == i) {
            return i;
        }
        par[i] = root(par[i]);
        return par[i];
    }

    static boolean same(int i, int j) {
        return root(i) == root(j);
    }

    static void unite(int i, int j) {
        i = root(i);
        j = root(j);
        if (i == j) {
            return;
        }
        if (rank[i] < rank[j]) {
            par[i] = j;
        } else {
            par[j] = i;
            if (rank[i] == rank[j]) {
                rank[i]++;
            }
        }
    }
}
