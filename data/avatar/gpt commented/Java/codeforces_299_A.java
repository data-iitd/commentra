import java.util.Arrays; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner in = new Scanner(System.in); 
        
        // Read the number of elements in the array
        int n = in.nextInt(); 
        
        // Initialize an array of size n to store the input values
        int[] a = new int[n]; 
        
        // Loop to read n integers from the user and store them in the array
        for (int i = 0; i < n; i++) { 
            a[i] = in.nextInt(); 
        } 
        
        // Sort the array in ascending order
        Arrays.sort(a); 
        
        // Store the minimum value from the sorted array
        int min = a[0]; 
        
        // Check if all elements in the array are divisible by the minimum value
        for (int value : a) { 
            if (value % min != 0) { 
                // If any element is not divisible, print -1 and exit
                System.out.println(-1); 
                return; 
            } 
        } 
        
        // If all elements are divisible, print the minimum value
        System.out.println(min); 
    } 
}
