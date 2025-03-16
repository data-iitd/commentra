import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n and k
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read the array of integers
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        
        // Sort the array
        Arrays.sort(arr);
        
        // Calculate the sum of the first k elements
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        
        // Print the result
        System.out.println(sum);
        
        scanner.close();
    }
}
// <END-OF-CODE>
