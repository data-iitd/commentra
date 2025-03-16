def main():
    # Read the number of elements in the array and the number of queries
    n, k = map(int, input().split())
    
    # Initialize an array to hold the input values
    arr = list(map(int, input().split()))
    
    # Process each query
    for _ in range(k):
        # Read the left and right indices for the current query
        l, r = map(int, input().split())
        
        # Count the number of 1s and 0s in the specified range
        o = arr[l-1:r].count(1)
        e = (r - l + 1) - o
        
        # Check if the number of elements in the range is odd
        if (r - l + 1) % 2 == 1:
            print(0)  # If odd, print "0"
        else:
            # If even, check if we can form a valid pair of 1s and 0s
            if (r - l + 1) // 2 <= o and (r - l + 1) // 2 <= e:
                print(1)  # Print "1" if valid pairs can be formed
            else:
                print(0)  # Otherwise, print "0"

if __name__ == "__main__":
    main()
