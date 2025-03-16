
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class s228769347{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));

        int n = Integer.parseInt(br.readLine());
        int[] ll = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            ll[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(ll);

        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int l = j + 1, r = n;
                while (l < r) {
                    int m = (l + r) / 2;
                    if (ll[m] < ll[i] + ll[j]) {
                        l = m + 1;
                    } else {
                        r = m;
                    }
                }
                ans += l - (j + 1);
            }
        }

        bw.write(String.valueOf(ans));
        bw.close();
    }
}

