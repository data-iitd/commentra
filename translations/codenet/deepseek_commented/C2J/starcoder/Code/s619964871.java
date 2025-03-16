/*
 * FileName:     the_number_of_inversions_fix
 * CreatedDate:  2020-06-05 16:25:10 +0900
 * LastModified: 2020-07-06 22:22:35 +0900
 */

import java.util.*;

// Function to merge two subarrays and count inversions
long int sort(long int[] a, int left, int middle, int right){
    long int l_arr[] = new long[middle-left+1];
    long int r_arr[] = new long[right-middle+1];
    long int cnt = 0;
    // Copy elements into temporary arrays
    for(int i=0;i<middle-left;i++) l_arr[i] = a[i+left];
    for(int i=0;i<right-middle;i++) r_arr[i] = a[i+middle];
    // Sentinel values to simplify merging
    l_arr[middle-left] = Long.MAX_VALUE;
    r_arr[right-middle] = Long.MAX_VALUE;
    int l=0, r=0;
    // Merge the two subarrays while counting inversions
    for(int i=0;i<right-left;i++){
        if(l_arr[l]<=r_arr[r]){
            a[left+i] = l_arr[l++];
        }
        else{
            a[left+i] = r_arr[r++];
            cnt += middle-left-l;
        }
    }
    return cnt;
}

// Recursive function to count inversions in the array
long int merge(long int[] a, int left, int right){
    if(left+1<right){
        int middle = (left+right)/2;
        // Recursively count inversions in the left and right halves
        long int x1 = merge(a, left, middle);
        long int x2 = merge(a, middle, right);
        // Merge the two halves and count inversions in the merge step
        long int x3 = sort(a, left, middle, right);
        return x1+x2+x3;
    }
    else{
        return 0;
    }
}

// Main function to read input, count inversions, and print the result
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Read the size of the array
        long int[] a = new long[n];
        for(int i=0;i<n;i++) a[i] = sc.nextLong(); // Read the elements of the array
        System.out.println(merge(a, 0, n)); // Count and print the number of inversions
    }
}

