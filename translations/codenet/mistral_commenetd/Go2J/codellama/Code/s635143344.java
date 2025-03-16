
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] in = new int[3];
        for (int i = 0; i < in.length; i++) {
            in[i] = scanner.nextInt();
        }
        int[] sorted = in.clone();
        sort(sorted);
        int result = sorted[2] * 10 + sorted[1] + sorted[0];
        System.out.println(result);
    }

    public static void sort(int[] in) {
        for (int i = 0; i < in.length; i++) {
            for (int j = i + 1; j < in.length; j++) {
                if (in[i] > in[j]) {
                    int temp = in[i];
                    in[i] = in[j];
                    in[j] = temp;
                }
            }
        }
    }
}

