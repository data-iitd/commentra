
// The code starts by including necessary headers for input/output operations, string manipulation, and memory management.
import java.util.*;
import java.io.*;

// Macros are defined to set the maximum sizes for arrays and other constants.
final int NUM_MAX = 1000;
final int NUM2_MAX = NUM_MAX*NUM_MAX;
final int RANK_MAX = 3000;

// This function reads four integers from the standard input and stores them in the provided variables.
void get_int4(int[] a1, int[] a2, int[] a3, int[] a4) {
  Scanner sc = new Scanner(System.in);
  a1[0] = sc.nextInt();
  a2[0] = sc.nextInt();
  a3[0] = sc.nextInt();
  a4[0] = sc.nextInt();
}

// This function reads an array of integers from the standard input.
void fget_array(int[] arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        arr[i] = Integer.parseInt(sc.next());
    }
}

// These functions are used to compare integers for sorting in ascending and descending order.
int asc(int a1, int a2) {
    if(a1 > a2) return 1;
    if(a1 == a2) return 0;
    return -1;
}

int desc(int a1, int a2) {
    if(a1 > a2) return -1;
    if(a1 == a2) return 0;
    return 1;
}

// Constants are defined for the maximum values of various quantities.
final int VAL_MAX = (int)(1e+10);
final int SUM_MAX = (VAL_MAX*3);

// A structure is defined to represent a range of indices.

class range {
    int start;
    int end;
}


// This function finds the lower bound of a key in a sorted array within a given range.
int lower_bound(int[] arr, range r, int key) {
    int low = r.start;;
    int high = r.end;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(arr[mid] < key) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low + 1;
}


// The main function reads input, processes data, and outputs the result based on the given rank.


public class Main {
    public static void main(String[] args) {
        int[] x = new int[1];
        int[] y = new int[1];
        int[] z = new int[1];
        int[] rank = new int[1];
        get_int4(x, y, z, rank);
        int[] xrr = new int[x[0]];
        int[] yrr = new int[y[0]];
        int[] zrr = new int[z[0]];
        fget_array(xrr, x[0]);
        fget_array(yrr, y[0]);
        fget_array(zrr, z[0]);
        int min_sum = VAL_MAX+1;
        int max_sum = 0;
        int i, j;
        for(i = 0; i < z[0]; i++) min_sum = Math.min(min_sum, zrr[i]);
        for(i = 0; i < z[0]; i++) max_sum = Math.max(max_sum, zrr[i]);

        int[] pair = new int[NUM2_MAX];
        int idx = 0;
        for(i = 0; i < x[0]; i++) {
            for(j = 0; j < y[0]; j++) {
                pair[idx++] = xrr[i] + yrr[j];
            }
        }
        Arrays.sort(pair, 0, idx, new Comparator<Integer>() {
            public int compare(Integer a1, Integer a2) {
                return asc(a1, a2);
            }
        });
        min_sum += pair[0];
        max_sum += pair[idx-1];

        int[] cache = new int[NUM_MAX];
        int[] cnt_map = new int[NUM_MAX];
        int[] ans = new int[RANK_MAX];
        int size = x[0]*y[0]*z[0];
        int64_t prev = min_sum;
        int r;
        for(r = rank[0]; r >= 1; r--) {
            int low = prev-1;
            int high = max_sum+1;
            while(low + 1 < high) {
                int mid = (low + high)/2;
                int cnt = 0;
                for(i = 0; i < z[0]; i++) {
                    int pivot = zrr[i];
                    range r = new range();
                    r.start = cache[i]-1;
                    r.end = idx;
                    int tmp = lower_bound(pair, r, mid-pivot);
                    cnt_map[i] = tmp;
                    cnt += tmp;
                }
                if(cnt <= size-r) {
                    System.arraycopy(cnt_map, 0, cache, 0, z[0]);
                    low = mid;
                } else {
                    high = mid;
                }
            }
            ans[r-1] = low;
            if(low == max_sum) break;
            prev = low;
        }
        for(i = 0; i < rank[0]; i++) {
            System.out.println((ans[i]==0)? max_sum : ans[i]);
        }
    }
}

