import java.util.*;
import java.io.*;
import java.math.*;

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
        String[] S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = fr.nextLine();
        }

        int[] march = new int[5];
        for (String s : S) {
            char firstChar = s.charAt(0);
            if (firstChar == 'M' || firstChar == 'A' || firstChar == 'R' || firstChar == 'C' || firstChar == 'H') {
                switch (firstChar) {
                    case 'M':
                        march[0]++;
                        break;
                    case 'A':
                        march[1]++;
                        break;
                    case 'R':
                        march[2]++;
                        break;
                    case 'C':
                        march[3]++;
                        break;
                    case 'H':
                        march[4]++;
                        break;
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {
                    ans += (long) march[i] * march[j] * march[k];
                }
            }
        }

        System.out.println(ans);
    }
}
