
//import java.util.*;
//import java.io.*;

class s458415155 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) {
            heights[i] = sc.nextInt();
        }
        int ans = solve(n, heights);
        System.out.println(ans);
    }

    static int solve(int n, int[] heights) {
        int[] t = new int[n+1];
        Arrays.fill(t, Integer.MAX_VALUE);
        t[0] = 0;
        for (int i = 1; i < n; i++) {
            int v = t[i-1] + Math.abs(heights[i]-heights[i-1]);
            if (v < t[i]) {
                t[i] = v;
            }
            if (1 < i) {
                int v2 = t[i-2] + Math.abs(heights[i]-heights[i-2]);
                if (v2 < t[i]) {
                    t[i] = v2;
                }
            }
        }
        return t[n-1];
    }
}

