
import java.util.*;
import java.io.*;

class atcoder_AGC013_A {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if ((a[i - 1] < a[i] && a[i] > a[i + 1]) || (a[i - 1] > a[i] && a[i] < a[i + 1])) {
                ans++;
            }
        }
        System.out.println(ans + 1);
    }
}

