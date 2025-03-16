package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        String s = tenToN(N, K);
        System.out.println(s.length());
    }

    public static String tenToN(int number, int n) {
        String s = "";
        int tmp = number;
        while (true) {
            s = i2s(tmp % n) + s;
            if (tmp < n) {
                break;
            }
            tmp /= n;
        }
        return s;
    }

    public static String i2s(int i) {
        return String.valueOf(i);
    }
}

