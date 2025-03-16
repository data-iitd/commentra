
import java.util.ArrayList ; import java.util.Arrays ; import java.util.Scanner ;

def main():
 md = [] # Initialize an empty ArrayList with a capacity of n elements
 n = int(input()) # Read the first integer n, which represents the number of elements in the arrays a and b
 a = [int(input()) for i in range(n)] # Create an integer array a with a length of n
 b = [int(input()) for i in range(n)] # Create an integer array b with a length of n
 temp = 0 # Initialize a variable temp to 0
 q = 0 # Initialize a variable q to 0
 w = -2147483648 # Initialize a variable w to the smallest possible integer value
 e = -2147483648 # Initialize a variable e to the smallest possible integer value
 f = False # Initialize a boolean variable f to false

 for i in range(n): # Start a for loop that iterates through the elements of arrays a and b
 a[i] = int(input()) # Read the next integer value for a[i]
 b[i] = int(input()) # Read the next integer value for b[i]

 if temp < a[i]: # If the current value of temp is less than a[i]
 if q > b[i]: # Check if the condition q > b[i] is satisfied
 f = True # If it is, set f to true
 q = b[i] # Update q with the new value of b[i]
 temp = a[i] # Update temp with the new value of a[i]
 if temp > a[i]: # If the current value of temp is greater than a[i]
 if q < b[i]: # Check if the condition q < b[i] is satisfied
 f = True # If it is, set f to true
 q = b[i] # Update q with the new value of b[i]
 temp = a[i] # Update temp with the new value of a[i]
 if a[i] > w: # If the current value of a[i] is greater than w
 w = a[i] # Update w with the new value of a[i]
 if b[i] < e: # Check if the condition b[i] < e is satisfied
 f = True # If it is, set f to true
 if a[i] < w: # If the current value of a[i] is less than w
 if b[i] > e: # Check if the condition b[i] > e is satisfied
 f = True # If it is, set f to true
 if f == True: # After the loop finishes, check the value of the boolean variable f
 print("Happy Alex") # If it is true, print the message "Happy Alex"
 else:
 print("Poor Alex") # Otherwise, print the message "Poor Alex"

if __name__ == "__main__":
 main()

