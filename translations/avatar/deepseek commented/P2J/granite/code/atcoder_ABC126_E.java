
import java.io.*;
import java.util.*;

class atcoder_ABC126_E {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        List<List<Integer>> edge = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            edge.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            String[] xyz = br.readLine().split(" ");
            int x = Integer.parseInt(xyz[0]) - 1;
            int y = Integer.parseInt(xyz[1]) - 1;
            int z = Integer.parseInt(xyz[2]);
            edge.get(x).add(y);
            edge.get(y).add(x);
        }
        boolean[] used = new boolean[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                ans++;
                Queue<Integer> queue = new ArrayDeque<>();
                queue.add(i);
                while (!queue.isEmpty()) {
                    int node = queue.poll();
                    used[node] = true;
                    for (int nextnode : edge.get(node)) {
                        if (!used[nextnode]) {
                            queue.add(nextnode);
                        }
                    }
                }
            }
        }
        System.out.println(ans);
    }
}

Translate the above Java code to C++ and end with comment "