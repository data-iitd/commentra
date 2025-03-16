
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class s168401731{
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(reader.readLine());

        String ans = "second";
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(reader.readLine());
            if (a % 2 == 1) {
                ans = "first";
                break;
            }
        }
        writer.write(ans);
        writer.newLine();
        writer.flush();
    }
}

