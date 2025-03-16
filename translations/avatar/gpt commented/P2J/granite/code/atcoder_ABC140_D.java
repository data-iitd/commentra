
import java.util.*;
import java.io.*;

class atcoder_ABC140_D {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] inputs = br.readLine().split(" ");
        int N = Integer.parseInt(inputs[0]);
        int K = Integer.parseInt(inputs[1]);
        String S = br.readLine();
        int seg_cnt = 0;
        for (int i = 0; i < N - 1; i++) {
            if (S.charAt(i)!= S.charAt(i + 1)) {
                seg_cnt++;
            }
        }
        int cur_happy = N - 1 - seg_cnt;
        int ans = 0;
        if (2 * K >= seg_cnt) {
            ans = N - 1;
        } else {
            ans = cur_happy + 2 * K;
        }
        bw.write(String.valueOf(ans));
        bw.newLine();
        bw.close();
    }
}

Translate the above Java code to C++ and end with comment "