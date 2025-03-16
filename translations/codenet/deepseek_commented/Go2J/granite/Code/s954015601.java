
// 广度first搜索
package com.company;

import java.util.*;

public class s954015601{
    public static void main(String[] args) {
        // 读入点的数量
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // 读入每条边的两个点
        int[][] ab = new int[n - 1][2];
        for (int i = 0; i < n - 1; i++) {
            ab[i][0] = scanner.nextInt() - 1;
            ab[i][1] = scanner.nextInt() - 1;
        }

        // 读入的点的数量
        List<Integer>[] edges = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            edges[ab[i][0]].add(ab[i][1]);
            edges[ab[i][1]].add(ab[i][0]);
        }

        // 给每条边assign不同的颜色
        Map<String, Integer> colors = new HashMap<>();
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0, -1, -1});
        while (!queue.isEmpty()) {
            int[] poll = queue.poll();
            int currentNode = poll[0];
            int usedColor = poll[1];
            int parentNode = poll[2];
            int color = 1;
            for (int childNode : edges[currentNode]) {
                if (childNode == parentNode) {
                    continue;
                }
                if (color == usedColor) {
                    color++;
                }
                colors.put(currentNode + "-" + childNode, color);
                queue.add(new int[]{childNode, color, currentNode});
                color++;
            }
        }

        // 输出每条边的颜色
        int maxDegree = 0;
        for (int i = 0; i < n; i++) {
            maxDegree = Math.max(maxDegree, edges[i].size());
        }
        System.out.println(maxDegree);
        for (int i = 0; i < n - 1; i++) {
            System.out.println(colors.get(Math.min(ab[i][0], ab[i][1]) + "-" + Math.max(ab[i][0], ab[i][1])));
        }
    }
}

