
/*
URL_HERE
*/
/*

*/
import java.io.*;
import java.util.*;

public class s976558978{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] inputs = br.readLine().split(" ");
        int a = Integer.parseInt(inputs[0]);
        int b = Integer.parseInt(inputs[1]);
        if (a < b) {
            for (int i = 0; i < b; i++) {
                bw.write(a + " ");
            }
        } else {
            for (int i = 0; i < a; i++) {
                bw.write(b + " ");
            }
        }
        bw.newLine();
        bw.flush();
    }
}

