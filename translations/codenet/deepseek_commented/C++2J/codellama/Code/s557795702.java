// Include the java.util library for input and output operations.
import java.util.*;

// Declare a class named MergeSort with a main function.
class MergeSort{
    // Declare an array a to store the elements, an integer n for the number of elements, and two arrays L and R to temporarily store the left and right halves of the array during merge sort.
    static int a[],n,L[],R[];

    // Merge function: Merges two sorted halves of the array a from index left to right.
    static long merge(int left,int mid,int right){
        int i,j,k;
        long cnt = 0;
        int n1 = mid - left;
        int n2 = right - mid;
        for(i = 0; i < n1; ++i)	L[i] = a[left+i];
        for(i = 0; i < n2; ++i)	R[i] = a[mid+i];
        L[n1] = R[n2] = Integer.MAX_VALUE;
        i = j = 0;
        for(k = left; k < right; ++k){
            if(L[i] <= R[j]) a[k] = L[i++];
            else{
                a[k] = R[j++];
                cnt += n1-i;
            }
        }
        return cnt;
    }

    // Merge sort function: Recursively divides the array into halves and sorts them using merge sort.
    static long mergesort(int left,int right){
        int mid;
        long v1,v2,v3;
        if(left + 1 < right){
            mid = (left+right)/2;
            v1 = mergesort(left,mid);
            v2 = mergesort(mid,right);
            v3 = merge(left,mid,right);
            return v1+v2+v3;
        }
        return 0;
    }

    // Main function: Synchronizes the input/output streams, reads the number of elements and the elements themselves, calls the merge sort function to sort the array and compute the number of inversions, and prints the number of inversions.
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n];
        L = new int[n/2];
        R = new int[n/2];
        for(int i = 0; i < n; ++i) a[i] = sc.nextInt();
        long ans = mergesort(0,n);
        System.out.println(ans);
    }
}

