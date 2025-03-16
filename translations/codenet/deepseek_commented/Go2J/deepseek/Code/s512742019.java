import java.util.*;
import java.io.*;

class Main {
    static class Scanner {
        private final BufferedReader br;
        private StringTokenizer st;

        public Scanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
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

    static class Node {
        int x, h;

        public Node(int x, int h) {
            this.x = x;
            this.h = h;
        }
    }

    static class Queue {
        private final LinkedList<Node> list = new LinkedList<>();

        public void push(Node node) {
            list.addLast(node);
        }

        public Node first() {
            return list.getFirst();
        }

        public Node pop() {
            return list.removeFirst();
        }

        public boolean isEmpty() {
            return list.isEmpty();
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
        Queue q = new Queue();
        long ans = 0;
        long total = 0;
        for (int i = 0; i < N; i++) {
            Mon m = M[i];
            while (!q.isEmpty() && q.first().x < m.x) {
                total -= q.pop().h;
            }
            if (total < m.h) {
                m.h -= total;
                long count = (long) Math.ceil((double) m.h / A);
                ans += count;
                long damage = count * A;
                q.push(new Node(m.x + 2 * D, damage));
                total += damage;
            }
        }

        wtr.println(ans);
        wtr.flush();
    }
}
