
import java.util.*;
import java.io.*;

public class atcoder_ABC174_C{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());
        int t = 0;
        for (int i = 1; i <= k; i++) {
            t = (t % k) * 10 + 7;
            if (t % k == 0) {
                System.out.println(i);
                break;
            }
        }
        if (t % k!= 0) {
            System.out.println(-1);
        }
    }
}

Translate the above Java code to C++ and end with comment "