package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] a = new int[3];
        for (int i = 0; i < 3; i++) {
            a[i] = in.nextInt();
        }
        int five = 0;
        int seven = 0;
        for (int i = 0; i < 3; i++) {
            if (a[i] == 5) {
                five++;
            }
            if (a[i] == 7) {
                seven++;
            }
        }
        if (five == 2 && seven == 1) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}

