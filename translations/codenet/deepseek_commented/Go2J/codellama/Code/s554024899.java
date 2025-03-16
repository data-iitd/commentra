
package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int[][] a = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
        int xt = 0;
        int yt = 0;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                if (x == a[i][j]) {
                    xt = i;
                }
                if (y == a[i][j]) {
                    yt = i;
                }
            }
        }
        if (xt == yt) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

