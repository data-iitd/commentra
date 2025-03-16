
import java.io.*;
import java.util.*;

public class atcoder_ABC089_C{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = br.readLine();
        }
        int[] march = new int[5];
        for (int i = 0; i < n; i++) {
            char c = s[i].charAt(0);
            if (c == 'M') march[0]++;
            else if (c == 'A') march[1]++;
            else if (c == 'R') march[2]++;
            else if (c == 'C') march[3]++;
            else if (c == 'H') march[4]++;
        }
        long ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                for (int k = j + 1; k < 5; k++) {
                    ans += (long) march[i] * march[j] * march[k];
                }
            }
        }
        System.out.println(ans);
    }
}

Translate the above Java code to C++ and end with comment "