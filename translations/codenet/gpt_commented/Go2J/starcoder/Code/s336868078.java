package main;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        int result = solve(a, b, c);
        System.out.println(result);
    }

    public static int solve(int a, int b, int c) {
        int temp = 0;
        if (c == a + b) {
            temp = b + c;
        } else if (c - 1 > a + b) {
            int diff = (c - 1) - (a + b);
            temp = b + c - diff;
        } else {
            temp = b + c;
        }
        return temp;
    }
}

