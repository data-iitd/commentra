
import java.util.*;
import java.io.*;

public class s436101574{
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter wr = new PrintWriter(System.out);

        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();

        List<String> ans = new ArrayList<>();
        for (int i = 0; i <= s.length - t.length; i++) {
            boolean f = true;
            char[] ss = s.clone();
            for (int j = 0; j < t.length; j++) {
                if (s[i + j]!= t[j] && s[i + j]!= '?') {
                    f = false;
                    break;
                } else {
                    ss[i + j] = t[j];
                }
            }
            if (f) {
                ans.add(new String(ss).replace("?", "a"));
            }
        }
        Collections.sort(ans);
        if (ans.isEmpty()) {
            wr.println("UNRESTORABLE");
        } else {
            wr.println(ans.get(0));
        }

        wr.close();
    }
}

