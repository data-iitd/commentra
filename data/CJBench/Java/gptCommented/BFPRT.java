import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {}

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the size of the array
        int n = scanner.nextInt();
        int[] arr = new int[n];
        
        // Read n integers into the array
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        
        // Read the value of k
        int k = scanner.nextInt();
        
        // Get the k smallest numbers from the array
        int[] result = getMinKNumsByMain(arr, k);
        
        // Print the result
        for (int num : result) {
            System.out.print(num + " ");
        }
        System.out.println();
        
        // Close the scanner to free resources
        scanner.close();
    }

    // Method to get the k smallest numbers from the array
    public static int[] getMinKNumsByMain(int[] arr, int k) {
        // Check if k is within valid range
        if (k < 1 || k > arr.length) {
            return null; // Return null if k is invalid
        }
        
        // Find the k-th smallest number
        int minKth = getMinKthByMain(arr, k);
        int[] res = new int[k]; // Array to hold the k smallest numbers
        int index = 0;
        
        // Populate the result array with numbers smaller than the k-th smallest
        for (int value : arr) {
            if (value < minKth) {
                res[index++] = value;
            }
        }
        
        // Fill the remaining slots in the result array with the k-th smallest number
        for (; index != res.length; index++) {
            res[index] = minKth;
        }
        
        return res; // Return the array of k smallest numbers
    }

    // Method to find the k-th smallest number in the array
    public static int getMinKthByMain(int[] arr, int k) {
        int[] copyArr = copyArray(arr); // Create a copy of the original array
        return bfprt(copyArr, 0, copyArr.length - 1, k - 1); // Use BFPRT algorithm to find the k-th smallest
    }

    // Method to create a copy of the array
    public static int[] copyArray(int[] arr) {
        int[] copyArr = new int[arr.length];
        System.arraycopy(arr, 0, copyArr, 0, arr.length); // Copy elements from original array
        return copyArr; // Return the copied array
    }

    // BFPRT algorithm to find the i-th smallest number
    public static int bfprt(int[] arr, int begin, int end, int i) {
        // Base case: if the range has only one element
        if (begin == end) {
            return arr[begin]; // Return that element
        }
        
        // Find the pivot using the median of medians method
        int pivot = medianOfMedians(arr, begin, end);
        int[] pivotRange = partition(arr, begin, end, pivot); // Partition the array around the pivot
        
        // Check if the i-th smallest is in the pivot range
        if (i >= pivotRange[0] && i <= pivotRange[1]) {
            return arr[i]; // Return the i-th smallest number
        } else if (i < pivotRange[0]) {
            return bfprt(arr, begin, pivotRange[0] - 1, i); // Search in the left partition
        } else {
            return bfprt(arr, pivotRange[1] + 1, end, i); // Search in the right partition
        }
    }

    // Method to find the median of medians
    public static int medianOfMedians(int[] arr, int begin, int end) {
        int num = end - begin + 1; // Number of elements in the range
        int offset = num % 5 == 0 ? 0 : 1; // Determine if there's an extra group
        int[] mArr = new int[num / 5 + offset]; // Array to hold medians
        
        // Calculate the median of each group of 5
        for (int i = 0; i < mArr.length; i++) {
            mArr[i] = getMedian(arr, begin + i * 5, Math.min(end, begin + i * 5 + 4));
        }
        
        // Recursively find the median of the medians
        return bfprt(mArr, 0, mArr.length - 1, mArr.length / 2);
    }

    // Method to partition the array around a pivot
    public static int[] partition(int[] arr, int begin, int end, int num) {
        int small = begin - 1; // Pointer for smaller elements
        int cur = begin; // Current pointer
        int big = end + 1; // Pointer for larger elements
        
        // Partitioning logic
        while (cur != big) {
            if (arr[cur] < num) {
                swap(arr, ++small, cur++); // Move smaller elements to the left
            } else if (arr[cur] > num) {
                swap(arr, --big, cur); // Move larger elements to the right
            } else {
                cur++; // Move current pointer forward
            }
        }
        return new int[]{small + 1, big - 1}; // Return the range of the pivot
    }

    // Method to find the median of a subarray
    public static int getMedian(int[] arr, int begin, int end) {
        insertionSort(arr, begin, end); // Sort the subarray
        int sum = begin + end; // Calculate the sum of indices
        int mid = sum / 2 + (sum % 2); // Find the middle index
        return arr[mid]; // Return the median value
    }

    // Insertion sort algorithm for sorting a subarray
    public static void insertionSort(int[] arr, int begin, int end) {
        if (arr == null || arr.length < 2) {
            return; // Return if the array is null or has less than 2 elements
        }
        // Insertion sort logic
        for (int i = begin + 1; i != end + 1; i++) {
            for (int j = i; j != begin; j--) {
                if (arr[j - 1] > arr[j]) {
                    swap(arr, j - 1, j); // Swap elements to sort
                } else {
                    break; // Break if the order is correct
                }
            }
        }
    }

    // Method to swap two elements in the array
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i]; // Store the value at index i
        arr[i] = arr[j]; // Assign the value at index j to index i
        arr[j] = temp; // Assign the stored value to index j
    }
}
