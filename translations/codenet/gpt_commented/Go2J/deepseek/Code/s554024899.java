import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

        int x = Integer.parseInt(tokenizer.nextToken());
        int y = Integer.parseInt(tokenizer.nextToken());

        int xt = -1, yt = -1;

        int[][] a = {
            {1, 3, 5, 7, 8, 10, 12},
            {4, 6, 9, 11},
            {2}
        };

        for (int i = 0; i < a.length; i++) {
            for (int n : a[i]) {
                if (x == n) {
                    xt = i;
                }
                if (y == n) {
                    yt = i;
                }
            }
        }

        if (xt == yt) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

