
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static final int MOD = 1000000007;

    private static int n, m;
    private static List<int[]> edges;

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            edges = new ArrayList<>();
            for (int i = 0; i < n - 1; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                x--;
                y--;
                edges.add(new int[] {x, y});
            }

            long[] res = new long[n];
            for (int i = 0; i < n; i++) {
                res[i] = 1;
            }
            for (int i = 0; i < n - 1; i++) {
                int[] edge = edges.get(i);
                int x = edge[0];
                int y = edge[1];
                res[x] = (res[x] * res[y]) % MOD;
            }
            for (int i = 0; i < n; i++) {
                System.out.println(res[i]);
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}

