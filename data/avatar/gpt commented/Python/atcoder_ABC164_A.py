import sys

def main():
    # Read two integers from input: S (the strength) and W (the weight)
    S, W = map(int, input().split())
    
    # Check if the strength S is less than or equal to the weight W
    # If it is, print "unsafe"; otherwise, print "safe"
    print("unsafe") if (S <= W) else print("safe")

# Entry point of the program
if __name__ == '__main__':
    main()
