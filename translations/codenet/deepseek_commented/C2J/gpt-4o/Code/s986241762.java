import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Read the value of n, which represents the number of elements in the array.
        int n = scanner.nextInt(); // Read the number of elements.
        long sum = 0; // Initialize sum to store the total difference.
        
        // Step 2: Dynamically allocate memory for an array 'a' of size n.
        int[] a = new int[n];
        
        // Step 3: Read n elements into the array 'a'.
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Step 4: Iterate through the array and calculate the sum of the differences between consecutive elements.
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                sum += a[i - 1] - a[i]; // Add the difference to the sum.
                a[i] = a[i - 1]; // Update the current element to be at least as large as the previous one.
            }
        }
        
        // Step 5: Print the calculated sum.
        System.out.println(sum);
        
        scanner.close();
    }
}

// <END-OF-CODE>
