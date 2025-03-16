// 深さ優先探索
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    // 辺のIDを生成する
    public static int genid(int a, int b) {
        if (b < a) {
            a = b;
            b = a;
        }
        return a * 100000 + b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 頂点数を読み込む
        int N = scanner.nextInt();

        // 辺の情報を保持する配列と隣接リストを初期化する
        int[][] ab = new int[N - 1][2];
        ArrayList<Integer>[] edges = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            edges[i] = new ArrayList<>();
        }

        // 辺を読み込んで隣接リストを作成する
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1; // 0-indexed
            int b = scanner.nextInt() - 1; // 0-indexed
            ab[i][0] = a;
            ab[i][1] = b;
            edges[a].add(b);
            edges[b].add(a);
        }

        // 辺に色を割り当てるためのマップを作成する
        HashMap<Integer, Integer> colors = new HashMap<>();
        // 深さ優先探索を行うためのスタックを作成する
        int[][] stack = new int[N - 1][3];
        stack[0][0] = 0; // 0-indexed
        stack[0][1] = -1;
        stack[0][2] = -1;

        // 深さ優先探索を行い、辺に色を割り当てる
        for (int i = 0; i < N - 1; i++) {
            int currentNode = stack[i][0];
            int usedColor = stack[i][1];
            int parentNode = stack[i][2];

            int color = 1; // 色を1から始める
            for (int childNode : edges[currentNode]) {
                if (childNode == parentNode) {
                    continue; // 親ノードはスキップする
                }
                if (color == usedColor) {
                    color++; // 親ノードで使われている色はスキップする
                }
                // 辺の色を割り当てる
                colors.put(genid(currentNode, childNode), color);
                // 子ノードをスタックに積む
                stack[i + 1][0] = childNode;
                stack[i + 1][1] = color;
                stack[i + 1][2] = currentNode;
                color++; // 次の色に移る
            }
        }

        // グラフの最大次数を求める
        int K = -1;
        for (int i = 0; i < N; i++) {
            int t = edges[i].size(); // 頂点iの次数
            if (t > K) {
                K = t; // 最大次数を更新する
            }
        }
        System.out.println(K); // 最大次数を出力する

        // 各辺に割り当てられた色を出力する
        for (int i = 0; i < N - 1; i++) {
            System.out.println(colors.get(genid(ab[i][0], ab[i][1])));
        }
    }
}

