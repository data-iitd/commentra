
import java.io.*;
import java.util.*;

class s469969316 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine())!= null &&!line.equals(".")) {
            int cnt = 0;
            for (int p = 0; p < 3; p++) {
                for (int q = 0; q < 3; q++) {
                    for (int r = 0; r < 3; r++) {
                        String s = line.replace("P", String.valueOf(p)).replace("Q", String.valueOf(q)).replace("R", String.valueOf(r));
                        int i = 0;
                        char c = s.charAt(i);
                        if (c == '-' || c == '*' || ('0' <= c && c <= '2')) {
                            cnt++;
                        }
                    }
                }
            }
            System.out.println(cnt);
        }
    }
}

