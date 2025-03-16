
import java.util.*;
import java.io.*;

class atcoder_ABC151_A {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] c = br.readLine().split(" ");
        String result = solve(c[0]);
        System.out.println(result);
    }

    public static String solve(String c) {
        String a = "abcdefghijklmnopqrstuvwxyz";
        int i = a.indexOf(c);
        return a.substring(i + 1, i + 2);
    }
}

Translate the above Python code to C++ and end with comment "