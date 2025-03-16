import java.util.*;

public class LuckyGlass {
    static final int MOD = 7007;

    static class Queue {
        int a, b, c, tot;
    }

    static int[][] F = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
    static List<Integer>[] Hash = new ArrayList[MOD];

    static boolean HASH(int n) {
        int index = n % MOD;
        if (Hash[index] == null) {
            Hash[index] = new ArrayList<>();
        }
        for (int i = 0; i < Hash[index].size(); i++) {
            if (n == Hash[index].get(i)) {
                return false;
            }
        }
        Hash[index].add(n);
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Queue Push = new Queue();
        Push.tot = 0;

        Queue Fro = new Queue();
        Queue que = new Queue();

        Push.a = scanner.nextInt();
        Push.b = scanner.nextInt();
        Push.c = scanner.nextInt();

        que.push(Push);

        while (!que.isEmpty()) {
            Fro = que.poll();

            if (Fro.a == Fro.b && Fro.b == Fro.c) {
                System.out.println(Fro.tot);
                return;
            }

            for (int i = 0; i < 6; i++) {
                Push = new Queue();
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
