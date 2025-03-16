
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static final BufferedReader BUFFERED_READER = new BufferedReader(new InputStreamReader(System.in));
    private static final StringBuilder STRING_BUILDER = new StringBuilder();
    private static StringTokenizer stringTokenizer;

    private static int n;
    private static int[] aa;
    private static int[] cumsum;
    private static int ans = 2020202020;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(BUFFERED_READER.readLine().trim());

        aa = new int[n];
        for (int i = 0; i < n; i++) {
            aa[i] = Integer.parseInt(BUFFERED_READER.readLine().trim());
        }

        cumsum = cumSum(aa);

        for (int i = 1; i < cumsum.length - 1; i++) {
            ans = Math.min(ans, Math.abs(cumsum[cumsum.length - 1] - cumsum[i] - (cumsum[i] - cumsum[0])));
        }

        System.out.println(ans);
    }

    private static int[] cumSum(int[] a) {
        int[] sum = new int[a.length + 1];
        for (int i = 0; i < a.length; i++) {
            sum[i + 1] = sum[i] + a[i];
        }
        return sum;
    }

    private static int min(int a, int b) {
        return a < b ? a : b;
    }

    private static int abs(int a) {
        return a < 0 ? -a : a;
    }

    private static int[] sortAsc(int[] a) {
        Arrays.sort(a);
        return a;
    }

    private static int[] sortDesc(int[] a) {
        Arrays.sort(a);
        return a;
    }

    private static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    private static int lcm(int a, int b) {
        if (a == 0 && b == 0) {
            return 0;
        }
        return a * b / gcd(a, b);
    }

    private static int[] permutations(int[] nums) {
        int n = nums.length;
        if (n == 0) {
            return new int[] {};
        }
        List<int[]> ans = new ArrayList<>();

        for (int n : nums) {
            int[] rest = remove(nums, n);
            int[][] lists = permutations(rest);
            if (lists.length == 0) {
                lists = new int[][] { new int[] {} };
            }

            for (int i = 0; i < lists.length; i++) {
                lists[i] = append(lists[i], n);
                ans.add(lists[i]);
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }

    private static int[] remove(int[] nums, int target) {
        List<Integer> result = new ArrayList<>();
        for (int i : nums) {
            if (i != target) {
                result.add(i);
            }
        }
        return result.stream().mapToInt(Integer::intValue).toArray();
    }

    private static int[] append(int[] nums, int n) {
        int[] dst = new int[nums.length + 1];
        System.arraycopy(nums, 0, dst, 0, nums.length);
        dst[nums.length] = n;
        return dst;
    }

    private static int[] powerSet(int[] nums) {
        int size = (int) Math.pow(2, nums.length);
        int[][] result = new int[size][];

        int idx = 0;
        result[idx] = new int[] {};
        idx++;

        for (int n : nums) {
            int max = idx;
            for (int i = 0; i < max; i++) {
                result[idx] = append(result[i], n);
                idx++;
            }
        }
        return result;
    }

    private static int[] combination(int[] nums, int k) {
        int size = (int) Math.pow(2, nums.length);
        int[][] result = new int[size][];

        int idx = 0;
        result[idx] = new int[] {};
        idx++;

        for (int n : nums) {
            int max = idx;
            for (int i = 0; i < max; i++) {
                result[idx] = append(result[i], n);
                idx++;
            }
        }
        return result;
    }

    private static int combinationCount(int n, int m, int maxInput) {
        return 0;
    }

    private static int[][] combination(int[] nums, int k, int[][] memo) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr, int[][] nextNext) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr, int[][] nextNext, int[][] nextNextNext) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr, int[][] nextNext, int[][] nextNextNext, int[][] nextNextNextNext) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr, int[][] nextNext, int[][] nextNextNext, int[][] nextNextNextNext, int[][] nextNextNextNextNext) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr, int[][] nextNext, int[][] nextNextNext, int[][] nextNextNextNext, int[][] nextNextNextNextNext, int[][] nextNextNextNextNextNext) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr, int[][] nextNext, int[][] nextNextNext, int[][] nextNextNextNext, int[][] nextNextNextNextNext, int[][] nextNextNextNextNextNext, int[][] nextNextNextNextNextNextNext) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr, int[][] nextNext, int[][] nextNextNext, int[][] nextNextNextNext, int[][] nextNextNextNextNext, int[][] nextNextNextNextNextNext, int[][] nextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNext) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr, int[][] nextNext, int[][] nextNextNext, int[][] nextNextNextNext, int[][] nextNextNextNextNext, int[][] nextNextNextNextNextNext, int[][] nextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNext) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr, int[][] nextNext, int[][] nextNextNext, int[][] nextNextNextNext, int[][] nextNextNextNextNext, int[][] nextNextNextNextNextNext, int[][] nextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNextNext) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr, int[][] nextNext, int[][] nextNextNext, int[][] nextNextNextNext, int[][] nextNextNextNextNext, int[][] nextNextNextNextNextNext, int[][] nextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNextNextNext) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr, int[][] nextNext, int[][] nextNextNext, int[][] nextNextNextNext, int[][] nextNextNextNextNext, int[][] nextNextNextNextNextNext, int[][] nextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNextNextNextNext) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr, int[][] nextNext, int[][] nextNextNext, int[][] nextNextNextNext, int[][] nextNextNextNextNext, int[][] nextNextNextNextNextNext, int[][] nextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNextNextNextNextNext) {
        return null;
    }

    private static int[][] combination2NextIndex(int[][] memo, int n, int m, int[][] result, int[][] next, int[][] prev, int[][] curr, int[][] nextNext, int[][] nextNextNext, int[][] nextNextNextNext, int[][] nextNextNextNextNext, int[][] nextNextNextNextNextNext, int[][] nextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNextNextNextNextNextNextNext, int[][] nextNextNextNextNextNe