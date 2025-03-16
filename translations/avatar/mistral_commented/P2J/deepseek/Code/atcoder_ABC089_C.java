import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        int N = Integer.parseInt(br.readLine().trim());
        String[][] S = new String[N][];
        for (int i = 0; i < N; i++) {
            S[i] = br.readLine().trim().split(" ");
        }
        
        String[] march = {"M", "A", "R", "C", "H"};
        int[] march_lis = new int[5];
        long ans = 0;
        
        for (String[] s : S) {
            for (int i = 0; i < march.length; i++) {
                if (s[0].toUpperCase().equals(march[i])) {
                    march_lis[i]++;
                    break;
                }
            }
        }
        
        for (int x = 0; x < march_lis.length; x++) {
            for (int y = x + 1; y < march_lis.length; y++) {
                for (int z = y + 1; z < march_lis.length; z++) {
                    ans += (long) march_lis[x] * march_lis[y] * march_lis[z];
                }
            }
        }
        
        out.println(ans);
        out.flush();
    }
}

