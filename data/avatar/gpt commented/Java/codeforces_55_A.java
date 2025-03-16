import java.util.*; 
import java.lang.*; 
import java.io.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner scan = new Scanner(System.in); 
        
        // Declare variables
        int n, i = 1, k = 0, p = 1; 
        boolean flag = true; 
        int[] a = new int[1000]; // Array to keep track of occurrences
        
        // Read an integer input from the user
        n = scan.nextInt(); 
        
