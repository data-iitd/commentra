import java.util.Scanner;
public final class Main {
    private Main() {}
    public static void main(String[] args) {
        // Step 1: Reading Input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        // Step 2: Reading k
        int k = scanner.nextInt();
        // Step 3: Finding the k smallest elements
        int[] result = getMinKNumsByMain(arr, k);
        // Final Output
        for (int num : result) {
            System.out.print(num + " ");
        }
        System.out.println();
        scanner.close();
    }
    // Step 4: Handling Edge Cases
    public static int[] getMinKNumsByMain(int[] arr, int k) {
        if (k < 1 || k > arr.length) {
            return null;
        }
        // Step 5: Finding the k-th smallest element
        int minKth = getMinKthByMain(arr, k);
        int[] res = new int[k];
        int index = 0;
        for (int value : arr) {
            if (value < minKth) {
                res[index++] = value;
            }
        }
        // Step 12: Filling remaining slots with the k-th smallest element
        for (; index != res.length; index++) {
            res[index] = minKth;
        }
        return res;
    }
    // Step 6: Copying the Array
    public static int getMinKthByMain(int[] arr, int k) {
        int[] copyArr = copyArray(arr);
        return bfprt(copyArr, 0, copyArr.length - 1, k - 1);
    }
    public static int[] copyArray(int[] arr) {
        int[] copyArr = new int[arr.length];
        System.arraycopy(arr, 0, copyArr, 0, arr.length);
        return copyArr;
    }
    // Step 7: Applying BFPRT Algorithm
    public static int bfprt(int[] arr, int begin, int end, int i) {
        if (begin == end) {
            return arr[begin];
        }
        // Step 8: Median of Medians
        int pivot = medianOfMedians(arr, begin, end);
        int[] pivotRange = partition(arr, begin, end, pivot);
        if (i >= pivotRange[0] && i <= pivotRange[1]) {
            return arr[i];
        } else if (i < pivotRange[0]) {
            return bfprt(arr, begin, pivotRange[0] - 1, i);
        } else {
            return bfprt(arr, pivotRange[1] + 1, end, i);
        }
    }
    // Step 9: Median of Medians
    public static int medianOfMedians(int[] arr, int begin, int end) {
        int num = end - begin + 1;
        int offset = num % 5 == 0 ? 0 : 1;
        int[] mArr = new int[num / 5 + offset];
        for (int i = 0; i < mArr.length; i++) {
            mArr[i] = getMedian(arr, begin + i * 5, Math.min(end, begin + i * 5 + 4));
        }
        return bfprt(mArr, 0, mArr.length - 1, mArr.length / 2);
    }
    // Step 10: Partitioning the Array
    public static int[] partition(int[] arr, int begin, int end, int num) {
        int small = begin - 1;
        int cur = begin;
        int big = end + 1;
        while (cur != big) {
            if (arr[cur] < num) {
                swap(arr, ++small, cur++);
            } else if (arr[cur] > num) {
                swap(arr, --big, cur);
            } else {
                cur++;
            }
        }
        return new int[]{small + 1, big - 1};
    }
    // Step 11: Getting the Median
    public static int getMedian(int[] arr, int begin, int end) {
        insertionSort(arr, begin, end);
        int sum = begin + end;
        int mid = sum / 2 + (sum % 2);
        return arr[mid];
    }
    // Step 11: Insertion Sort
    public static void insertionSort(int[] arr, int begin, int end) {
        if (arr == null || arr.length < 2) {
            return;
        }
        for (int i = begin + 1; i != end + 1; i++) {
            for (int j = i; j != begin; j--) {
                if (arr[j - 1] > arr[j]) {
                    swap(arr, j - 1, j);
                } else {
                    break;
                }
            }
        }
    }
    // Step 12: Swapping Elements
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
