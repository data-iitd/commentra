import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    # Declare a static ArrayList to hold some data (not used in this code)
    static ArrayList md = new ArrayList();

    public static void main(String[] args) {
        # Create a Scanner object for input
        Scanner in = new Scanner(System.in);
        
        # Read the number of pairs (n)
        int n = in.nextInt();
        
        # Initialize two arrays to hold the pairs of integers
        int[] a = new int[n];
        int[] b = new int[n];
        
        # Temporary variables for processing
        int temp = 0; # To track the current maximum value in array a
        int q = 0;    # To track the corresponding value in array b
        int w = 0;    # To track the maximum value in array a
        int e = 0;    # To track the corresponding value in array b
        boolean f = false; # Flag to determine if the condition for "Happy Alex" is met

        # Loop to read pairs of integers into arrays a and b
        for i in range(n):
            a[i] = in.nextInt(); # Read value for array a
            b[i] = in.nextInt(); # Read value for array b
            
            # Check if the current value in a is greater than the previous maximum
            if temp < a[i]:
                # If the current b value is less than the previous b value, set flag to true
                if q > b[i]:
                    f = true;
                # Update q and temp with current values
                q = b[i];
                temp = a[i];
            # Check if the current value in a is less than the previous maximum
            if temp > a[i]:
                # If the current b value is greater than the previous b value, set flag to true
                if q < b[i]:
                    f = true;
                # Update q and temp with current values
                q = b[i];
                temp = a[i];
            # Update the maximum value in a and check conditions for b
            if a[i] > w:
                w = a[i]; # Update maximum value in a
                # If the current b value is less than the previous maximum b, set flag to true
                if b[i] < e:
                    f = true;
                e = b[i]; # Update corresponding value in b
            # Check if the current value in a is less than the maximum value
            if a[i] < w:
                # If the current b value is greater than the previous maximum b, set flag to true
                if b[i] > e:
                    f = true;

        # Output the result based on the flag value
        if f == true:
            print("Happy Alex"); # Condition met for "Happy Alex"
        else:
            print("Poor Alex");   # Condition not met, output "Poor Alex"
    }
}

