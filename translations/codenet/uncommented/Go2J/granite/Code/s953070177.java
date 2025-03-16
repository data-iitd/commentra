
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class s953070177{

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(reader.readLine());

        int[] aa = new int[n + 2];
        int sum = 0;
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            aa[i + 1] = Integer.parseInt(tokenizer.nextToken());
            sum += Math.abs(aa[i + 1] - aa[i]);
        }
        sum += Math.abs(aa[n + 1] - aa[n]);

        for (int i = 1; i < n + 1; i++) {
            int ans = sum - Math.abs(aa[i + 1] - aa[i]) - Math.abs(aa[i] - aa[i - 1]) + Math.abs(aa[i + 1] - aa[i - 1]);
            writer.write(String.valueOf(ans));
            writer.newLine();
        }

        writer.flush();
    }
}

Translate the above Java code to C++ and end with comment "