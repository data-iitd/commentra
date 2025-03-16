import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int z = sc.nextInt();
        int rank = sc.nextInt();
        int[] xrr = new int[x];
        int[] yrr = new int[y];
        int[] zrr = new int[z];
        for(int i = 0; i < x; i++) xrr[i] = sc.nextInt();
        for(int i = 0; i < y; i++) yrr[i] = sc.nextInt();
        for(int i = 0; i < z; i++) zrr[i] = sc.nextInt();
        int min_sum = Integer.MAX_VALUE;
        int max_sum = Integer.MIN_VALUE;
        for(int i = 0; i < z; i++) min_sum = Math.min(min_sum, zrr[i]);
        for(int i = 0; i < z; i++) max_sum = Math.max(max_sum, zrr[i]);
        int[] pair = new int[x*y];
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
        int r;
        for(r = rank; r >= 1; r--) {
            int64_t low = prev-1;
            int64_t high = max_sum+1;
            while(low + 1 < high) {
                int64_t mid = (low + high)/2;
                int cnt = 0;
                for(int i = 0; i < z; i++) {
                    int64_t pivot = zrr[i];
                    int l = cache[i]-1;
                    int r = idx;
                    int tmp = 0;
                    while(l + 1 < r) {
                        int mid = (l + r)/2;
                        if(pair[mid] < mid-pivot) {
                            l = mid;
                        } else {
                            r = mid;
                        }
                    }
                    tmp = l+1;
                    cnt_map[i] = tmp;
                    cnt += tmp;
                }
                if(cnt <= size-r) {
                    System.arraycopy(cnt_map, 0, cache, 0, z);
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
}

