import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int j = 0; j < n; j++) {
                arr[j] = sc.nextInt();
            }
            int count = 0;
            for (int j = 1; j <= 12; j++) {
                if (n % j == 0) {
                    if (help(j, n / j, arr)) {
                        count++;
                    }
                }
            }
            System.out.print(count + " ");
            for (int j = 1; j <= 12; j++) {
                if (n % j == 0) {
                    if (help(j, n / j, arr)) {
                        System.out.print(j + "x" + (n / j) + " ");
                    }
                }
            }
            System.out.println();
        }
    }

    public static boolean help(int a, int b, int[] arr) {
        int[][] tot = new int[b][a];
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j++) {
                tot[i][j] = arr[i * a + j];
            }
        }
        for (int i = 0; i < b; i++) {
            int sum = 0;
            for (int j = 0; j < a; j++) {
                sum += tot[i][j];
            }
            if (sum == b) {
                return true;
            }
        }
        for (int i = 0; i < a; i++) {
            int sum = 0;
            for (int j = 0; j < b; j++) {
                sum += tot[j][i];
            }
            if (sum == b) {
                return true;
            }
        }
        return false;
    }
}

