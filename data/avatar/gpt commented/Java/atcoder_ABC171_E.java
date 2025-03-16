import java.util.ArrayList; 
import java.util.Arrays; 
import java.util.Collections; 
import java.util.Comparator; 
import java.util.HashSet; 
import java.util.List; 
import java.util.PriorityQueue; 
import java.util.Scanner; 
import java.util.Set; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements in the array
        int n = sc.nextInt(); 
        
        // Initialize an array to hold the input integers
        int[] a = new int[n]; 
        
        // Variable to hold the cumulative XOR of all elements
        int r = 0; 
        
        // Read each integer from input and compute the cumulative XOR
        for (int i = 0; i < n; i++) { 
            a[i] = sc.nextInt(); 
            r ^= a[i]; // Update the cumulative XOR with the current element
        } 
        
        // For each element in the array, print the result of XORing the cumulative XOR with the element
        for (int i = 0; i < n; i++) { 
            if (i != 0) 
                System.out.print(" "); // Print a space before the next number if it's not the first element
            System.out.print(r ^ a[i]); // Print the result of XORing the cumulative XOR with the current element
        } 
    } 
}
