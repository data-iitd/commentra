
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class s436101574{
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();

        List<String> ans = new ArrayList<>();
        for (int i = 0; i < s.length - t.length + 1; i++) {
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
            wr.write("UNRESTORABLE");
        } else {
            wr.write(ans.get(0));
        }
        wr.flush();
    }
}

