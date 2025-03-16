
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int z = sc.nextInt();
        int rank = sc.nextInt();
        int64_t[] xrr = new int64_t[x];
        int64_t[] yrr = new int64_t[y];
        int64_t[] zrr = new int64_t[z];
        for(int i = 0; i < x; i++) {
            xrr[i] = sc.nextLong();
        }
        for(int i = 0; i < y; i++) {
            yrr[i] = sc.nextLong();
        }
        for(int i = 0; i < z; i++) {
            zrr[i] = sc.nextLong();
        }
        int64_t min_sum = Long.MAX_VALUE;
        int64_t max_sum = 0;
        for(int i = 0; i < z; i++) {
            min_sum = Math.min(min_sum, zrr[i]);
            max_sum += zrr[i];
        }
        int64_t[] pair = new int64_t[x*y];
        int idx = 0;
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                pair[idx++] = xrr[i] + yrr[j];
            }
        }
        Arrays.sort(pair);
        min_sum += pair[0];
        max_sum += pair[idx-1];
        int[] cache = new int[z];
        int[] cnt_map = new int[z];
        int64_t[] ans = new int64_t[rank];
        int size = x*y*z;
        int64_t prev = min_sum;
        for(int r = rank; r >= 1; r--) {
            int64_t low = prev-1;
            int64_t high = max_sum+1;
            while(low + 1 < high) {
                int64_t mid = (low + high)/2;
                for(int i = 0; i < z; i++) {
                    int64_t pivot = zrr[i];
                    int tmp = lower_bound(pair, cache[i]-1, idx, mid-pivot);
                    cnt_map[i] = tmp;
                }
                if(sum(cnt_map, z) >= size-r) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            ans[r-1] = low;
            if(low == max_sum) break;
            prev = low;
        }
        for(int i = 0; i < rank; i++) {
            System.out.println((ans[i]==0)? max_sum : ans[i]);
        }
    }

    public static int lower_bound(int64_t[] arr, int start, int end, int64_t key) {
        int low = start;
        int high = end;
        while(low + 1 < high) {
            int mid = (low + high)/2;
            if(arr[mid] < key) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low + 1;
    }

    public static int sum(int[] arr, int size) {
        int ans = 0;
        for(int i = 0; i < size; i++) {
            ans += arr[i];
        }
        return ans;
    }
}

