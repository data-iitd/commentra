import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static List<Integer>[] G = new ArrayList[100000];
    static boolean[] used = new boolean[100000];
    static int[] grundy = new int[100000];

    static void dfs(int v) {
        used[v] = true;
        grundy[v] = 0;
        for (int i = 0; i < G[v].size(); i++) {
            if (!used[G[v].get(i)]) {
                dfs(G[v].get(i));
                grundy[v] ^= (grundy[G[v].get(i)] + 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        
        for (int i = 0; i < N - 1; i++) {
            int x = scanner.nextInt() - 1;
            int y = scanner.nextInt() - 1;
            if (G[x] == null) G[x] = new ArrayList<>();
            if (G[y] == null) G[y] = new ArrayList<>();
            G[x].add(y);
            G[y].add(x);
        }
        
        dfs(0);
        if (grundy[0] != 0) {
            System.out.println("Alice");
        } else {
            System.out.println("Bob");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
