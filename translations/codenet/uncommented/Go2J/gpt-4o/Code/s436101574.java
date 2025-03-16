import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();
        String t = br.readLine();

        List<String> ans = new ArrayList<>();
        for (int i = 0; i <= s.length() - t.length(); i++) {
            boolean f = true;
            char[] ss = s.toCharArray();

            for (int j = 0; j < t.length(); j++) {
                if (s.charAt(i + j) != t.charAt(j) && s.charAt(i + j) != '?') {
                    f = false;
                    break;
                } else {
                    ss[i + j] = t.charAt(j);
                }
            }
            if (f) {
                String result = new String(ss).replace("?", "a");
                ans.add(result);
            }
        }
        Collections.sort(ans);
        if (ans.isEmpty()) {
            bw.write("UNRESTORABLE\n");
        } else {
            bw.write(ans.get(0) + "\n");
        }
        bw.flush();
    }
}
