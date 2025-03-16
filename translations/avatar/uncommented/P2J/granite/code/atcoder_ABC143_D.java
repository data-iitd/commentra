
import java.io.*;
import java.util.*;

class atcoder_ABC143_D {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] s = br.readLine().split(" ");
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = Integer.parseInt(s[i]);
        }
        Arrays.sort(l);
        long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = l[i];
                int b = l[j];
                int left = lowerBound(l, a - b);
                int right = upperBound(l, a + b);
                int tmp = right - left;
                if (left <= i && i < right) {
                    tmp--;
                }
                if (left <= j && j < right) {
                    tmp--;
                }
                ans += tmp;
            }
        }
        System.out.println(ans / 3);
    }

    public static int lowerBound(int[] a, int key) {
        int ng = -1;
        int ok = a.length;
        while (Math.abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if (a[mid] >= key) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    }

    public static int upperBound(int[] a, int key) {
        int ng = -1;
        int ok = a.length;
        while (Math.abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if (a[mid] > key) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    }
}

