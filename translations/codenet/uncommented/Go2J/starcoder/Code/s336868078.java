package main;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(in.readLine());
        int b = Integer.parseInt(in.readLine());
        int c = Integer.parseInt(in.readLine());
        int ans = solve(a, b, c);
        System.out.println(ans);
    }

    public static int solve(int a, int b, int c) {
        int temp_ = 0;
        if (c == a + b) {
            temp_ = b + c;
        } else if (c - 1 > a + b) {
            int temp = (c - 1) - (a + b);
            temp_ = b + c - temp;
        } else {
            temp_ = b + c;
        }
        return temp_;
    }
}

