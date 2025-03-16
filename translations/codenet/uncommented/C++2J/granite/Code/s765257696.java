
import java.util.*;
import java.io.*;

public class s765257696{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] p_str = br.readLine().split(" ");
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = Integer.parseInt(p_str[i]);
        }

        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (p[i] > p[i+1] && p[i+1] > p[i+2]) ans++;
            if (p[i] < p[i+1] && p[i+1] < p[i+2]) ans++;
        }

        System.out.println(ans);
    }
}

