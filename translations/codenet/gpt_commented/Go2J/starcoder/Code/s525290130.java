import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            int q = sc.nextInt();
            for (int i = 0; i < q; i++) {
                int b = sc.nextInt();
                int e = sc.nextInt();
                for (int j = 0; j < (e - b) / 2; j++) {
                    int t = a[b + j];
                    a[b + j] = a[e - 1 - j];
                    a[e - 1 - j] = t;
                }
            }
            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    System.out.print(" ");
                }
                System.out.print(a[i]);
            }
            System.out.println();
        }
    }
}

