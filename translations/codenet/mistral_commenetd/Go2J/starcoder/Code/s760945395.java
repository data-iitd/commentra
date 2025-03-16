
package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a;
        for (int i = 0; i < 5; i++) {
            a = input.nextInt();
            if (a == 0) {
                System.out.println(i + 1);
            }
        }
    }
}

