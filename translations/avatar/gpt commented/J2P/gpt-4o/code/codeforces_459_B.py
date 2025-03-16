import sys

def main():
    # Read the number of elements from input
    N = int(sys.stdin.readline().strip())
    
    # Read N integers from input and store them in the list A
    A = list(map(int, sys.stdin.readline().strip().split()))
    
    # Sort the list A to easily find the minimum and maximum values
    A.sort()
    
    # Identify the minimum and maximum values in the sorted list
    min_value = A[0]
    max_value = A[-1]
    
    # Initialize counters for occurrences of min and max values
    mins = A.count(min_value)
    maxs = A.count(max_value)
    
    # If all elements are the same (min equals max)
    if min_value == max_value:
        # Calculate the difference (which is 0) and the number of ways to choose 2 from mins
        print((max_value - min_value), mins * (mins - 1) // 2)
    else:
        # Calculate the difference and the product of occurrences of min and max
        print((max_value - min_value), mins * maxs)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
