
import sys

def main():
    x = int(input()) # Read the first integer input
    y = int(input()) # Read the second integer input
    a = int(input()) # Read the third integer input
    b = int(input()) # Read the fourth integer input
    
    j = 2
    i = 0
    x1 = 0
    y1 = 0
    c = 0
    ans = True
    
    # Calculate the maximum of x and y and store it in c
    c = max(x, y)
    
    # If c is greater than b, print "0" and set ans to false
    if c > b:
        print("0")
        ans = False
    
    # Continue looping until c is divisible by the minimum of x and y or ans is false
    while c % min(x, y)!= 0 and ans:
        if x > y:
            c = x * j # Update c to be x multiplied by j
        else:
            c = y * j # Update c to be y multiplied by j
        j += 1 # Increment j
        
        # If the updated c is greater than b, print "0" and break out of the loop
        if c > b:
            print("0")
            ans = False
            break
    
    # If ans is still true, calculate the number of multiples of c between a and b
    if ans:
        count = 0
        i = a
        for i in range(a, b + 1):
            if i % c == 0: break # Break if a multiple of c is found
        if i!= b + 1: 
            print(((b - i) // c) + 1) # Print the number of multiples
        else: 
            print("0")

if __name__ == "__main__":
    main()

