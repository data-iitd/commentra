import java.util.Arrays; 
import java.util.Scanner; 

public class Main { 
    // Create a Scanner object for user input
    public static Scanner input = new Scanner(System.in); 
    
    public static void main(String[] args) { 
        // Read two integers n and m from user input
        int n = input.nextInt(); 
        int m = input.nextInt(); 
        
        // Initialize an array of size m to hold the results
        int a[] = new int[m]; 
        
        // Check if n is divisible by m
        if (n % m == 0) { 
            // If divisible, fill the array with equal parts
            for (int i = 0; i < a.length; i++) { 
                a[i] = n / m; 
            } 
        } else { 
            // If not divisible, calculate the base value for each part
            int sub = n / m; 
            for (int i = 0; i < a.length; i++) { 
                a[i] = sub; 
            } 
            
            // Calculate the remainder that needs to be distributed
            int test = n - (sub * m); 
            int count = 0; 
            
            // Distribute the remainder across the first few elements of the array
            for (int i = 0; i < test; i++) { 
                a[count] = a[count] + 1; 
                count++; 
                
                // Wrap around if count exceeds the array length
                if (count >= a.length) count = 0; 
            } 
        } 
        
        // Print the array in reverse order
        for (int i = (a.length - 1); i >= 0; i--) { 
            System.out.print(a[i] + " "); 
        } 
    } 
}
