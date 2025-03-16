import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        new Main();
    }

    public Main() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();
        System.out.println(mergesort(a, 0, n));
    }

    public int mergesort(int[] a, int left, int right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        if (left + 1 < right) {
            cnt += mergesort(a, left, mid);
            cnt += mergesort(a, mid, right);
            cnt += merge(a, left, mid, right);
        }
        return cnt;
    }

    public int merge(int[] a, int left, int mid, int right) {
        int i = left, j = mid, k = left;
        int n1 = mid - left, n2 = right - mid;
        int[] L = new int[n1 + 2];
        int[] R = new int[n2 + 2];
        for (int x = 0; x < n1; x++) L[x] = a[left + x];
        for (int x = 0; x < n2; x++) R[x] = a[mid + x];
        L[n1] = R[n2] = Integer.MAX_VALUE;
        while (k < right) {
            if (L[i] <= R[j]) a[k++] = L[i++];
            else {
                a[k++] = R[j++];
                cnt += n1 - i;
            }
        }
        return cnt;
    }
}

