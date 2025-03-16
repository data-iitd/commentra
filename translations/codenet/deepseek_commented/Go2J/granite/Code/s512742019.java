
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class s512742019{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int d = Integer.parseInt(br.readLine());
        int a = Integer.parseInt(br.readLine());

        Monster[] m = new Monster[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());
            m[i] = new Monster(x, h);
        }

        Arrays.sort(m, Comparator.comparingInt(o -> o.x));

        int ans = 0;
        int total = 0;
        Queue q = new Queue();
        for (int i = 0; i < n; i++) {
            Monster monster = m[i];
            while (!q.isEmpty() && q.first().x < monster.x) {
                total -= q.pop().h;
            }
            if (total < monster.h) {
                int damage = Math.max(0, monster.h - total);
                int count = (damage + a - 1) / a;
                ans += count;
                total += count * a;
                q.push(new Node(monster.x + 2 * d, count * a));
            }
        }

        pw.println(ans);
        pw.flush();
    }

    static class Monster implements Comparable<Monster> {
        int x, h;

        public Monster(int x, int h) {
            this.x = x;
            this.h = h;
        }

        @Override
        public int compareTo(Monster o) {
            return Integer.compare(x, o.x);
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
            arr[size++] = v;
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

    static class Node {
        int x, h;

        public Node(int x, int h) {
            this.x = x;
            this.h = h;
        }
    }
}

