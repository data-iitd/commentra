import java.util.*;
import java.io.*;

public class Main {
    static class Scanner {
        private final BufferedReader br;
        private StringTokenizer st;

        public Scanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
            st = new StringTokenizer("");
        }

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
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

        public char[] nextCharArray() throws IOException {
            return next().toCharArray();
        }

        public String[] nextStringArray(int n) throws IOException {
            String[] arr = new String[n];
            for (int i = 0; i < n; i++) {
                arr[i] = next();
            }
            return arr;
        }

        public int[] nextIntArray(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        public long[] nextLongArray(int n) throws IOException {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }

        public double[] nextDoubleArray(int n) throws IOException {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextDouble();
            }
            return arr;
        }
    }

    static class Mon implements Comparable<Mon> {
        int x, h;

        public Mon(int x, int h) {
            this.x = x;
            this.h = h;
        }

        @Override
        public int compareTo(Mon o) {
            return Integer.compare(this.x, o.x);
        }
    }

    static class Node implements Comparable<Node> {
        int x, h;

        public Node(int x, int h) {
            this.x = x;
            this.h = h;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.x, o.x);
        }
    }

    static class PriorityQueue {
        private final List<Node> arr;

        public PriorityQueue() {
            arr = new ArrayList<>();
        }

        public void push(Node v) {
            arr.add(v);
            Collections.sort(arr);
        }

        public Node first() {
            return arr.get(0);
        }

        public Node pop() {
            Node res = arr.get(0);
            arr.remove(0);
            return res;
        }

        public boolean isEmpty() {
            return arr.isEmpty();
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter wtr = new PrintWriter(System.out);

        int N = sc.nextInt();
        int D = sc.nextInt();
        int A = sc.nextInt();

        Mon[] M = new Mon[N];
        for (int i = 0; i < N; i++) {
            M[i] = new Mon(sc.nextInt(), sc.nextInt());
        }

        Arrays.sort(M);

        PriorityQueue q = new PriorityQueue();
        long ans = 0;
        long total = 0;

        for (int i = 0; i < N; i++) {
            Mon m = M[i];

            while (!q.isEmpty() && q.first().x < m.x) {
                Node first = q.pop();
                total -= first.h;
            }

            if (total < m.h) {
                long damage = m.h - total;
                ans += damage;
                q.push(new Node(m.x + 2 * D, (int) damage));
                total += damage;
            }
        }

        wtr.println(ans);
        wtr.flush();
    }
}
