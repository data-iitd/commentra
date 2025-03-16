
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter wr = new PrintWriter(System.out);

        int n = sc.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
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
        wr.println(ans);

        sc.close();
        wr.close();
    }
}

