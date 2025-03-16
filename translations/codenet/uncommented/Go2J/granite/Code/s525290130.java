
import java.util.*;
import java.io.*;

class s525290130 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int b = sc.nextInt();
            int e = sc.nextInt();
            reverse(a, b, e);
        }
        PrintWriter wtr = new PrintWriter(System.out);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                wtr.print(" ");
            }
            wtr.print(a[i]);
        }
        wtr.println();
        wtr.flush();
    }

    public static void reverse(int[] a, int b, int e) {
        for (int i = b; i < (b + e) / 2; i++) {
            int tmp = a[i];
            a[i] = a[e - 1 - (i - b)];
            a[e - 1 - (i - b)] = tmp;
        }
    }
}

