import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;

        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]);
            if (args.length > 1) {
                outputStream = new FileOutputStream(args[1]);
            }
        }

        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(outputStream));

        int n = Integer.parseInt(reader.readLine());
        int[] ll = new int[n];

        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            ll[i] = Integer.parseInt(tokenizer.nextToken());
        }

        Arrays.sort(ll);

        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int l = j + 1;
                int r = n;
                while (l < r) {
                    int m = (l + r) >> 1;
                    if (ll[m] < ll[i] + ll[j]) {
                        l = m + 1;
                    } else {
                        r = m;
                    }
                }
                ans += l - (j + 1);
            }
        }
        writer.write(String.valueOf(ans));
        writer.newLine();

        writer.flush();
        writer.close();
        reader.close();
    }
}
// <END-OF-CODE>
