
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class codeforces_400_A{
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        while (t-- > 0) {
            solve(sc);
        }
    }

    private static void solve(FastReader sc) {
        String s = sc.nextLine();
        int[] arr = new int[12];
        for (int i = 0; i < 12; i++) {
            arr[i] = s.charAt(i) == 'O'? 0 : 1;
        }
        ArrayList<String> ans = new ArrayList<>();
        for (int i = 1; i <= 12; i++) {
            if (12 % i == 0) {
                int j = 12 / i;
                boolean flag = false;
                for (int k = 0; k < i; k++) {
                    int sum = 0;
                    for (int l = k; l < 12; l += j) {
                        sum += arr[l];
                    }
                    if (sum!= j) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    ans.add(i + "x" + j);
                }
            }
        }
        Collections.sort(ans);
        System.out.print(ans.size() + " ");
        for (String a : ans) {
            System.out.print(a + " ");
        }
        System.out.println();
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null ||!st.hasMoreElements()) {
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
}

Translate the above Java code to C++ and end with comment "