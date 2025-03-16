
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class s953070177{
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        BufferedWriter writer = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(reader.readLine());

        int[] a = new int[n + 2];

        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 1; i <= n; i++) {
            a[i] = Integer.parseInt(tokenizer.nextToken());
        }

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += Math.abs(a[i] - a[i - 1]);
        }

        for (int i = 1; i <= n; i++) {
            int diff = sum - Math.abs(a[i] - a[i - 1]) - Math.abs(a[i + 1] - a[i]) + Math.abs(a[i + 1] - a[i - 1]);
            writer.write(String.valueOf(diff));
            writer.newLine();
        }

        writer.close();
        reader.close();
    }
}

