import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        int n, i;
        n = getNum();
        for (i = 0; i < n; i++) {
            A[i] = getNum();
        }
        CountingSort(A, B, MAX_Ai, n);
        for (i = 0; i < n; i++) {
            putNum(B[i]);
        }
    }

    public static void CountingSort(int A[], int B[], int k, int len) {
        int i, j, C[k];
        for (i = 0; i < k; i++) {
            C[i] = 0;
        }
        for (i = 0; i < len; i++) {
            C[A[i]]++;
        }
        for (i = 1; i < k; i++) {
            C[i] += C[i - 1];
        }
        for (i = len - 1; i >= 0; i--) {
            B[C[A[i]] - 1] = A[i];
            C[A[i]]--;
        }
    }

    public static int getNum() {
        int n = 0;
        char c;
        do {
            c = (char)System.in.read();
        } while (c < '0' || c > '9');
        do {
            n = n * 10 + c - '0';
            c = (char)System.in.read();
        } while (c >= '0' && c <= '9');
        return n;
    }

    public static void putNum(int n) {
        if (n == 0) {
            System.out.write('0');
        }
        boolean neg = false;
        if (n < 0) {
            neg = true;
            n = -n;
        }
        char buf[] = new char[100];
        int i = 0;
        do {
            buf[i++] = (char)('0' + n % 10);
            n /= 10;
        } while (n!= 0);
        if (neg) {
            System.out.write('-');
        }
        while (--i >= 0) {
            System.out.write(buf[i]);
        }
    }
}
