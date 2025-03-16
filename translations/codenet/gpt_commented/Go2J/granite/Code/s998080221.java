
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class s998080221{
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = reader.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int _ = Integer.parseInt(input[1]);

        int[] A = new int[N];
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(tokenizer.nextToken());
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

        writer.write(Integer.toString(maxCnt));
        writer.newLine();
        writer.flush();
    }
}

// 