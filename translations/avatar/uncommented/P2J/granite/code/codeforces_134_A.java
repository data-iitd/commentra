
import java.util.*;
import java.io.*;

class codeforces_134_A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] w_str = br.readLine().split(" ");
        int[] w = new int[n];
        int x = 0;
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(w_str[i]);
            x += w[i];
        }
        List<Integer> d = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if ((x - w[i]) / (n - 1) == w[i]) {
                d.add(i + 1);
            }
        }
        System.out.println(d.size());
        for (int i = 0; i < d.size(); i++) {
            System.out.print(d.get(i) + " ");
        }
        System.out.println();
    }
}
