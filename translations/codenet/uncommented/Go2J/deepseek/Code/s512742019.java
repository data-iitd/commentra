import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    throw new RuntimeException(e);
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
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }

        int[] nextIntArray(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        long[] nextLongArray(int n) {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }

        double[] nextDoubleArray(int n) {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextDouble();
            }
            return arr;
        }
    }

    static class Mon implements Comparable<Mon> {
        int x, h;

        Mon(int x, int h) {
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

        Node(int x, int h) {
            this.x = x;
            this.h = h;
        }
    }

    static class Queue {
        List<Node> arr = new ArrayList<>();

        void push(Node v) {
            arr.add(v);
        }

        Node first() {
            return arr.get(0);
        }

        Node pop() {
            Node res = arr.get(0);
            arr.remove(0);
            return res;
        }

        boolean isEmpty() {
            return arr.isEmpty();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner();
        PrintWriter wtr = new PrintWriter(System.out);
        int N = sc.nextInt(), D = sc.nextInt(), A = sc.nextInt();
        List<Mon> M = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            M.add(new Mon(sc.nextInt(), sc.nextInt()));
        }
        Collections.sort(M);
        Queue q = new Queue();
        long ans = 0;
        long total = 0;
        for (Mon m : M) {
            while (!q.isEmpty() && q.first().x < m.x) {
                total -= q.pop().h;
            }
            if (total < m.h) {
                m.h -= total;
                long count = (m.h + A - 1) / A;
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
