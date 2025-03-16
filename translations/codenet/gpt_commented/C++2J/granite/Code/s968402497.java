
import java.util.*;
import java.io.*;

public class s968402497{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] input = br.readLine().split(" ");
        int tc = Integer.parseInt(input[0]);
        int n = Integer.parseInt(input[1]);
        int m = Integer.parseInt(input[2]);
        if (n > m) {
            int temp = n;
            n = m;
            m = temp;
        }
        boolean flag = false;
        for (int i = 1; i <= m; i++) {
            if (i * tc >= n && i * tc <= m) {
                bw.write("OK\n");
                flag = true;
                break;
            }
        }
        if (!flag) {
            bw.write("NG\n");
        }
        bw.flush();
    }
}

