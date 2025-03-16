
import sys # Step 1: Import the sys module.

def main(): # Step 2: Define the main function.
    n, k = map(int, sys.stdin.readline().split()) # Step 3: Read two integer values from the user and store them in the variables n and k.
    
    n += 1 # Step 4: Increment the value of n by 1.
    
    z = 0 # Step 5: Initialize a variable z to 0.
    
    if n % k!= 0: # Step 6: Check if n is not divisible by k.
        z = k - n % k # If true, calculate the difference between k and the remainder of n divided by k, and store it in z.
    
    print(n + z) # Step 7: Print the new value of n plus the value of z.

if __name__ == "__main__": # Step 8: Call the main function if the script is executed directly.
    main()

