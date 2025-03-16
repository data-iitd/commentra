import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        String[] sArray = reader.readLine().split(" ");
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = Integer.parseInt(sArray[i]);
        }
        boolean[] u = new boolean[n];
        long m = 0, f = 0;
        for (int c = 1; c < n - 1; c++) {
            f = 0;
            for (int k = 0; k * c < n - 1; k++) {
                u[k * c] = true;
                if (u[n - 1 - k * c]) break;
                f += s[n - 1 - k * c] + s[k * c];
                if (m < f) m = f;
            }
            Arrays.fill(u, false);
        }
        System.out.println(m);
    }
}

