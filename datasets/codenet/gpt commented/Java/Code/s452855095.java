//package Contest081;

import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static void main(String []args) {
        // Create a Scanner object for input and PrintWriter for output
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        // Read the number of elements in the array
        int n = sc.nextInt();
        // Initialize an array to hold the integers
        int arr [] = new int[n];
        
        // Populate the array with input values
        for(int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        
        // Initialize a counter for the number of times all elements can be divided by 2
        int cnt = 0;
        // Flag to check if all elements are even
        boolean flag = true;
        
        // Loop indefinitely until a break condition is met
        while(true) {
            // Check each element in the array
            for(int i = 0; i < n; i++) {
                // If an element is odd, set the flag to false and break the loop
                if(arr[i] % 2 != 0) {
                    flag = false;
                    break;
                } else {
                    // If the element is even, divide it by 2
                    arr[i] = arr[i] / 2;
                }
            }
            // If the flag is still true, increment the counter
            if(flag == true)
                cnt++;
            else
                // If any element was odd, exit the loop
                break;
        }
        
        // Output the count of how many times all elements were even
        out.println(cnt);
        // Flush the output to ensure all data is printed
        out.flush();
    }
}
