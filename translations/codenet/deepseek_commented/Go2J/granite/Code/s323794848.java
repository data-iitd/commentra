
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
                String[] input = br.readLine().split(" ");
                front[i - 1] = Integer.parseInt(input[0]) == 1;
                c[i - 1] = input[1].charAt(0);
            }
            sum[i - 1] = sum[i] + (rev[i - 1]? 1 : 0);
        }
        if (sum[0] % 2 == 1) {
            S = new StringBuilder(S).reverse().toString();
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < Q; i++) {
            if (!rev[i]) { // Not a reversal operation (string append)
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
        for (int i = 0; i < Q; i++) {
            if (rev[i]) {
                if (sum[i] % 2 == 1) {
                    sb.append(c[i]);
                } else {
                    sb.insert(0, c[i]);
                }
            }
        }
        bw.write(sb.toString());
        bw.newLine();
        bw.flush();
    }
}

