def find(li, from_index, target):
    low = from_index
    upp = len(li) - 1

    # Base cases for the search
    if upp < low:
        return 0
    elif li[from_index] >= target:
        return 0
    elif li[upp] < target:
        return upp - low + 1

    # Perform binary search to find the count of valid integers
    while upp - low > 1:
        mid = (low + upp) // 2
        if li[mid] >= target:
            upp = mid
        else:
            low = mid

    return low - from_index + 1

def main():
    # Read the number of integers to be processed
    N = int(input())

    # Initialize a list to store the integers
    L = []

    # Read N integers from input and add them to the list
    for _ in range(N):
        L.append(int(input()))

    # Sort the list of integers in ascending order
    L.sort()

    # Initialize a counter to keep track of valid pairs
    count = 0

    # Iterate through each pair of integers in the sorted list
    for i in range(N):
        for j in range(i + 1, N):
            # Get the current pair of integers
            a = L[i]
            b = L[j]

            # Find the number of integers that can form a valid triplet with a and b
            res = find(L, j + 1, a + b)

            # Increment the count by the number of valid triplets found
            count += res

    # Output the total count of valid triplets
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
