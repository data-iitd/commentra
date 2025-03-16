package main

import java.util.Scanner;

public class Main {
    static int n, m;
    static int[][] e;

    public static void printEdge(int[][] e) {
        for (int i = 1; i < n + 1; i++) {
            System.out.print(i + ": ");
            for (int j = 0; j < e[i].length; j++) {
                System.out.print(e[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static int dfs(int v, boolean[] visited) {
        // visited[v] = true
        // System.out.println(v + " " + visited);

        boolean comp = true;
        for (int i = 1; i < n + 1; i++) {
            if (!visited[i]) {
                comp = false;
            }
        }

        if (comp) {
            return 1;
        }

        int count = 0;
        for (int i = 0; i < e[v].length; i++) {
            // System.out.println("ne=" + e[v][i]);
            if (visited[e[v][i]]) {
                continue;
            }
            visited[e[v][i]] = true;
            // if (cmp, _ := dfs(ne, visited, count); cmp) {
            // 	count++
            // }
            int rst = dfs(e[v][i], visited);
            // System.out.println(rst);
            // count += dfs(ne, visited)
            count += rst;
            visited[e[v][i]] = false;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        e = new int[n + 1][];
        for (int i = 1; i < n + 1; i++) {
            e[i] = new int[0];
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            a = sc.nextInt();
            b = sc.nextInt();
            e[a] = append(e[a], b);
            e[b] = append(e[b], a);
        }
        // printEdge(e);

        boolean[] visited = new boolean[n + 1];
        visited[1] = true;
        int count = dfs(1, visited);
        System.out.println(count);
    }

    public static int[] append(int[] arr, int v) {
        int[] newArr = new int[arr.length + 1];
        for (int i = 0; i < arr.length; i++) {
            newArr[i] = arr[i];
        }
        newArr[arr.length] = v;
        return newArr;
    }
}

