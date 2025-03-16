# Import the necessary module to read input from the user
import sys

def main():
    # Read the first four integer inputs
    x = int(sys.stdin.readline().strip())
    y = int(sys.stdin.readline().strip())
    a = int(sys.stdin.readline().strip())
    b = int(sys.stdin.readline().strip())
    
    j = 2
    c = 0
    ans = True  # Initialize a boolean variable to track the result
    
    # Calculate the maximum of x and y and store it in c
    c = max(x, y)
    
    # If c is greater than b, print "0" and set ans to false
    if c > b:
        print("0")
        ans = False
    
    # Continue looping until c is divisible by the minimum of x and y or ans is false
    while c % min(x, y) != 0 and ans:
        if x > y:
            c = x * j  # Update c to be x multiplied by j
        else:
            c = y * j  # Update c to be y multiplied by j
        j += 1  # Increment j
        
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
            if i % c == 0:
                break  # Break if a multiple of c is found
        if i != b + 1:
            print(((b - i) // c) + 1)  # Print the number of multiples
        else:
            print("0")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
