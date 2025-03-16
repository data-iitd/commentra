
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
        int[] front = new int[Q];
        int[] back = new int[Q];
        int[] c = new int[Q];
        int[] f = new int[Q];
        int[] rev = new int[Q];
        int frontCount = 0;
        int backCount = 0;

        for (int i = Q - 1; i >= 1; i--) {
            int q = Integer.parseInt(br.readLine());
            if (q == 1) {
                rev[i - 1] = 1;
                sum[i - 1] = sum[i] + 1;
            } else {
                String[] input = br.readLine().split(" ");
                f[i - 1] = Integer.parseInt(input[0]);
                c[i - 1] = input[1].charAt(0);
                if (f[i - 1] == 1) {
                    front[frontCount++] = i - 1;
                } else {
                    back[backCount++] = i - 1;
                }
                sum[i - 1] = sum[i];
            }
        }

        if (sum[0] % 2 == 1) {
            S = new StringBuilder(S).reverse().toString();
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < frontCount; i++) {
            int index = front[i];
            if (sum[index] % 2 == 1) {
                sb.append(c[index]);
            } else {
                sb.insert(0, c[index]);
            }
        }
        sb.append(S);
        for (int i = 0; i < backCount; i++) {
            int index = back[i];
            if (sum[index] % 2 == 1) {
                sb.insert(0, c[index]);
            } else {
                sb.append(c[index]);
            }
        }

        bw.write(sb.toString());
        bw.newLine();
        bw.flush();
    }
}
