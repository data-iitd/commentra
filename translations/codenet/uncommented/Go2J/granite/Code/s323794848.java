
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class s323794848{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String S = br.readLine();
        int Q = Integer.parseInt(br.readLine());
        int[] sum = new int[Q + 1];
        boolean[] rev = new boolean[Q];
        boolean[] front = new boolean[Q];
        char[] c = new char[Q];
        for (int i = Q - 1; i >= 1; i--) {
            int q = Integer.parseInt(br.readLine());
            if (q == 1) {
                rev[i - 1] = true;
            } else {
                String[] s = br.readLine().split(" ");
                front[i - 1] = Integer.parseInt(s[0]) == 1;
                c[i - 1] = s[1].charAt(0);
            }
            sum[i - 1] = sum[i] + (rev[i - 1]? 1 : 0);
        }
        if (sum[0] % 2 == 1) {
            S = new StringBuilder(S).reverse().toString();
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < Q; i++) {
            if (!rev[i]) { // 反転ではない(文字列追加)
                if (front[i]) {
                    if (sum[i] % 2 == 1) {
                        sb.append(c[i]);
                    } else {
                        sb.insert(0, c[i]);
                    }
                } else {
                    if (sum[i] % 2 == 1) {
                        sb.insert(0, c[i]);
                    } else {
                        sb.append(c[i]);
                    }
                }
            }
        }
        bw.write(sb.toString());
        bw.write(S);
        bw.newLine();
        bw.flush();
    }
}

