def main():
    n = int(input())  # 1. Reading the input number of elements (n)
    
    a = list(map(int, input().split()))  # 2. Reading the elements into a list (a)
    
    b = []  # 3. Creating a list (b) to store the longest increasing subsequence
    for v in a:  # 4. Finding the longest increasing subsequence
        x = binary_search(b, v)
        if x == len(b):
            b.append(v)
        else:
            b[x] = v

    print(len(b))  # 5. Outputting the length of the longest increasing subsequence

def binary_search(b, v):
    """Helper function to perform binary search."""
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
