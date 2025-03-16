import java.util.*;

public class AtCoder {
    static int N, M;
    static int[] H;
    static List<Integer>[] G;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();
        H = new int[N];
        G = new ArrayList[N];

        for (int i = 0; i < N; i++) {
            H[i] = scanner.nextInt();
            G[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            int u = scanner.nextInt() - 1;
            int v = scanner.nextInt() - 1;
            G[u].add(v);
            G[v].add(u);
        }

        long ans = 0;
        for (int u = 0; u < N; u++) {
            boolean flag = true;
            for (int v : G[u]) {
                if (H[u] <= H[v]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans++;
        }
        System.out.println(ans);
        scanner.close();
    }
}
// <END-OF-CODE>
