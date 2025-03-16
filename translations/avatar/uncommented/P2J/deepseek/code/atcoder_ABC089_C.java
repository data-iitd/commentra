import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = br.readLine();
        }
        
        int[] march = new int[5];
        String marchStr = "MARCH";
        
        for (String s : S) {
            char firstChar = s.charAt(0);
            if (marchStr.indexOf(firstChar) != -1) {
                march[marchStr.indexOf(firstChar)]++;
            }
        }
        
        long ans = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {
                    ans += (long) march[i] * march[j] * march[k];
                }
            }
        }
        
        System.out.println(ans);
    }
}
