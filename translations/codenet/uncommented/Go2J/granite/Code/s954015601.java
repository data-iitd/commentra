
// 幅優先探索
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class s954015601{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Map<Integer, List<Integer>> edges = new HashMap<>();
        for (int i = 0; i < n - 1; i++) {
            String[] ab = br.readLine().split(" ");
            int a = Integer.parseInt(ab[0]) - 1;
            int b = Integer.parseInt(ab[1]) - 1;
            edges.computeIfAbsent(a, k -> new ArrayList<>()).add(b);
            edges.computeIfAbsent(b, k -> new ArrayList<>()).add(a);
        }

        Map<Integer, Integer> colors = new HashMap<>();
        Queue<Integer> q = new ArrayDeque<>();
        q.add(0);
        int[] usedColor = new int[n];
        int[] parentNode = new int[n];
        while (!q.isEmpty()) {
            int currentNode = q.poll();
            int color = 1;
            for (int childNode : edges.get(currentNode)) {
                if (childNode == parentNode[currentNode]) {
                    continue;
                }
                if (color == usedColor[currentNode]) {
                    color++;
                }
                colors.put(Math.min(currentNode, childNode) * 100000 + Math.max(currentNode, childNode), color);
                q.add(childNode);
                usedColor[childNode] = color;
                parentNode[childNode] = currentNode;
                color++;
            }
        }

        int K = 0;
        for (int i = 0; i < n; i++) {
            K = Math.max(K, edges.get(i).size());
        }
        System.out.println(K);

        for (int i = 0; i < n - 1; i++) {
            System.out.println(colors.get(Math.min(ab[i][0], ab[i][1]) * 100000 + Math.max(ab[i][0], ab[i][1])));
        }
    }
}

