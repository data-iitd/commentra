
import java.util.*;
import java.io.*;

public class s557795702{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        String[] s = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(s[i]);
        }
        long ans = mergesort(a, 0, n);
        System.out.println(ans);
    }

    public static long merge(int[] a, int left, int mid, int right) {
        int n1 = mid - left;
        int n2 = right - mid;
        int[] L = new int[n1 + 1];
        int[] R = new int[n2 + 1];
        for (int i = 0; i < n1; i++) {
            L[i] = a[left + i];
        }
        for (int i = 0; i < n2; i++) {
            R[i] = a[mid + i];
        }
        L[n1] = R[n2] = Integer.MAX_VALUE;
        int i = 0, j = 0;
        long cnt = 0;
        for (int k = left; k < right; k++) {
            if (L[i] <= R[j]) {
                a[k] = L[i++];
            } else {
                a[k] = R[j++];
                cnt += n1 - i;
            }
        }
        return cnt;
    }

    public static long mergesort(int[] a, int left, int right) {
        int mid;
        long v1, v2, v3;
        if (left + 1 < right) {
            mid = (left + right) / 2;
            v1 = mergesort(a, left, mid);
            v2 = mergesort(a, mid, right);
            v3 = merge(a, left, mid, right);
            return v1 + v2 + v3;
        }
        return 0;
    }
}
