
import java.util.*;
import java.io.*;

public class s447383972{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(str[i]);
        }
        Arrays.sort(a);
        int[] q = new int[n];
        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || a[i]!= a[i + 1]) {
                q[tot++] = a[i];
            }
        }
        bw.write(q[tot - 1] + " " + q[tot - 2] + "\n");
        bw.flush();
    }
}

