
import java.util.Scanner;

public class s176519935{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        long[] heap = new long[n];
        int sz = 0;
        for (int i = 0; i < n; i++) {
            push(heap, sz++, a[i]);
        }
        for (int i = 0; i < m; i++) {
            long tm = pop(heap, sz--);
            push(heap, sz++, tm / 2);
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += heap[i];
        }
        System.out.println(ans);
    }

    public static void push(long[] heap, int i, long x) {
        int j = i++;
        while (j > 0) {
            int p = (j - 1) / 2;
            if (heap[p] >= x) break;
            heap[j] = heap[p];
            j = p;
        }
        heap[j] = x;
    }

    public static long pop(long[] heap, int i) {
        long ret = heap[0];
        long x = heap[--i];
        int j = 0;
        while (j * 2 + 1 < i) {
            int a = j * 2 + 1, b = j * 2 + 2;
            if (b < i && heap[b] > heap[a]) a = b;
            if (heap[a] <= x) break;
            heap[j] = heap[a];
            j = a;
        }
        heap[j] = x;
        return ret;
    }
}

