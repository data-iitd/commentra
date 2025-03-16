import java.util.*;

public class LuckyGlass {
    static final int MOD = 7007;
    static class QUEUE {
        int a, b, c, tot;
    }
    static int[][] F = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
    static List<Integer>[] Hash = new ArrayList[MOD];

    static boolean HASH(int n) {
        int index = n % MOD;
        for (int i = 0; i < Hash[index].size(); i++) {
            if (n == Hash[index].get(i)) {
                return false;
            }
        }
        Hash[index].add(n);
        return true;
    }

    public static void main(String[] args) {
        for (int i = 0; i < MOD; i++) {
            Hash[i] = new ArrayList<>();
        }
        Scanner scanner = new Scanner(System.in);
        QUEUE Push = new QUEUE();
        Push.tot = 0;
        Queue<QUEUE> que = new LinkedList<>();
        Push.a = scanner.nextInt();
        Push.b = scanner.nextInt();
        Push.c = scanner.nextInt();
        que.add(Push);
        while (!que.isEmpty()) {
            QUEUE Fro = que.poll();
            if (Fro.a == Fro.b && Fro.b == Fro.c) {
                System.out.println(Fro.tot);
                return;
            }
            for (int i = 0; i < 6; i++) {
                Push = new QUEUE();
                Push.tot = Fro.tot + 1;
                Push.a = Fro.a + F[i][0];
                Push.b = Fro.b + F[i][1];
                Push.c = Fro.c + F[i][2];
                int n = Push.a * 10000 + Push.b * 100 + Push.c;
                if (!HASH(n)) continue;
                que.add(Push);
            }
        }
    }
}
