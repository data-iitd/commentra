package main;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] v = new int[N];
        int a;
        for (int i = 1; i < N; i++) {
            a = sc.nextInt();
            v[a - 1]++;
        }
        PrintWriter pw = new PrintWriter(System.out);
        for (int e : v) {
            pw.println(e);
        }
        pw.close();
    }
}

