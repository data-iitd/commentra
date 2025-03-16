
import java.util.*;
import java.io.*;

class atcoder_ABC142_A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int t = 0;
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 2 == 1) {
                t += 1;
            }
        }
        System.out.println((double)t / n);
    }
}

Translate the above Python code to C++ and end with comment "