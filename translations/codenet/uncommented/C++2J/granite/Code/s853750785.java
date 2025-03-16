
// AtCoder.java :このファイルには'main' クラスが含まれています。プログラムの execution の開始と終了がそこで行われます。
//

// AtCoder.java : このファイルには'main' クラスが含まれています。プログラムの execution の開始と終了がそこで行われます。
//


import java.util.*;
import java.io.*;

class s853750785 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
        }
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            g.get(u).add(v);
            g.get(v).add(u);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            boolean flag = true;
            for (int j : g.get(i)) {
                if (h[i] <= h[j]) {
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

