def main():
    import sys
    
    # Read the number of integers to be processed
    n = int(input())
    
    # If there is only one integer, print it and exit
    if n == 1:
        print(int(input()))
        sys.exit(0)
    
    # Read n integers from input and store them in a list
    a = [int(input()) for _ in range(n)]
    
    # Sort the list in ascending order
    a.sort()
    
    # If the largest number is 0, print 0 and exit
    if a[-1] == 0:
        print(0)
        sys.exit(0)
    
    # Initialize the answer variable
    ans = 0
    
    # Loop until the list is reduced to one element
    while True:
        # If only one element remains, set it as the answer and break the loop
        if len(a) == 1:
            ans = a[0]
            break
        # Call the function to process the list and update it
        a = func(a)
    
    # Print the final answer
    print(ans)

def func(A):
    # Create a copy of the input list
    a = A.copy()
    
    # Initialize a variable to store the minimum value
    min_val = 0
    
    # Iterate through the list
    i = 0
    while i < len(a):
        # If the current element is 0, remove it from the list
        if a[i] == 0:
            a.pop(i)
        else:
            # If min_val is not zero, update the current element
            if min_val != 0:
                a[i] = a[i] % min_val
                # If the updated element is 1, print 1 and exit
                if a[i] == 1:
                    print(1)
                    sys.exit(0)
            else:
                # Set min_val to the current element if min_val is still zero
                min_val = a[i]
                i += 1  # Only increment if we didn't remove an element
    # Sort the modified list before returning
    a.sort()
    return a

if __name__ == "__main__":
    main()

# <END-OF-CODE>
