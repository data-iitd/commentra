
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        System.out.println(walkOnMultiplicationTable(a));
    }

    public static int walkOnMultiplicationTable(int num) {

        int div = 0;
        for (int i = (int) Math.sqrt(num); i > 1; i--) {
            if (num % i == 0) {
                div = i;
                break;
            }
        }
        if (div == 0) {
            return num - 1;
        }
        return div + num / div - 2;

    }
}

