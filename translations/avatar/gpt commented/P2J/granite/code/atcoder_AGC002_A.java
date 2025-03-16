
import java.util.*;
import java.io.*;

class atcoder_AGC002_A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] ab = br.readLine().split(" ");
        int a = Integer.parseInt(ab[0]);
        int b = Integer.parseInt(ab[1]);
        if (a > 0) {
            bw.write("Positive");
        } else if (a <= 0 && b >= 0) {
            bw.write("Zero");
        } else {
            if ((a + b) % 2 == 0) {
                bw.write("Negative");
            } else {
                bw.write("Positive");
            }
        }
        bw.newLine();
        bw.close();
    }
}
