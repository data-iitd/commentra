import java.util.*;
import java.io.*;

// Custom class to read input efficiently.
class Scanner {
    private BufferedReader br;
    private StringTokenizer st;

    public Scanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    private String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
}

// Custom class to represent a monster.
class Mon {
    int x, h;

    Mon(int x, int h) {
        this.x = x;
        this.h = h;
    }
}

// Custom comparator for sorting monsters by their x position.
class MonComparator implements Comparator<Mon> {
    public int compare(Mon a, Mon b) {
        return Integer.compare(a.x, b.x);
    }
}

// Main class to solve the problem.
public class Main {
    static final int MOD = (int) 1e9 + 7;
    static final long INF = 1L << 60;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        PrintWriter wtr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int N = sc.nextInt();
        int D = sc.nextInt();
        int A = sc.nextInt();
        Mon[] M = new Mon[N];

        for (int i = 0; i < N; i++) {
            M[i] = new Mon(sc.nextInt(), sc.nextInt());
        }

        Arrays.sort(M, new MonComparator());
        Queue<Node> q = new LinkedList<>();
        long ans = 0;
        long total = 0;

        for (int i = 0; i < N; i++) {
            Mon m = M[i];

            while (!q.isEmpty() && q.peek().x < m.x) {
                total -= q.poll().h;
            }

            if (total < m.h) {
                m.h -= total;
                long count = (m.h + A - 1) / A; // Equivalent to ceil(m.h / A)
                ans += count;
                long damage = count * A;
                q.add(new Node(m.x + 2 * D, damage));
                total += damage;
            }
        }

        wtr.println(ans);
        wtr.flush();
    }

    // Node class to represent a node in the queue.
    static class Node {
        int x, h;

        Node(int x, int h) {
            this.x = x;
            this.h = h;
        }
    }
}

// <END-OF-CODE>
