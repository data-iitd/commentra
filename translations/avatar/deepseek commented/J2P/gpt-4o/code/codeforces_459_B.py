import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    # Read the size of the array
    N = int(data[0])
    
    # Read the elements of the array
    A = list(map(int, data[1:N+1]))
    
    # Sort the array
    A.sort()
    
    # Find the minimum and maximum values in the array
    min_val = A[0]
    max_val = A[N - 1]
    
    # Count the occurrences of the minimum and maximum values
    mins = A.count(min_val)
    maxs = A.count(max_val)
    
    # Special case: if min == max
    if min_val == max_val:
        print((max_val - min_val), (mins * (mins - 1)) // 2)
    else:
        # General case: if min != max
        print((max_val - min_val), (mins * maxs))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
