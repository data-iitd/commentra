import sys

def main():
    # Read the number of integers to be processed
    n = int(sys.stdin.readline())
    
    # Initialize an empty list to store the integers
    a = []
    
    # If there is only one integer, print it and exit
    if n == 1:
        print(int(sys.stdin.readline()))
        sys.exit(0)
    
    # Read n integers from input and add them to the list
    for i in range(n):
        a.append(int(sys.stdin.readline()))
    
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

def func(a):
    # Create a copy of the input list
    a_copy = a[:]
    
    # Initialize a variable to store the minimum value
    min = 0
    
    # Iterate through the list
    for i in range(len(a_copy)):
        # If the current element is 0, remove it from the list
        if a_copy[i] == 0:
            a_copy.pop(i)
            i -= 1 # Adjust index after removal
        else:
            # If min is not zero, update the current element
            if min != 0:
                a_copy[i] = a_copy[i] % min
                # If the updated element is 1, print 1 and exit
                if a_copy[i] == 1:
                    print(1)
                    sys.exit(0)
            else:
                # Set min to the current element if min is still zero
                min = a_copy[i]
    
    # Sort the modified list before returning
    a_copy.sort()
    return a_copy

if __name__ == "__main__":
    main()

