import java.util.*; 
import java.io.*; 

public class Main { 
    public static void main(String args[]) throws IOException { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements to be processed
        int n = sc.nextInt(); 
        
        // Initialize variables to hold the sums of three different sets of integers
        int a = 0, b = 0, c = 0; 
        
        // Read n integers and calculate their sum (a)
        for (int i = 0; i < n; i++) 
            a += sc.nextInt(); 
        
        // Read n-1 integers and calculate their sum (b)
        for (int i = 0; i < n - 1; i++) 
            b += sc.nextInt(); 
        
        // Read n-2 integers and calculate their sum (c)
        for (int i = 0; i < n - 2; i++) 
            c += sc.nextInt(); 
        
        // Calculate the difference between the sums: x = sum of first set - sum of second set
        int x = a - b; 
        
        // Calculate the difference between the sums: y = sum of second set - sum of third set
        int y = b - c; 
        
        // Print the results of the differences
        System.out.println(x); 
        System.out.println(y); 
    } 
}
