import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();  // Read the number of elements in the list `r`
        int[] r = new int[n];  // Initialize the array `r`
        
        for (int i = 0; i < n; i++) {
            r[i] = scanner.nextInt();  // Read the space-separated integers into the array `r`
        }
        
        int ans = Math.abs(r[0]);  // Initialize `ans` to the absolute value of the first element in the array `r`
        
        // The for loop iterates over the range from 1 to `n` (exclusive)
        // For each iteration, it adds the absolute difference between the current element and the previous element in the array `r` to `ans`
        for (int i = 1; i < n; i++) {
            ans += Math.abs(r[i] - r[i - 1]);
        }
        
        System.out.println(ans);  // Print the value of `ans`
        
        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
