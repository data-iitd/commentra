import java.util.*;
import java.io.*;

public class ProblemB {
    static final int constMod = (int) (1e9 + 7);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] a = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int sum = 0;
        for (int v : a) {
            sum += v;
        }

        int count = 0;
        for (int v : a) {
            double rate = (double) sum / (4 * m);
            if ((double) v >= rate) {
                count++;
            }
        }

        if (count >= m) {
            pw.println("Yes");
        } else {
            pw.println("No");
        }

        pw.flush();
    }
}
