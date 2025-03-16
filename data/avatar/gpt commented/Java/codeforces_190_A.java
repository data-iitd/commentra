import java.io.*; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read two integers n and m from the input
        int n = sc.nextInt(); 
        int m = sc.nextInt(); 
        
        // Check if n is zero
        if (n == 0) { 
            // If m is not zero, print "Impossible" since we cannot form a valid output
            if (m != 0) 
                System.out.println("Impossible"); 
            // If m is also zero, print "0 0" as the valid output
            else 
                System.out.println(0 + " " + 0); 
            return; 
        } 
        
        // Check if m is less than or equal to n
        if (m <= n) { 
            // If m is zero, set it to one to ensure valid output
            if (m == 0) { 
                m = 1; 
            } 
            // Print n and the adjusted value of m
            System.out.print(n + " " + (m + n - 1)); 
            return; 
        } 
        
        // If m is greater than n, print m and the adjusted value of m
        System.out.print(m + " " + (m + n - 1)); 
    } 
}
