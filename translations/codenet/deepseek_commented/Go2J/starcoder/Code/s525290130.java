import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            int n = Integer.parseInt(br.readLine());
            int[] a = new int[n];
            String[] s = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(s[i]);
            }
            int q = Integer.parseInt(br.readLine());
            for (int i = 0; i < q; i++) {
                int b = Integer.parseInt(br.readLine());
                int e = Integer.parseInt(br.readLine());
                for (int j = 0; j < (e - b) / 2; j++) {
                    int temp = a[b + j];
                    a[b + j] = a[e - 1 - j];
                    a[e - 1 - j] = temp;
                }
            }
            for (int i = 0; i < n; i++) {
                if (i > 0) bw.write(" ");
                bw.write(a[i]);
            }
            bw.write("\n");
            bw.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

