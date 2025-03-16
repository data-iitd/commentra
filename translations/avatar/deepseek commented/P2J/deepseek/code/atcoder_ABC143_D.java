import java.util.*;
import java.io.*;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] input = reader.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int[] l = Arrays.stream(input).skip(1).mapToInt(Integer::parseInt).toArray();

        // Read input: n is the number of elements, l is the array of integers

        Arrays.sort(l);
        // Sort the array l to prepare for binary search operations

        long ans = 0;
        // Initialize the answer variable to store the count of valid triangles

        for (int i = 0; i < n; i++) {
            // Outer loop: iterate over each element in l
            for (int j = i + 1; j < n; j++) {
                // Inner loop: iterate over each element in l starting from i+1
                int a = l[i];
                int b = l[j];
                // a and b are the sides of the triangle being considered

                int right = binarySearchRight(l, a + b);
                // Find the leftmost index where a + b can be inserted to maintain sorted order

                int left = binarySearchLeft(l, Math.max(a - b, b - a));
                // Find the rightmost index where max(a - b, b - a) can be inserted to maintain sorted order

                int tmp = Math.max(0, right - left);
                // Calculate the number of valid elements that can form a triangle

                if (left <= i && i < right) {
                    tmp--;
                }
                // Adjust for overcounting if i is within the valid range

                if (left <= j && j < right) {
                    tmp--;
                }
                // Adjust for overcounting if j is within the valid range

                ans += tmp;
                // Add the valid triangle count for the current pair to the total answer
            }
        }

        System.out.println(ans / 3);
        // Print the final answer, dividing by 3 as implied by the context
    }

    private static int binarySearchRight(int[] arr, int value) {
        int low = 0;
        int high = arr.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    private static int binarySearchLeft(int[] arr, int value) {
        int low = 0;
        int high = arr.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}
