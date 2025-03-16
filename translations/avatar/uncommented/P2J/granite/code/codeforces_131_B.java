
import java.util.*;
import java.io.*;

class codeforces_131_B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] s = br.readLine().split(" ");
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(s[i]);
        }
        Arrays.sort(w);
        int count = 0;
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (w[i] + w[j] == 0) {
                count++;
                i++;
                j--;
            } else if (w[i] + w[j] < 0) {
                i++;
            } else {
                j--;
            }
        }
        System.out.println(count);
    }
}

