
import java.util.*;
import java.io.*;

class atcoder_ABC122_D {
    static int mod = 100000007;
    static int n;
    static HashMap<String, HashMap<String, Integer>> memo = new HashMap<>();

    static boolean ok(String last4) {
        for (int i = 0; i < 4; i++) {
            char[] t = last4.toCharArray();
            if (i >= 1) {
                char tmp = t[i];
                t[i] = t[i - 1];
                t[i - 1] = tmp;
            }
            if (new String(t).contains("AGC")) {
                return false;
            }
        }
        return true;
    }

    static int dfs(int cur, String last3) {
        if (memo.containsKey(cur) && memo.get(cur).containsKey(last3)) {
            return memo.get(cur).get(last3);
        }
        if (cur == n) {
            return 1;
        }
        int ret = 0;
        for (char c : "ACGT".toCharArray()) {
            if (ok(last3 + c)) {
                ret = (ret + dfs(cur + 1, last3.substring(1) + c)) % mod;
            }
        }
        if (!memo.containsKey(cur)) {
            memo.put(cur, new HashMap<>());
        }
        memo.get(cur).put(last3, ret);
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        System.out.println(dfs(0, "TTT"));
    }
}
