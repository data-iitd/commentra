import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = Integer.parseInt(input[i]);
        }

        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            xs[i] = as[i] - i + 1;
        }
        Arrays.sort(xs);

        int b = xs[n / 2];
        int ans = 0;
        for (int x : xs) {
            ans += Math.abs(x - b);
        }
        pw.println(ans);
        pw.flush();
    }
}
