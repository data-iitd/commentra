import java.util.*;
import java.io.*;

// The main class declaration.
// This class uses BufferedReader and InputStreamReader for efficient I/O operations.

public class Main {
    static final int SIZE = 1000000;
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        int[] p = nextIntArray();
        int x, y;
        initialize(n);
        
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(reader.readLine());
            x = Integer.parseInt(st.nextToken()) - 1;
            y = Integer.parseInt(st.nextToken()) - 1;
            unite(x, y);
        }
        
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (same(i, p[i] - 1)) {
                s++;
            }
        }
        System.out.println(s);
    }

    static int[] par, rank;

    static void initialize(int n) {
        par = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    static int root(int i) {
        if (par[i] == i) return i;
        par[i] = root(par[i]);
        return par[i];
    }

    static boolean same(int i, int j) {
        return root(i) == root(j);
    }

    static void unite(int i, int j) {
        i = root(i);
        j = root(j);
        if (i == j) return;
        if (rank[i] < rank[j]) {
            par[i] = j;
        } else {
            par[j] = i;
            if (rank[i] == rank[j]) rank[i]++;
        }
    }

    static int[] nextIntArray() throws IOException {
        StringTokenizer st = new StringTokenizer(reader.readLine());
        int[] a = new int[st.countTokens()];
        for (int i = 0; i < a.length; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        return a;
    }
}
// <END-OF-CODE>
