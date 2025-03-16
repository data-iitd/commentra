import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.*;
import java.util.stream.*;

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
        int N = fr.nextInt();
        List<String> S = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            S.add(fr.nextLine());
        }

        int[] march_lis = new int[5];
        List<Character> march = Arrays.asList('M', 'A', 'R', 'C', 'H');

        for (String s : S) {
            char firstChar = s.charAt(0);
            if (march.contains(firstChar)) {
                march_lis[march.indexOf(firstChar)]++;
            }
        }

        long ans = 0;
        for (int x = 0; x < 5; x++) {
            for (int y = x + 1; y < 5; y++) {
                for (int z = y + 1; z < 5; z++) {
                    ans += (long) march_lis[x] * march_lis[y] * march_lis[z];
                }
            }
        }

        System.out.println(ans);
    }
}
