import java.util.*;

public class Main {
    static class Scanner {
        private final Scanner sc;

        public Scanner(Scanner sc) {
            this.sc = sc;
        }

        public String nextStr() {
            return sc.next();
        }

        public int nextInt() {
            return Integer.parseInt(sc.next());
        }

        public double nextDouble() {
            return Double.parseDouble(sc.next());
        }

        public char[] nextCharArray() {
            return sc.next().toCharArray();
        }

        public int[] nextIntArray(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(sc.next());
            }
            return arr;
        }

        public double[] nextDoubleArray(int n) {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Double.parseDouble(sc.next());
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
        private final LinkedList<Node> arr = new LinkedList<>();

        public void push(Node v) {
            arr.add(v);
        }

        public Node first() {
            return arr.getFirst();
        }

        public Node pop() {
            return arr.removeFirst();
        }

        public boolean isEmpty() {
            return arr.isEmpty();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(new java.util.Scanner(System.in));
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

        for (Mon m : M) {
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

        System.out.println(ans);
    }
}
