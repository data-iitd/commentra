// 深さ優先探索
import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        int[][] ab = new int[N-1][2];
        ArrayList<Integer>[] edges = new ArrayList[N];
        for (int i = 0; i < N-1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            ab[i][0] = a;
            ab[i][1] = b;
            if (edges[a] == null) {
                edges[a] = new ArrayList<Integer>();
            }
            edges[a].add(b);
            if (edges[b] == null) {
                edges[b] = new ArrayList<Integer>();
            }
            edges[b].add(a);
        }

        HashMap<Integer, Integer> colors = new HashMap<Integer, Integer>();
        int[] q = new int[3];
        q[0] = 0;
        q[1] = -1;
        q[2] = -1;
        while (q.length != 0) {
            int currentNode = q[0];
            int usedColor = q[1];
            int parentNode = q[2];
            q = q.slice(3);
            int color = 1;
            for (int childNode : edges[currentNode]) {
                if (childNode == parentNode) {
                    continue;
                }
                if (color == usedColor) {
                    color++;
                }
                colors.put(genid(currentNode, childNode), color);
                q = append(q, new int[] {childNode, color, currentNode});
                color++;
            }
        }

        int K = -1;
        for (int i = 0; i < N; i++) {
            int t = edges[i].size();
            if (t > K) {
                K = t;
            }
        }
        System.out.println(K);

        for (int i = 0; i < N-1; i++) {
            System.out.println(colors.get(genid(ab[i][0], ab[i][1])));
        }
    }

    public static int genid(int a, int b) {
        if (b < a) {
            a = b;
            b = a;
        }
        return a*100000 + b;
    }

    public static int[] append(int[] arr, int[] arr2) {
        int[] result = new int[arr.length + arr2.length];
        for (int i = 0; i < arr.length; i++) {
            result[i] = arr[i];
        }
        for (int i = 0; i < arr2.length; i++) {
            result[i+arr.length] = arr2[i];
        }
        return result;
    }
}

