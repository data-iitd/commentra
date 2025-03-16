
import java.util.*;
import java.io.*;

class codeforces_637_A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] s = br.readLine().split(" ");
        HashMap<String, Integer> w = new HashMap<>();
        for (String si : s) {
            w.put(si, w.getOrDefault(si, 0) + 1);
        }
        String[] srev = s.clone();
        Arrays.sort(srev);
        String a = "";
        int max = 0;
        for (int i = srev.length - 1; i >= 0; i--) {
            if (w.get(srev[i]) > max) {
                max = w.get(srev[i]);
                a = srev[i];
            }
        }
        System.out.println(a);
    }
}
