
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        System.out.println(min(n*a, b));
    }

    public static int min(int num1, int num2) {
        return Math.min(num1, num2);
    }
}

