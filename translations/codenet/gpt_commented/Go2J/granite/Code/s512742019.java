
import java.io.*;
import java.util.*;

public class s512742019{
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter wtr = new PrintWriter(System.out);
        int N = sc.nextInt(), D = sc.nextInt(), A = sc.nextInt();
        Mon[] M = new Mon[N];
        for (int i = 0; i < N; i++) {
            M[i] = new Mon(sc.nextInt(), sc.nextInt());
        }
        Arrays.sort(M);
        Queue q = new Queue();
        int ans = 0, total = 0;
        for (int i = 0; i < N; i++) {
            Mon m = M[i];
            while (!q.isEmpty() && q.first().x < m.x) {
                total -= q.pop().h;
            }
            if (total < m.h) {
                m.h -= total;
                int count = (int) Math.ceil((double) m.h / A);
                ans += count;
                int damage = count * A;
                q.push(new Node(m.x + 2 * D, damage));
                total += damage;
            }
        }
        wtr.println(ans);
        wtr.flush();
    }

    static class Mon implements Comparable<Mon> {
        int x, h;

        public Mon(int x, int h) {
            this.x = x;
            this.h = h;
        }

        @Override
        public int compareTo(Mon o) {
            return Integer.compare(x, o.x);
        }
    }

    static class Queue {
        List<Node> arr = new ArrayList<>();

        public void push(Node v) {
            arr.add(v);
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

    static class Node {
        int x, h;

        public Node(int x, int h) {
            this.x = x;
            this.h = h;
        }
    }
}

