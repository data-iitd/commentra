import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        int A = sc.nextInt();
        int B = sc.nextInt();

        int mx = max(A + B, A - B);
        mx = max(mx, A * B);
        System.out.println(mx);
    }

    // max function: Returns the larger of two integers.
    public static int max(int a, int b) {
        return a < b ? b : a;
    }

    // Scanner class: Wraps a BufferedReader and provides methods to read various types of input data.
    static class Scanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public Scanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }

        // Next method: Reads the next token from the input buffer.
        public String next() throws IOException {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        // NextInt method: Reads the next integer from the input buffer.
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        // NextInt64 method: Reads the next 64-bit integer from the input buffer.
        public long nextInt64() throws IOException {
            return Long.parseLong(next());
        }

        // NextFloat method: Reads the next floating-point number from the input buffer.
        public float nextFloat() throws IOException {
            return Float.parseFloat(next());
        }

        // NextIntArray method: Reads the next array of integers from the input buffer.
        public int[] nextIntArray() throws IOException {
            String line = reader.readLine();
            StringTokenizer st = new StringTokenizer(line);
            int[] result = new int[st.countTokens()];
            int index = 0;
            while (st.hasMoreTokens()) {
                result[index++] = Integer.parseInt(st.nextToken());
            }
            return result;
        }

        // NextInt64Array method: Reads the next array of 64-bit integers from the input buffer.
        public long[] nextInt64Array() throws IOException {
            String line = reader.readLine();
            StringTokenizer st = new StringTokenizer(line);
            long[] result = new long[st.countTokens()];
            int index = 0;
            while (st.hasMoreTokens()) {
                result[index++] = Long.parseLong(st.nextToken());
            }
            return result;
        }

        // NextMap method: Reads the next map of integers from the input buffer.
        public java.util.Map<Integer, Boolean> nextMap() throws IOException {
            String line = reader.readLine();
            StringTokenizer st = new StringTokenizer(line);
            java.util.Map<Integer, Boolean> map = new java.util.HashMap<>();
            while (st.hasMoreTokens()) {
                int key = Integer.parseInt(st.nextToken());
                map.put(key, true);
            }
            return map;
        }
    }
}

// <END-OF-CODE>
