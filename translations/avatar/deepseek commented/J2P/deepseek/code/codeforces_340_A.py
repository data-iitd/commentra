import sys

def main():
    # Read the input values
    x = int(sys.stdin.readline().strip())
    y = int(sys.stdin.readline().strip())
    a = int(sys.stdin.readline().strip())
    b = int(sys.stdin.readline().strip())
    
    # Initialize variables
    j = 2
    ans = True
    
    # Calculate the maximum of x and y
    c = max(x, y)
    
    # If c is greater than b, print "0" and set ans to False
    if c > b:
        print("0")
        ans = False
    
    # Continue looping until c is divisible by the minimum of x and y or ans is false
    while c % min(x, y) != 0 and ans:
        if x > y:
            c = x * j
        else:
            c = y * j
        j += 1
        
        # If the updated c is greater than b, print "0" and break out of the loop
        if c > b:
            print("0")
            ans = False
            break
    
    # If ans is still true, calculate the number of multiples of c between a and b
    if ans:
        count = 0
        i = a
        while i <= b:
            if i % c == 0:
                break
            i += 1
        if i != b + 1:
            print(((b - i) // c) + 1)
        else:
            print("0")

if __name__ == "__main__":
    main()
