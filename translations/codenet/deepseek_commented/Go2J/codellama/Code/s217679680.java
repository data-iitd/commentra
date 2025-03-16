
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] arr = scanArrayInt(scanner);
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

    public static int[] scanArrayInt(Scanner scanner) {
        String[] arr = scanner.nextLine().split(" ");
        int[] ret = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            ret[i] = Integer.parseInt(arr[i]);
        }
        return ret;
    }
}

