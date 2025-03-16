import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
        
        int n = Integer.parseInt(br.readLine());
        int[] as = new int[n];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            as[i] = Integer.parseInt(input[i]);
        }

        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            xs[i] = as[i] - i + 1;
        }
        Arrays.sort(xs);

        int b = xs[n / 2];
        long ans = 0;
        for (int x : xs) {
            ans += Math.abs(x - b);
        }
        wr.println(ans);
        wr.flush();
    }
}
// <END-OF-CODE>
