def main():
    n = int(input())
    a = list(map(int, input().split()))

    b = []
    for v in a:
        # Perform binary search to find the position to replace or append
        x = binary_search(b, v)
        if x == len(b):
            b.append(v)
        else:
            b[x] = v

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
