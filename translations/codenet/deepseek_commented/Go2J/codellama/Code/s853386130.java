
package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(reader.readLine());
        int m = Integer.parseInt(reader.readLine());
        int R = Integer.parseInt(reader.readLine());

        int[] rs = new int[R];
        for (int i = 0; i < R; i++) {
            rs[i] = Integer.parseInt(reader.readLine());
        }

        int[][] costs = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(costs[i], Integer.MAX_VALUE);
            costs[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            String[] line = reader.readLine().split(" ");
            int a = Integer.parseInt(line[0]);
            int b = Integer.parseInt(line[1]);
            int c = Integer.parseInt(line[2]);
            costs[a - 1][b - 1] = c;
            costs[b - 1][a - 1] = c;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    costs[i][j] = Math.min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }

        List<List<Integer>> perms = permutations(rs);
        int ans = Integer.MAX_VALUE;
        for (List<Integer> perm : perms) {
            int tmp = 0;
            for (int j = 1; j < perm.size(); j++) {
                int from = perm.get(j - 1);
                int to = perm.get(j);
                tmp += costs[from][to];
            }
            ans = Math.min(ans, tmp);
        }
        System.out.println(ans);
    }

    private static List<List<Integer>> permutations(int[] arr) {
        List<List<Integer>> res = new ArrayList<>();

        permutations(arr, 0, arr.length, res);

        return res;
    }

    private static void permutations(int[] arr, int index, int n, List<List<Integer>> res) {
        if (index == n) {
            List<Integer> tmp = new ArrayList<>();
            for (int i : arr) {
                tmp.add(i);
            }
            res.add(tmp);
        } else {
            for (int i = index; i < n; i++) {
                swap(arr, index, i);
                permutations(arr, index + 1, n, res);
                swap(arr, index, i);
            }
        }
    }

    private static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

