
import java.util.*;
import java.io.*;

public class s984540390{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        long h = Long.parseLong(br.readLine());
        long ans = 0;
        long cnt = 1;
        while (h!= 1) {
            if (h % 2!= 0) h--;
            h /= 2;
            cnt *= 2;
            ans += cnt;
        }
        bw.write(String.valueOf(ans + 1));
        bw.newLine();
        bw.flush();
    }
}

