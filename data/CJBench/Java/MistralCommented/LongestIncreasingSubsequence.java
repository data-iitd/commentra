
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    private static int upperBound(int[] ar, int l, int r, int key) {
        // Binary search algorithm to find the index of the last occurrence of key in the subarray ar[l..r]
        while (l < r - 1) {
            int m = (l + r) >>> 1; // Calculate the middle index
            if (ar[m] >= key) { // If the middle element is greater than or equal to key
                r = m; // Update the right index
            } else {
                l = m; // Otherwise, update the left index
            }
        }
        return r; // Return the index of the last occurrence of key
    }

    public static int lis(int[] array) {
        // Length of the Longest Increasing Subsequence in the given array
        int len = array.length;
        if (len == 0) {
            return 0; // Base case: empty array has no LIS
        }
        int[] tail = new int[len]; // Array to store the last element of each LIS
        int length = 1; // Length of the current LIS
        tail[0] = array[0]; // Initialize the first element of tail array
        for (int i = 1; i < len; i++) {
            if (array[i] < tail[0]) { // If the current element is smaller than the first element of tail array
                tail[0] = array[i]; // Update the first element of tail array
            } else if (array[i] > tail[length - 1]) { // If the current element is greater than the last element of the current LIS
                tail[length++] = array[i]; // Add the current element to the tail array and increment the length of LIS
            } else { // If the current element can be added to an existing LIS
                tail[upperBound(tail, -1, length - 1, array[i])] = array[i]; // Update the last element of the LIS that contains the current element
            }
        }
        return length; // Return the length of the Longest Increasing Subsequence
    }

    public static int findLISLen(int[] a) {
        // Length of the Longest Increasing Subsequence using binary search
        final int size = a.length;
        if (size == 0) {
            return 0; // Base case: empty array has no LIS
        }
        int[] arr = new int[size]; // Array to store the last occurrence of each element in the sorted array
        arr[0] = a[0];
        int lis = 1;
        for (int i = 1; i < size; i++) {
            int index = binarySearchBetween(arr, lis - 1, a[i]); // Binary search to find the index where a[i] should be inserted in arr
            arr[index] = a[i]; // Update the array with the current element
            if (index == lis) { // If the index is equal to the length of LIS
                lis++; // Increment the length of LIS
            }
        }
        return lis; // Return the length of the Longest Increasing Subsequence
    }

    private static int binarySearchBetween(int[] t, int end, int key) {
        // Binary search algorithm to find the index where key should be inserted in the sorted subarray t[0..end]
        int left = 0;
        int right = end;
        if (key < t[0]) { // If key is smaller than the first element of the subarray
            return 0; // Return 0 as the index
        }
        if (key > t[end]) { // If key is greater than the last element of the subarray
            return end + 1; // Return end+1 as the index
        }
        while (left < right - 1) { // Iterate until the search space is reduced to one element
            final int middle = (left + right) >>> 1; // Calculate the middle index
            if (t[middle] < key) { // If the middle element is smaller than key
                left = middle; // Update the left index
            } else {
                right = middle; // Otherwise, update the right index
            }
        }
        return right; // Return the index where key should be inserted
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the console
        int n = scanner.nextInt(); // Read the number of elements in the array from the console
        int[] array = new int[n]; // Create an array of size n to store the input elements
        for (int i = 0; i < n; i++) { // Iterate through the array to read the elements from the console
            array[i] = scanner.nextInt();
        }
        int method = scanner.nextInt(); // Read the method number from the console
        int result;
        if (method == 1) { // If the method number is 1, call the lis() method to find the length of the LIS
            result = lis(array);
        } else { // Otherwise, call the findLISLen() method to find the length of the LIS using binary search
            result = findLISLen(array);
        }
        System.out.println("The length of the longest increasing subsequence is: " + result); // Print the result to the console