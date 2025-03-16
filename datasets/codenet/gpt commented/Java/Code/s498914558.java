import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read two integers from input: n (number of elements) and m (initial value)
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        // Initialize an array to hold the integers
        int po[] = new int[n];
        
        // Read n integers from input and subtract each from m
        for (int i = 0; i < n; i++) {
            po[i] = sc.nextInt(); // Store the input integer in the array
            m -= po[i]; // Decrease m by the value of the current integer
        }
        
        // Sort the array of integers in ascending order
        Arrays.sort(po);
        
        // Calculate and print the result: n plus the quotient of m divided by the smallest element in the array
        System.out.println(n + m / po[0]);
    }
}
