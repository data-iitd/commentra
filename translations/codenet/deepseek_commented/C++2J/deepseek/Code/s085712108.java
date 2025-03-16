import java.util.*;

public class LuckyGlass {
    static final int MOD = 7007;

    static class QUEUE {
        int a, b, c, tot;
    }

    static int[][] F = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 1, 1},
        {2, 0, 0},
        {0, 2, 0},
        {0, 0, 2}
    };

    static List<Integer>[] Hash = new ArrayList[MOD];

    static {
        for (int i = 0; i < MOD; i++) {
            Hash[i] = new ArrayList<>();
        }
    }

    static boolean HASH(int n) {
        int hashKey = n % MOD;
        for (int i = 0; i < Hash[hashKey].size(); i++) {
            if (n == Hash[hashKey].get(i)) {
                return false;
            }
        }
        Hash[hashKey].add(n);
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        QUEUE push = new QUEUE();
        push.tot = 0;
        Queue<QUEUE> que = new LinkedList<>();
        push.a = scanner.nextInt();
        push.b = scanner.nextInt();
        push.c = scanner.nextInt();
        que.add(push);
        while (!que.isEmpty()) {
            QUEUE fro = que.poll();
            if (fro.a == fro.b && fro.b == fro.c) {
                System.out.println(fro.tot);
                return;
            }
            for (int i = 0; i < 6; i++) {
                QUEUE newPush = new QUEUE();
                newPush.a = fro.a + F[i][0];
                newPush.b = fro.b + F[i][1];
                newPush.c = fro.c + F[i][2];
                newPush.tot = fro.tot + 1;
                int n = newPush.a * 10000 + newPush.b * 100 + newPush.c;
                if (!HASH(n)) continue;
                que.add(newPush);
            }
        }
    }
}
