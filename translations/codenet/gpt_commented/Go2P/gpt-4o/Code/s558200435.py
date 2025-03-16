def main():
    # Read the number of elements from standard input
    n = int(input())

    # Initialize a list to hold the input integers
    a = list(map(int, input().split()))

    # Initialize a list b to hold the longest increasing subsequence
    b = []

    # Iterate over each value in the input list a
    for v in a:
        # Use binary search to find the index where v can be placed in b
        x = binary_search(b, v)
        # If v is greater than all elements in b, append it to b
        if x == len(b):
            b.append(v)
        else:
            # Otherwise, replace the existing value at index x with v
            b[x] = v

    # Output the length of the longest increasing subsequence
    print(len(b))

def binary_search(b, v):
    low, high = 0, len(b)
    while low < high:
        mid = (low + high) // 2
        if b[mid] < v:
            low = mid + 1
        else:
            high = mid
    return low

if __name__ == "__main__":
    main()

# <END-OF-CODE>
