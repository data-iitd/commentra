import sys

def main():
    # Read the number of elements from input
    N = int(input().strip())
    
    # Read N integers from input and store them in the list A
    A = list(map(int, input().strip().split()))
    
    # Sort the list A to easily find the minimum and maximum values
    A.sort()
    
    # Identify the minimum and maximum values in the sorted list
    min_val = A[0]
    max_val = A[-1]
    
    # Initialize counters for occurrences of min and max values
    mins = A.count(min_val)
    maxs = A.count(max_val)
    
    # If all elements are the same (min equals max)
    if min_val == max_val:
        # Calculate the difference (which is 0) and the number of ways to choose 2 from mins
        print(f"{max_val - min_val} {mins * (mins - 1) // 2}")
    else:
        # Calculate the difference and the product of occurrences of min and max
        print(f"{max_val - min_val} {mins * maxs}")

if __name__ == "__main__":
    main()
