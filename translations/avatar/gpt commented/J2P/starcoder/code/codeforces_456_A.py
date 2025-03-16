import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

def main():
    # Declare a static ArrayList to hold some data (not used in this code)
    md = []

    # Create a Scanner object for input
    in = Scanner(System.in)
    
    # Read the number of pairs (n)
    n = in.nextInt()
    
    # Initialize two arrays to hold the pairs of integers
    a = [0] * n
    b = [0] * n
    
    # Temporary variables for processing
    temp = 0 # To track the current maximum value in array a
    q = 0    # To track the corresponding value in array b
    w = 0    # To track the maximum value in array a
    e = 0    # To track the corresponding value in array b
    f = False # Flag to determine if the condition for "Happy Alex" is met

    # Loop to read pairs of integers into arrays a and b
    for i in range(n):
        a[i] = in.nextInt() # Read value for array a
        b[i] = in.nextInt() # Read value for array b
        
        # Check if the current value in a is greater than the previous maximum
        if temp < a[i]:
            # If the current b value is less than the previous b value, set flag to true
            if q > b[i]:
                f = True
            # Update q and temp with current values
            q = b[i]
            temp = a[i]
        # Check if the current value in a is less than the previous maximum
        if temp > a[i]:
            # If the current b value is greater than the previous b value, set flag to true
            if q < b[i]:
                f = True
            # Update q and temp with current values
            q = b[i]
            temp = a[i]
        # Update the maximum value in a and check conditions for b
        if a[i] > w:
            w = a[i] # Update maximum value in a
            # If the current b value is less than the previous maximum b, set flag to true
            if b[i] < e:
                f = True
            e = b[i] # Update corresponding value in b
        # Check if the current value in a is less than the maximum value
        if a[i] < w:
            # If the current b value is greater than the previous maximum b, set flag to true
            if b[i] > e:
                f = True

    # Output the result based on the flag value
    if f == True:
        print("Happy Alex") # Condition met for "Happy Alex"
    else:
        print("Poor Alex")   # Condition not met, output "Poor Alex"

if __name__ == "__main__":
    main()

