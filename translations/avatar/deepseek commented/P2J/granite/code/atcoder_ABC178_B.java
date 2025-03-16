
import java.util.*;
import java.io.*;

public class atcoder_ABC178_B{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);
        int c = Integer.parseInt(input[2]);
        int d = Integer.parseInt(input[3]);
        int max = Math.max(a * c, Math.max(b * d, Math.max(a * d, b * c)));
        System.out.println(max);
    }
}

Translate the above Python code to C++ and end with comment "