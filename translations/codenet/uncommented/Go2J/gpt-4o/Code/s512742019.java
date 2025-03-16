import java.util.*;
import java.io.*;

public class Main {
    static class Mon {
        int x, h;

        Mon(int x, int h) {
            this.x = x;
            this.h = h;
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

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter wtr = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        int A = Integer.parseInt(st.nextToken());

        Mon[] M = new Mon[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            M[i] = new Mon(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        Arrays.sort(M, Comparator.comparingInt(m -> m.x));

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
                long count = (m.h + A - 1) / A; // Equivalent to ceil(m.h / A)
                ans += count;
                long damage = count * A;
                q.push(new Node(m.x + 2 * D, (int) damage));
                total += damage;
            }
        }

        wtr.write(ans + "\n");
        wtr.flush();
    }
}
// <END-OF-CODE>
