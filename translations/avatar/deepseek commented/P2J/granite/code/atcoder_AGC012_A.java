
import java.util.*;
import java.io.*;

public class atcoder_AGC012_A{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        int[] A = new int[n * 2];
        for (int i = 0; i < n * 2; i++) {
            A[i] = Integer.parseInt(line[i]);
        }
        Arrays.sort(A);
        int ans = 0;
        for (int i = n * 2 - 2; i >= n; i -= 2) {
            ans += A[i];
        }
        System.out.println(ans);
    }
}

Translate the above Java code to C++ and end with comment "