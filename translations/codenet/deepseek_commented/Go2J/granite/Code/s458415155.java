
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class s458415155{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) {
            heights[i] = Integer.parseInt(input[i]);
        }
        int[] t = new int[n + 1];
        Arrays.fill(t, Integer.MAX_VALUE);
        t[0] = 0;
        for (int i = 1; i < n; i++) {
            int cost1 = t[i - 1] + Math.abs(heights[i] - heights[i - 1]);
            int cost2 = i >= 2? t[i - 2] + Math.abs(heights[i] - heights[i - 2]) : Integer.MAX_VALUE;
            t[i] = Math.min(cost1, cost2);
        }
        System.out.println(t[n - 1]);
    }
}
