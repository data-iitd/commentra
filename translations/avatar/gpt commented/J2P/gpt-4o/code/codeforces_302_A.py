import sys

def main():
    # Read the number of elements in the array and the number of queries
    n, k = map(int, sys.stdin.readline().split())
    
    # Initialize a list to hold the input values
    arr = list(map(int, sys.stdin.readline().split()))
    
    # String to store the results of the queries
    res = []
    
    # Counters for the number of 1s (o) and 0s (e) in the array
    o = arr.count(1)  # Count of 1s
    e = n - o         # Count of 0s (total - count of 1s)
    
    # Process each query
    for _ in range(k):
        l, r = map(int, sys.stdin.readline().split())
        
        # Check if the number of elements in the range is odd
        if (r - l + 1) % 2 == 1:
            res.append("0")  # If odd, append "0" to results
        else:
            # If even, check if we can form a valid pair of 1s and 0s
            if (r - l + 1) // 2 <= o and (r - l + 1) // 2 <= e:
                res.append("1")  # Append "1" if valid pairs can be formed
            else:
                res.append("0")  # Otherwise, append "0"
    
    # Output the results of all queries
    print("\n".join(res))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
