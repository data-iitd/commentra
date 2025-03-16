
package main;

import java.util.Scanner;

public class Main {

    static int n, m;
    static int[][] e;

    // Function to print the edges of the graph in a readable format
    static void printEdge(int[][] e) {
        for (int i = 1; i < n + 1; i++) {
            System.out.print(i + ": ");
            for (int j = 0; j < e[i].length; j++) {
                System.out.print(e[i][j] + " ");
            }
            System.out.println();
        }
    }

    // Depth-First Search (DFS) function to count connected components in the graph
    static int dfs(int v, boolean[] visited) {
        // Mark the current node as visited
        // System.out.println(v + " " + visited);

        // Check if all nodes are visited
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
            // if (cmp, _ := dfs(e[v][i], visited, count); cmp) {
            // 	count++;
            // }
            int rst = dfs(e[v][i], visited);
            // System.out.println(rst);
            // count += dfs(e[v][i], visited);
            count += rst;
            visited[e[v][i]] = false;
        }
        return count;
    }

    // Main function to read input, initialize the graph, and perform DFS
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        // Initialize the graph edges
        e = new int[n + 1][];
        for (int i = 1; i < n + 1; i++) {
            e[i] = new int[0];
        }

        // Read the edges and populate the graph
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            e[a] = append(e[a], b);
            e[b] = append(e[b], a);
        }
        // printEdge(e);

        // Initialize visited slice and start DFS from node 1
        boolean[] visited = new boolean[n + 1];
        visited[1] = true;
        int count = dfs(1, visited);
        System.out.println(count);
    }

    // Function to append an element to an array
    static int[] append(int[] arr, int element) {
        int[] newArr = new int[arr.length + 1];
        for (int i = 0; i < arr.length; i++) {
            newArr[i] = arr[i];
        }
        newArr[arr.length] = element;
        return newArr;
    }
}

