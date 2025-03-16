

import java.util.*;
import java.io.*;

class atcoder_ABC151_A {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        String c = input[0];
        System.out.println(solve(c));
    }

    public static String solve(String c) {
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        int index = alphabet.indexOf(c);
        return alphabet.charAt(index + 1) + "";
    }
}

Translate the above Python code to C++ and end with comment "