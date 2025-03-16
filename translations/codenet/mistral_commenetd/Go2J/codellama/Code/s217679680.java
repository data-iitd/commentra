
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] arr = new int[2];
        for (int i = 0; i < 2; i++) {
            arr[i] = scanner.nextInt();
        }
        int a = arr[0];
        int b = arr[1];
        int tap = 0;
        int consent = 1;
        while (consent < b) {
            consent = consent + a - 1;
            tap++;
        }
        System.out.println(tap);
    }
}

