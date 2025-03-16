import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();  // Take an integer input representing the length of the list `a`
        int[] a = new int[n];  // Initialize an array `a` of length `n`
        
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();  // Take space-separated integers and fill the array `a`
        }
        
        int[] b = new int[n];  // Initialize an empty array `b` of length `n`
        
        // Assign the index of each element in `a` to the corresponding position in `b`, adjusting for zero-based indexing
        for (int i = 0; i < n; i++) {
            b[a[i] - 1] = i;
        }
        
        int res = 0;  // Initialize the result variable `res` to 0
        
        // Calculate the sum of absolute differences between the positions of consecutive elements in `b`
        for (int i = 1; i < n; i++) {
            res += Math.abs(b[i] - b[i - 1]);
        }
        
        System.out.println(res);  // Print the result
        
        scanner.close();  // Close the scanner
    }
}
// <END-OF-CODE>
