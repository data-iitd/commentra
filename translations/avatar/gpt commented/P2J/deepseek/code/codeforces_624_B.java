import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = Integer.parseInt(scanner.nextLine());
        
        // Read the list of integers and convert them to an array of integers
        int[] a = Arrays.stream(scanner.nextLine().split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray();
        
        // Initialize the previous value to infinity
        int pre = Integer.MAX_VALUE;
        
        // Initialize the answer variable to accumulate the result
        int ans = 0;
        
        // Sort the array in descending order
        Arrays.sort(a);
        for (int j = n - 1; j >= 0; j--) {
            // Calculate the current contribution to the answer
            // It takes the minimum of (pre - 1) and the current element a[j], ensuring it's non-negative
            ans += Math.max(0, Math.min(pre - 1, a[j]));
            
            // Update the previous value for the next iteration
            pre = Math.max(0, Math.min(pre - 1, a[j]));
        }
        
        // Print the final accumulated answer
        System.out.println(ans);
    }
}
