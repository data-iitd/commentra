
// Optimize input/output operations
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int n = Integer.parseInt(br.readLine());
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = Integer.parseInt(br.readLine());
        }

        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (p[i] > p[i + 1] && p[i + 1] > p[i + 2]) {
                ans++;
            }
            if (p[i] < p[i + 1] && p[i + 1] < p[i + 2]) {
                ans++;
            }
        }

        pw.println(ans);
        pw.flush();
        pw.close();
    }
}

