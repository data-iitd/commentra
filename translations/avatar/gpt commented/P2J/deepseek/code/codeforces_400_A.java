import java.io.*;
import java.util.*;

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

    static class Helper {
        boolean checkArrangement(int a, int b, List<Integer> l) {
            List<List<Integer>> tot = new ArrayList<>();
            for (int i = 0; i < b; i++) {
                List<Integer> sublist = new ArrayList<>();
                for (int j = i * a; j < i * a + a; j++) {
                    sublist.add(l.get(j));
                }
                tot.add(sublist);
            }

            for (int i = 0; i < tot.get(0).size(); i++) {
                int sum = 0;
                for (int j = 0; j < tot.size(); j++) {
                    sum += tot.get(j).get(i);
                }
                if (sum == b) {
                    return true;
                }
            }
            return false;
        }
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();
        Helper helper = new Helper();
        int t = fr.nextInt();
        for (int i = 0; i < t; i++) {
            String x = fr.nextLine();
            List<Integer> s = new ArrayList<>();
            for (char c : x.toCharArray()) {
                if (c == 'O') {
                    s.add(0);
                } else {
                    s.add(1);
                }
            }

            List<int[]> validArrangements = new ArrayList<>();
            for (int j = 1; j <= 12; j++) {
                if (12 % j == 0) {
                    if (helper.checkArrangement(j, 12 / j, s)) {
                        validArrangements.add(new int[]{12 / j, j});
                    }
                }
            }

            System.out.print(validArrangements.size() + " ");
            validArrangements.sort(Comparator.comparingInt(a -> a[0]));
            for (int[] arrangement : validArrangements) {
                System.out.print(arrangement[0] + "x" + arrangement[1] + " ");
            }
            System.out.println();
        }
    }
}
