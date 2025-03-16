//package Contest081; // Package declaration

import java.io.PrintWriter; // Import PrintWriter for outputting to the console
import java.util.Scanner; // Import Scanner for reading input from the console

public class Main {
    public static void main(String []args) { // Main method entry point
        Scanner sc = new Scanner(System.in); // Initialize Scanner for reading input
        PrintWriter out = new PrintWriter(System.out); // Initialize PrintWriter for outputting results

        // Read the number of elements in the array from the input
        int n = sc.nextInt();

        // Allocate memory for the array and initialize it with the given size
        int arr []=new int [n];

        // Read the elements of the array from the input
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();

        // Initialize variables for counting the number of steps and checking if all elements are even
        int cnt =0;
        boolean flag = true;

        // Start the main loop
        while(true) {
            // Check if all elements in the array are even
            for(int i=0;i<n;i++) {
                // If an odd number is found, set the flag to false and break the loop
                if(arr[i]%2!=0) {
                    flag = false;
                    break;
                }
                // If the number is even, divide it by 2
                else
                    arr[i] = arr[i]/2;
            }

            // If all elements are even, increment the counter and check if the loop can be terminated
            if(flag==true)
                cnt++;
            else
                break;
        }

        // Output the result to the console
        out.println(cnt);

        // Flush the output buffer to ensure all output is written to the console
        out.flush();
    }
}
