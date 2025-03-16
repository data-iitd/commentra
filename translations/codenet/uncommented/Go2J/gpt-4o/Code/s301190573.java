import java.util.*;
import java.io.*;

public class Main {
    static int[] par, rank;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(reader.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        int[] p = new int[n];
        st = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            p[i] = Integer.parseInt(st.nextToken()) - 1; // Adjusting to 0-based index
        }
        
        initialize(n);
        
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(reader.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1; // Adjusting to 0-based index
            int y = Integer.parseInt(st.nextToken()) - 1; // Adjusting to 0-based index
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
// <END-OF-CODE>
