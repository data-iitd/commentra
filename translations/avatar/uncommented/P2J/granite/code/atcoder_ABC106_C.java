
import java.util.*;
import java.io.*;

class atcoder_ABC106_C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int k = Integer.parseInt(br.readLine());
        int l = 0;
        for (char c : s.toCharArray()) {
            if (c!= '1') {
                break;
            }
            l++;
        }
        if (l >= k) {
            System.out.println(1);
        } else {
            System.out.println(s.charAt(l));
        }
    }
}
