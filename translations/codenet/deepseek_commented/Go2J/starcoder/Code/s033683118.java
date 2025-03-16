package main;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int k = sc.nextInt();
        int x = sc.nextInt();

        String ans = "No";
        if (k * 500 >= x) {
            ans = "Yes";
        }
        bw.write(ans);
        bw.newLine();

        bw.close();
        sc.close();
    }
}

