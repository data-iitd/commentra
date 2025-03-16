import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        String[] S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = br.readLine().trim();
        }

        String[] march = {"M", "A", "R", "C", "H"};
        int[] marchCount = new int[5];

        for (String s : S) {
            char firstChar = Character.toUpperCase(s.charAt(0));
            for (int j = 0; j < march.length; j++) {
                if (firstChar == march[j].charAt(0)) {
                    marchCount[j]++;
                    break;
                }
            }
        }

        long ans = 0;
        for (int x = 0; x < 5; x++) {
            for (int y = x + 1; y < 5; y++) {
                for (int z = y + 1; z < 5; z++) {
                    ans += (long) marchCount[x] * marchCount[y] * marchCount[z];
                }
            }
        }

        System.out.println(ans);
    }
}
//<END-OF-CODE>
