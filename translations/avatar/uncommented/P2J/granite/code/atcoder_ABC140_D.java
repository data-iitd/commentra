
import java.util.*;
import java.io.*;

class atcoder_ABC140_D {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = br.readLine().split(" ");
        int N = Integer.parseInt(inputs[0]);
        int K = Integer.parseInt(inputs[1]);
        String S = br.readLine();
        int seg_cnt = 0;
        for (int i = 0; i < N - 1; i++) {
            if (S.charAt(i)!= S.charAt(i + 1)) {
                seg_cnt += 1;
            }
        }
        int cur_happy = N - 1 - seg_cnt;
        int ans = 0;
        if (2 * K >= seg_cnt) {
            ans = N - 1;
        } else {
            ans = cur_happy + 2 * K;
        }
        System.out.println(ans);
    }
}
