# Include the standard input/output library
import sys

# Declare the main function with return type signed
def main():
    # Declare two integer variables n and k
    n = int(input())
    k = int(input())

    # Declare an array p of integers with a size of 99999
    p = [0] * 99999

    # Declare integer variables i, j, l, and m
    i = 0
    j = 0
    l = 0
    m = 0

    # Declare an integer variable o and initialize it to 0
    o = 0

    # Read two integers from the standard input and store them in variables n and k
    for i in range(n):
        p[i] = int(input())

    # Iterate through the array p from index 0 to n-1
    for i in range(n):
        l = i
        # Iterate through the array p from index i+1 to n-1
        for j in range(i+1,n):
            if(p[j] < p[l]):
                l = j
        # If the index of the smallest element is not equal to i
        if(l!= i):
            # Swap the elements at indices i and l
            m = p[i]
            p[i] = p[l]
            p[l] = m

    # Iterate through the array p from index 0 to k-1
    for i in range(k):
        # Add the element at index i to the variable o
        o += p[i]

    # Print the value of the variable o to the standard output
    print(o)

    # Return 0 to indicate successful execution of the program
    return 0

# Call the main function
if __name__ == "__main__":
    main()

