
// AtCoder.java

import java.util.*;

class s853750785 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] H = new int[N];
        for (int i = 0; i < N; i++) {
            H[i] = sc.nextInt();
        }
        List<List<Integer>> G = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            G.add(new ArrayList<>());
        }
        for (int i = 0; i < M; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            G.get(u).add(v);
            G.get(v).add(u);
        }
        int ans = 0;
        for (int u = 0; u < N; u++) {
            boolean flag = true;
            for (int v : G.get(u)) {
                if (H[u] <= H[v]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}

// Translate the above Java code to Python and end with comment "