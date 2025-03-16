
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class s998080221{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int _ = Integer.parseInt(st.nextToken());
        int[] A = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        int maxProfit = 0;
        int maxCnt = 0;
        int maxA = A[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            int profit = Math.max(0, maxA - A[i]);
            if (maxProfit < profit) {
                maxProfit = profit;
                maxCnt = 1;
            } else if (maxProfit == profit) {
                maxCnt++;
            }
            maxA = Math.max(maxA, A[i]);
        }
        out.println(maxCnt);
        out.flush();
    }
}

