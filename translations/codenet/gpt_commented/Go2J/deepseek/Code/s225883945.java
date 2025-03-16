import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from input: n (number of elements) and k (some parameter)
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read 'n' integers into array 'a'
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize sum with the value of k and set ans to 1
        int sum = k;
        int ans = 1;
        
        // Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
        while (sum < n) {
            sum = sum - 1 + k; // Update sum by subtracting 1 and adding k
            ans++; // Increment the answer counter
        }
        
        // Print the final answer
        System.out.println(ans);
    }
}

