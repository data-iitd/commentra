

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
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = l[i], b = l[j];
                int right = lowerBound(l, a + b);
                int left = upperBound(l, Math.max(a - b, b - a));
                int tmp = Math.max(0, right - left);
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
        int low = 0, high = a.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (a[mid] < key) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    public static int upperBound(int[] a, int key) {
        int low = 0, high = a.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (a[mid] <= key) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}

Translate the above Java code to C++ and end with comment "