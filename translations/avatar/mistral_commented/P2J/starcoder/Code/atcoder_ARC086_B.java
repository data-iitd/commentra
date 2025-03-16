
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }
        int max_val = 0;
        int max_sign = 0;
        int max_index = -1;
        for (int i = 0; i < N; i++) {
            if (Math.abs(a[i]) > max_val) {
                max_val = Math.abs(a[i]);
                max_sign = my_sign(a[i]);
                max_index = i;
            }
        }
        if (max_sign == 0) {
            System.out.println(0);
        } else if (max_sign == 1) {
            System.out.println(2 * N - 1);
            System.out.println(max_index + 1, 1);
            for (int i = 1; i < N; i++) {
                System.out.println(i + 1, i + 2);
            }
        } else {
            System.out.println(2 * N - 1);
            System.out.println(max_index + 1, 1);
            for (int i = N - 1; i > 0; i--) {
                System.out.println(i + 1, i);
            }
        }
    }

    public static int my_sign(int a) {
        if (a > 0) {
            return 1;
        } else if (a < 0) {
            return -1;
        } else {
            return 0;
        }
    }
}

