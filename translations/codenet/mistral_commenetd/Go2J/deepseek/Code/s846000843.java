import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(reader.readLine());
        int[] aa = new int[n];
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            aa[i] = Integer.parseInt(tokenizer.nextToken());
        }
        int[] cumsum = cumSum(aa);
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i < cumsum.length - 1; i++) {
            int diff1 = Math.abs(cumsum[cumsum.length - 1] - cumsum[i]);
            int diff2 = cumsum[i] - cumsum[0];
            ans = Math.min(ans, Math.min(diff1, diff2));
        }
        writer.println(ans);
        writer.flush();
    }

    private static int[] cumSum(int[] nums) {
        int[] sums = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return sums;
    }
}
