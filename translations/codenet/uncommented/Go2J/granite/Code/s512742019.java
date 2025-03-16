
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class s512742019{
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter wtr = new PrintWriter(System.out);
        int N = sc.nextInt();
        int D = sc.nextInt();
        int A = sc.nextInt();
        Mon[] M = new Mon[N];
        for (int i = 0; i < N; i++) {
            M[i] = new Mon(sc.nextInt(), sc.nextInt());
        }
        Arrays.sort(M, Comparator.comparingInt(m -> m.x));
        Queue q = new Queue();
        int ans = 0;
        int total = 0;
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

    static class Mon {
        int x, h;

        public Mon(int x, int h) {
            this.x = x;
            this.h = h;
        }
    }

    static class Queue {
        Node[] arr;
        int size;

        public Queue() {
            arr = new Node[100000];
            size = 0;
        }

        public void push(Node v) {
            arr[size] = v;
            size++;
        }

        public Node first() {
            return arr[0];
        }

        public Node pop() {
            Node res = arr[0];
            for (int i = 0; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
            return res;
        }

        public boolean isEmpty() {
            return size == 0;
        }
    }
}

