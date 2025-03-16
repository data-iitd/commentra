
import java.util.*;
import java.io.*;

public class codeforces_61_B{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] s = new String[3];
        for (int i = 0; i < 3; i++) {
            s[i] = br.readLine().replaceAll("-|_|;", "").toLowerCase();
        }
        List<String> list = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                for (int k = 0; k < 3; k++) {
                    if (i == k || j == k) continue;
                    list.add(s[i] + s[j] + s[k]);
                }
            }
        }
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String str = br.readLine().replaceAll("-|_|;", "").toLowerCase();
            if (list.contains(str)) {
                bw.write("ACC\n");
            } else {
                bw.write("WA\n");
            }
        }
        bw.flush();
    }
}

Translate the above Java code to C++ and end with comment "