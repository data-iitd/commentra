import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

        int n = Integer.parseInt(tokenizer.nextToken());
        int[] aa = new int[n];
        tokenizer = new StringTokenizer(reader.readLine());

        for (int i = 0; i < n; i++) {
            aa[i] = Integer.parseInt(tokenizer.nextToken());
        }

        int[] cumsum = cumulativeSum(aa);

        int ans = Integer.MAX_VALUE;
        for (int i = 1; i < cumsum.length - 1; i++) {
            ans = Math.min(ans, Math.abs(cumsum[cumsum.length - 1] - cumsum[i] - (cumsum[i] - cumsum[0])));
        }

        writer.println(ans);
        writer.flush();
    }

    private static int[] cumulativeSum(int[] nums) {
        int[] sums = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return sums;
    }

    private static int abs(int a) {
        return a >= 0 ? a : -a;
    }

    private static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }
}
