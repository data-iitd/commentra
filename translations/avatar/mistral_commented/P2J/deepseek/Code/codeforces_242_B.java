import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        int id = 0;
        String[] firstLine = reader.readLine().split(" ");
        int l = Integer.parseInt(firstLine[0]);
        int r = Integer.parseInt(firstLine[1]);

        for (int i = 1; i < n; i++) {
            String[] currentLine = reader.readLine().split(" ");
            int li = Integer.parseInt(currentLine[0]);
            int ri = Integer.parseInt(currentLine[1]);

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

