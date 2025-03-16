import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        String s = br.readLine();
        String t = br.readLine();

        List<String> ans = new ArrayList<>();

        for (int i = 0; i <= s.length() - t.length(); i++) {
            char[] ss = s.toCharArray();
            boolean f = true;

            for (int j = 0; j < t.length(); j++) {
                if (ss[i + j] != t.charAt(j) && ss[i + j] != '?') {
                    f = false;
                    break;
                } else {
                    ss[i + j] = t.charAt(j);
                }
            }

            if (f) {
                ans.add(new String(ss).replace('?', 'a'));
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

