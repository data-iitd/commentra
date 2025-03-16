

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
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out))) {
            String s = reader.readLine();
            String t = reader.readLine();
            List<String> ans = new ArrayList<>();
            for (int i = 0; i <= s.length() - t.length(); i++) {
                boolean f = true;
                StringBuilder sb = new StringBuilder(s);
                for (int j = 0; j < t.length(); j++) {
                    if (sb.charAt(i + j)!= '?' && sb.charAt(i + j)!= t.charAt(j)) {
                        f = false;
                        break;
                    }
                    sb.setCharAt(i + j, t.charAt(j));
                }
                if (f) {
                    ans.add(sb.toString().replace("?", "a"));
                }
            }
            Collections.sort(ans);
            if (ans.isEmpty()) {
                writer.write("UNRESTORABLE");
            } else {
                writer.write(ans.get(0));
            }
        }
    }
}

