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
        FastReader scanner = new FastReader();
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            solve(scanner);
        }
    }

    static void solve(FastReader scanner) {
        List<Integer> s = new ArrayList<>();
        String x = scanner.nextLine();
        for (char c : x.toCharArray()) {
            if (c == 'O') {
                s.add(0);
            } else {
                s.add(1);
            }
        }

        List<int[]> tot = new ArrayList<>();
        for (int i = 1; i <= 12; i++) {
            if (12 % i == 0) {
                if (helper(i, 12 / i, s)) {
                    tot.add(new int[]{12 / i, i});
                }
            }
        }

        System.out.print(tot.size() + " ");
        Collections.sort(tot, (a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0]) : Integer.compare(a[1], b[1]));
        for (int[] pair : tot) {
            System.out.print(pair[0] + "x" + pair[1] + " ");
        }
        System.out.println();
    }

    static boolean helper(int a, int b, List<Integer> s) {
        List<List<Integer>> tot = new ArrayList<>();
        for (int i = 0; i < b; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = i * a; j < i * a + a; j++) {
                row.add(s.get(j));
            }
            tot.add(row);
        }

        for (int col = 0; col < a; col++) {
            List<Integer> column = new ArrayList<>();
            for (int row = 0; row < b; row++) {
                column.add(tot.get(row).get(col));
            }
            if (column.stream().mapToInt(Integer::intValue).sum() == b) {
                return true;
            }
        }
        return false;
    }
}
