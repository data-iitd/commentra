
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int[] aa = new int[n];
        for (int i = 0; i < n; i++) {
            aa[i] = Integer.parseInt(tokenizer.nextToken());
        }
        int[] cumsum = cumsum(aa);
        int ans = 2020202020;
        for (int i = 1; i < cumsum.length - 1; i++) {
            ans = Math.min(ans, Math.abs(cumsum[cumsum.length - 1] - cumsum[i] - (cumsum[i] - cumsum[0])));
        }
        System.out.println(ans);
    }

    public static int[] cumsum(int[] nums) {
        int[] sums = new int[nums.length + 1];
        sums[0] = 0;
        for (int i = 0; i < nums.length; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return sums;
    }

    public static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int i = 0; i < nums.length; i++) {
            res = Math.min(res, nums[i]);
        }
        return res;
    }

    public static int abs(int a) {
        if (a >= 0) {
            return a;
        } else {
            return -a;
        }
    }
}

