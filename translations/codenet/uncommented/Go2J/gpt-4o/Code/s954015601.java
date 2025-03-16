import java.util.*;

public class Main {
    static int genid(int a, int b) {
        if (b < a) {
            int temp = a;
            a = b;
            b = temp;
        }
        return a * 100000 + b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        int[][] ab = new int[N - 1][2];
        List<List<Integer>> edges = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            edges.add(new ArrayList<>());
        }

        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            ab[i][0] = a;
            ab[i][1] = b;
            edges.get(a).add(b);
            edges.get(b).add(a);
        }

        Map<Integer, Integer> colors = new HashMap<>();
        Stack<int[]> q = new Stack<>();
        q.push(new int[]{0, -1, -1});

        while (!q.isEmpty()) {
            int[] current = q.pop();
            int currentNode = current[0];
            int usedColor = current[1];
            int parentNode = current[2];
            int color = 1;

            for (int childNode : edges.get(currentNode)) {
                if (childNode == parentNode) {
                    continue;
                }
                if (color == usedColor) {
                    color++;
                }
                colors.put(genid(currentNode, childNode), color);
                q.push(new int[]{childNode, color, currentNode});
                color++;
            }
        }

        int K = -1;
        for (int i = 0; i < N; i++) {
            int t = edges.get(i).size();
            if (t > K) {
                K = t;
            }
        }
        System.out.println(K);

        for (int i = 0; i < N - 1; i++) {
            System.out.println(colors.get(genid(ab[i][0], ab[i][1])));
        }
    }
}
