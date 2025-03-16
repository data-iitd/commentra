import java.util.Arrays;
import java.util.Scanner;

public class TripletCounter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values: first value is n, followed by n integers
        int n = scanner.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        // Sort the list of integers
        Arrays.sort(l);
        
        // Initialize the answer variable to count valid triplets
        long ans = 0;
        
        // Iterate through each pair of elements in the sorted list
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = l[i];  // First element of the pair
                int b = l[j];  // Second element of the pair
                
                // Find the index where a + b would fit in the sorted list
                int right = bisectLeft(l, a + b);
                
                // Find the index where max(a - b, b - a) would fit in the sorted list
                int left = bisectRight(l, Math.max(a - b, b - a));
                
                // Calculate the number of valid third elements that can form a triplet
                long tmp = Math.max(0, right - left);
                
                // Adjust the count if the indices i or j are within the range of valid third elements
                if (left <= i && i < right) {
                    tmp--;  // Exclude the first element if it's counted
                }
                if (left <= j && j < right) {
                    tmp--;  // Exclude the second element if it's counted
                }
                
                // Add the number of valid triplets formed with the current pair (i, j)
                ans += tmp;
            }
        }
        
        // Since each triplet is counted three times, divide the final answer by 3
        System.out.println(ans / 3);
    }
    
    // Method to find the leftmost index where value can be inserted
    private static int bisectLeft(int[] arr, int value) {
        int low = 0, high = arr.length;
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
    
    // Method to find the rightmost index where value can be inserted
    private static int bisectRight(int[] arr, int value) {
        int low = 0, high = arr.length;
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
}
// <END-OF-CODE>
