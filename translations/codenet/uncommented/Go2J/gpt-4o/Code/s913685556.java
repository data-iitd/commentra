import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        int A = sc.nextInt();
        int B = sc.nextInt();

        int mx = Math.max(A + B, A - B);
        mx = Math.max(mx, A * B);
        System.out.println(mx);
    }

    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() throws IOException {
            if (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public int[] nextIntArray() throws IOException {
            String line = br.readLine();
            StringTokenizer tokenizer = new StringTokenizer(line);
            int[] array = new int[tokenizer.countTokens()];
            int index = 0;
            while (tokenizer.hasMoreTokens()) {
                array[index++] = Integer.parseInt(tokenizer.nextToken());
            }
            return array;
        }

        public long[] nextLongArray() throws IOException {
            String line = br.readLine();
            StringTokenizer tokenizer = new StringTokenizer(line);
            long[] array = new long[tokenizer.countTokens()];
            int index = 0;
            while (tokenizer.hasMoreTokens()) {
                array[index++] = Long.parseLong(tokenizer.nextToken());
            }
            return array;
        }

        public java.util.Map<Integer, Boolean> nextMap() throws IOException {
            String line = br.readLine();
            StringTokenizer tokenizer = new StringTokenizer(line);
            java.util.Map<Integer, Boolean> map = new java.util.HashMap<>();
            while (tokenizer.hasMoreTokens()) {
                int key = Integer.parseInt(tokenizer.nextToken());
                map.put(key, true);
            }
            return map;
        }
    }
}
// <END-OF-CODE>
