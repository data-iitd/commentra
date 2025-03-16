
package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        int x = N % K;
        x = Math.min(Math.abs(x - K), x);
        System.out.println(x);
    }
}

