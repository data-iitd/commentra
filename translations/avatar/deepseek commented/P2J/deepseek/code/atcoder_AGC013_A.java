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
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = fr.nextInt();
        }

        // Removing consecutive duplicates from array A
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if (i == 0 || A[i] != A[i - 1]) {
                list.add(A[i]);
            }
        }
        N = list.size();
        int[] A_new = new int[N];
        for (int i = 0; i < N; i++) {
            A_new[i] = list.get(i);
        }

        // Initializing variables for main logic
        int i = 1;
        int ans = 0;

        // Main logic to find peaks
        while (i < N - 1) {
            if ((A_new[i - 1] < A_new[i] && A_new[i] > A_new[i + 1]) || (A_new[i - 1] > A_new[i] && A_new[i] < A_new[i + 1])) {
                ans += 1;
                i += 1; // Skip next element as it's already checked
            }
            i += 1;
        }

        // Output the total number of peaks found
        System.out.println(ans + 1);
    }
}
