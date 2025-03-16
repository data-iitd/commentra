import java.util.Arrays; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner in = new Scanner(System.in); 
        
        // Read the number of elements from the user
        int n = in.nextInt(); 
        
        // Initialize an array to hold the Long integers
        Long[] ans = new Long[n]; 
        
        // Read n Long integers from the user and store them in the array
        for (int i = 0; i < n; i++) { 
            ans[i] = in.nextLong(); 
        } 
        
        // Sort the array in ascending order
        Arrays.sort(ans); 
        
        // Initialize count with the largest element in the sorted array
        Long count = ans[n - 1]; 
        
        // Iterate through the array from the second largest element to the first
        for (int i = n - 2; i >= 0; i--) { 
            // If the current element is less than the next element, add it to count
            if (ans[i] < ans[i + 1]) { 
                count += ans[i]; 
            } else { 
                // If the current element is not less, decrement it until it is less than the next element
                while (ans[i] >= ans[i + 1]) { 
                    ans[i]--; 
                } 
                // If the decremented value is still positive, add it to count
                if (ans[i] > 0) { 
                    count += ans[i]; 
                } 
            } 
        } 
        
        // Print the final count
        System.out.println(count); 
    } 
}
