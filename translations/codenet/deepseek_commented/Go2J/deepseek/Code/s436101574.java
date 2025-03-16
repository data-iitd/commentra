import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        char[] s = st.nextToken().toCharArray();
        char[] t = br.readLine().toCharArray();

        List<String> ans = new ArrayList<>();
        for (int i = 0; i <= s.length - t.length; i++) {
            boolean f = true;
            char[] ss = s.clone();

            for (int j = 0; j < t.length; j++) {
                if (s[i + j] != t[j] && s[i + j] != '?') {
                    f = false;
                    break;
                } else {
                    ss[i + j] = t[j];
                }
            }
            if (f) {
                ans.add(new String(ss).replace('?', 'a'));
            }
        }
        Collections.sort(ans);
        if (ans.isEmpty()) {
            pw.println("UNRESTORABLE");
        } else {
            pw.println(ans.get(0));
        }
        pw.flush();
    }
}
