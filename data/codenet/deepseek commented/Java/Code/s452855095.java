import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static void main(String []args)
    {
        // Initialize a Scanner to read input from the standard input stream (System.in)
        Scanner sc = new Scanner(System.in);
        // Initialize a PrintWriter to write output to the standard output stream (System.out)
        PrintWriter out = new PrintWriter(System.out);
        
        // Read the number of elements in the array
        int n = sc.nextInt();
        // Declare and initialize an array of size n to store the elements
        int arr []=new int [n];
        
        // Read n integers from the input and store them in the array
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        
        // Initialize a counter to count the number of times the array can be halved
        int cnt =0;
        // Initialize a flag to check if all elements in the array are even
        boolean flag = true;
        
        // Start an infinite loop to repeatedly halve the array elements
        while(true)
        {
            // Iterate through each element of the array
            for(int i=0;i<n;i++)
            {
                // Check if the current element is odd
                if(arr[i]%2!=0)
                {
                    // Set the flag to false and break out of the loop
                    flag = false;
                    break;
                }
                else
                    // Divide the current element by 2 if it is even
                    arr[i] = arr[i]/2;
            }
            // If the flag is true, increment the counter
            if(flag==true)
                cnt++;
            else
                // Break out of the loop if the flag is false
                break;
        }
        // Print the final count
        out.println(cnt);
        // Flush the output to ensure the result is displayed immediately
        out.flush();
    }
}