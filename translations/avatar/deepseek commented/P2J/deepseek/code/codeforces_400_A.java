import java.util.*;
import java.io.*;

public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();
        int t = fr.nextInt();
        for (int i = 0; i < t; i++) {
            solve(fr);
        }
    }

    public static void solve(FastReader fr) {
        char[] x = fr.nextLine().toCharArray();
        int[] s = new int[x.length];
        for (int i = 0; i < x.length; i++) {
            s[i] = (x[i] == 'O') ? 0 : 1;
        }
        List<int[]> tot = new ArrayList<>();
        for (int i = 1; i <= 12; i++) {
            if (12 % i == 0) {
                int b = 12 / i;
                if (canFormGrid(i, b, s)) {
                    tot.add(new int[]{b, i});
                }
            }
        }
        System.out.print(tot.size() + " ");
        Collections.sort(tot, (a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0]) : Integer.compare(a[1], b[1]));
        for (int[] dim : tot) {
            System.out.print(dim[0] + "x" + dim[1] + " ");
        }
        System.out.println();
    }

    public static boolean canFormGrid(int a, int b, int[] s) {
        int[][] grid = new int[b][a];
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j++) {
                grid[i][j] = s[i * a + j];
            }
        }
        for (int j = 0; j < a; j++) {
            int sum = 0;
            for (int i = 0; i < b; i++) {
                sum += grid[i][j];
            }
            if (sum == b) {
                return true;
            }
        }
        return false;
    }
}
