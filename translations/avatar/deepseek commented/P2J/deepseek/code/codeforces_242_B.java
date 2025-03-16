import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());

        int id = 0;
        int l = 0, r = 0;
        String[] interval = reader.readLine().split(" ");
        l = Integer.parseInt(interval[0]);
        r = Integer.parseInt(interval[1]);

        for (int i = 1; i < n; i++) {
            String[] intervals = reader.readLine().split(" ");
            int li = Integer.parseInt(intervals[0]);
            int ri = Integer.parseInt(intervals[1]);

            if (li <= l && r <= ri) {
                id = i;
            } else if (li < l || r < ri) {
                id = n;
            }

            l = Math.min(l, li);
            r = Math.max(r, ri);
        }

        System.out.println(id == n ? -1 : id + 1);
    }
}

