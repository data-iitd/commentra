
import java.util.*;
import java.io.*;

public class s968402497{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int tc = Integer.parseInt(str[0]);
        int n = Integer.parseInt(str[1]);
        int m = Integer.parseInt(str[2]);
        if (n > m) {
            int temp = n;
            n = m;
            m = temp;
        }
        for (int i = 1; i <= m; i++) {
            if (i * tc >= n && i * tc <= m) {
                System.out.println("OK");
                return;
            }
        }
        System.out.println("NG");
    }
}

