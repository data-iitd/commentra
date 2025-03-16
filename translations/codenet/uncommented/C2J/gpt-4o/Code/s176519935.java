import java.util.Scanner;

public class Main {
    static long[] heap = new long[100000];
    static long sz = 0;

    static void push(long x) {
        int i = (int) sz++;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[p] >= x) break;
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = x;
    }

    static long pop() {
        long ret = heap[0];
        long x = heap[--sz];
        int i = 0;
        while (i * 2 + 1 < sz) {
            int a = i * 2 + 1, b = i * 2 + 2;
            if (b < sz && heap[b] > heap[a]) a = b;
            if (heap[a] <= x) break;
            heap[i] = heap[a];
            i = a;
        }
        heap[i] = x;
        return ret;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        long[] a = new long[100000];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
        }
        for (int i = 0; i < n; i++) {
            push(a[i]);
        }
        for (int i = 0; i < m; i++) {
            long tm = pop();
            tm /= 2;
            push(tm);
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += heap[i];
        }
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
