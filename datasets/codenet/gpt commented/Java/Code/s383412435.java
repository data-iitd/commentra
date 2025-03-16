import java.util.Scanner;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements N
        int N = sc.nextInt();
        
        // Initialize an array to hold the input numbers
        long a[] = new long[N];
        
        // Variable to hold temporary counts of duplicates
        int tmp;
        
        // Variable to hold the final answer
        int ans = 0;
        
        // Read N integers into the array
        for (int z = 0; N > z; z++) {
            a[z] = sc.nextInt();
        }
        
        // Sort the array to facilitate counting duplicates
        Arrays.sort(a);
        
        // Special case: if there is only one element and it's greater than 1
        if (N == 1 && a[0] > 1) {
            ans = 1; // Set answer to 1 since we can only have one unique number
        } else {
            // Loop through the sorted array to count duplicates
            for (int j = 0; N > j; j++) {
                // Check if the current element is the first occurrence
                if (j == 0 || a[j] != a[j - 1]) {
                    // Initialize temporary count of duplicates
                    tmp = 1;
                    
                    // Count how many times the current number appears in the array
                    for (int i = j + 1; N > i; i++) {
                        if (a[j] == a[i]) {
                            tmp++; // Increment count for duplicates
                        } else {
                            break; // Exit the loop if a different number is found
                        }
                    }
                    
                    // Adjust the answer based on the count of duplicates
                    if (tmp > a[j]) {
                        ans += tmp - a[j]; // More duplicates than the value itself
                    } else if (tmp < a[j]) {
                        ans += tmp; // Less duplicates than the value itself
                    }
                }
            }
        }
        
        // Print the final answer
        System.out.println(ans);
    }
}
