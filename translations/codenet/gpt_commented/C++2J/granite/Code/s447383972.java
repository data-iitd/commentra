
import java.util.*;
import java.io.*;

public class s447383972{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = Long.parseLong(input[i]);
        }

        Arrays.sort(a);

        long[] q = new long[n];
        int tot = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                q[tot++] = a[i];
                i++;
            }
        }

        bw.write(String.valueOf(q[tot - 1] * q[tot - 2]));
        bw.newLine();
        bw.close();
    }
}

