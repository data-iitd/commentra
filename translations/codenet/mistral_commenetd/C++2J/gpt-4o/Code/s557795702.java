import java.util.Scanner;

public class InversionCount {
    static final int MAXN = 200010; // maximum size of the array
    static long[] L = new long[MAXN / 2], R = new long[MAXN / 2]; // auxiliary arrays 'L' and 'R'
    static long[] a = new long[MAXN]; // array 'a' of size MAXN
    static int n; // integer 'n' representing the size of the array

    static long merge(int left, int mid, int right) { // function to merge two sorted subarrays
        int i, j, k;
        long cnt = 0; // counter to store the number of inversions
        int n1 = mid - left; // size of the first subarray
        int n2 = right - mid; // size of the second subarray

        // copy the elements of the first subarray to 'L' array
        for (i = 0; i < n1; ++i) L[i] = a[left + i];

        // copy the elements of the second subarray to 'R' array
        for (i = 0; i < n2; ++i) R[i] = a[mid + i];

        // set the last elements of 'L' and 'R' arrays as INF
        L[n1] = R[n2] = Long.MAX_VALUE;

        // merge the two sorted subarrays and update the array 'a' accordingly
        i = j = 0;
        for (k = left; k < right; ++k) {
            if (L[i] <= R[j]) a[k] = L[i++]; // if the current element in 'L' is smaller than the current element in 'R', copy it to 'a'
            else {
                a[k] = R[j++]; // if the current element in 'L' is greater than the current element in 'R', copy it to 'a'
                cnt += n1 - i; // update the counter 'cnt' with the number of inversions caused by this swap
            }
        }

        return cnt; // return the number of inversions caused by merging the two subarrays
    }

    static long mergesort(int left, int right) { // recursive function to sort the subarrays using merge sort algorithm
        int mid;
        long v1, v2, v3; // variables to store the number of inversions caused by sorting the subarrays

        if (left + 1 < right) { // if the size of the subarray is greater than 1
            mid = (left + right) / 2; // find the middle index
            v1 = mergesort(left, mid); // recursively sort the left subarray and calculate the number of inversions
            v2 = mergesort(mid, right); // recursively sort the right subarray and calculate the number of inversions
            v3 = merge(left, mid, right); // merge the two sorted subarrays and calculate the number of inversions
            return v1 + v2 + v3; // return the total number of inversions caused by sorting the subarrays
        }
        return 0; // if the size of the subarray is 1, the array is already sorted and there are no inversions
    }

    public static void main(String[] args) { // main function to read the input and call the mergesort function
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt(); // read the size of the array
        for (int i = 0; i < n; ++i) a[i] = scanner.nextLong(); // read the elements of the array
        long ans = mergesort(0, n); // call the mergesort function to sort the array and calculate the number of inversions
        System.out.println(ans); // print the number of inversions
        scanner.close();
    }
}

// <END-OF-CODE>
