import java.util.*;

public class LuckyGlass {
    static final int MOD = 7007;
    static int[][] F = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
    static List<Integer>[] Hash = new ArrayList[MOD];

    static {
        for (int i = 0; i < MOD; i++) {
            Hash[i] = new ArrayList<>();
        }
    }

    static class QUEUE {
        int a, b, c, tot;

        QUEUE(int a, int b, int c, int tot) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.tot = tot;
        }
    }

    static boolean HASH(int n) {
        for (int value : Hash[n % MOD]) {
            if (n == value) {
                return false;
            }
        }
        Hash[n % MOD].add(n);
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        scanner.close();

        QUEUE push = new QUEUE(a, b, c, 0);
        Queue<QUEUE> que = new LinkedList<>();
        que.add(push);

        while (!que.isEmpty()) {
            QUEUE fro = que.poll();
            if (fro.a == fro.b && fro.b == fro.c) {
                System.out.println(fro.tot);
                return;
            }
            for (int i = 0; i < 6; i++) {
                QUEUE newPush = new QUEUE(fro.a + F[i][0], fro.b + F[i][1], fro.c + F[i][2], fro.tot + 1);
                int n = newPush.a * 10000 + newPush.b * 100 + newPush.c;
                if (!HASH(n)) continue;
                que.add(newPush);
            }
        }
    }
}
//<END-OF-CODE>
