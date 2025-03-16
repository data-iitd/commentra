import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        final long INF = (long) Math.pow(10, 11);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        
        long[] s = new long[A + 2];
        s[0] = -INF;
        s[A + 1] = INF;
        for (int i = 1; i <= A; i++) {
            s[i] = Long.parseLong(br.readLine());
        }
        
        long[] t = new long[B + 2];
        t[0] = -INF;
        t[B + 1] = INF;
        for (int i = 1; i <= B; i++) {
            t[i] = Long.parseLong(br.readLine());
        }
        
        for (int i = 0; i < Q; i++) {
            long x = Long.parseLong(br.readLine());
            int b = binarySearch(s, x);
            int d = binarySearch(t, x);
            long res = INF;
            
            for (long S : new long[]{s[b - 1], s[b]}) {
                for (long T : new long[]{t[d - 1], t[d]}) {
                    long d1 = Math.abs(S - x) + Math.abs(T - S);
                    long d2 = Math.abs(T - x) + Math.abs(S - T);
                    res = Math.min(res, Math.min(d1, d2));
                }
            }
            
            System.out.println(res);
        }
    }
    
    private static int binarySearch(long[] arr, long target) {
        int left = 0, right = arr.length - 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (arr[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }
}
