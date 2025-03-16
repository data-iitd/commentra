import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader;
        if (args.length > 0) {
            reader = new BufferedReader(new FileReader(args[0]));
        } else {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(reader.readLine().trim());
        int[] aa = new int[n + 2];
        int sum = 0;

        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            aa[i + 1] = Integer.parseInt(tokenizer.nextToken());
            sum += absint(aa[i + 1] - aa[i]);
        }
        sum += absint(aa[n + 1] - aa[n]);

        for (int i = 1; i < n + 1; i++) {
            int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
            writer.write(ans + "\n");
        }

        writer.flush();
        writer.close();
        reader.close();
    }

    private static int absint(int a) {
        return a < 0 ? -a : a;
    }
}
// <END-OF-CODE>
