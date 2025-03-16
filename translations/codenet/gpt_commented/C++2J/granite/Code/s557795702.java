
import java.util.*;

public class s557795702{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        long ans = mergeSort(a, 0, n);
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
        for (int j = 0; j < n2; j++) {
            R[j] = a[mid + j];
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

    public static long mergeSort(int[] a, int left, int right) {
        int mid;
        long v1, v2, v3;
        if (left + 1 < right) {
            mid = (left + right) / 2;
            v1 = mergeSort(a, left, mid);
            v2 = mergeSort(a, mid, right);
            v3 = merge(a, left, mid, right);
            return v1 + v2 + v3;
        }
        return 0;
    }
}

