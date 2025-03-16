def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Step 1: Read the input values for n and k
    n = int(data[0])  # Read the size of the array
    k = int(data[1])  # Read the number of queries

    # Step 2: Read the array elements
    arr = list(map(int, data[2:n+2]))  # Read each element of the array

    # Step 3: Initialize two counters, o and e, to count the number of 1s and 0s in the array, respectively
    res = []  # To store the result
    o = 0  # Counter for 1s
    e = 0  # Counter for 0s

    # Step 4: Iterate through the array to count the number of 1s and 0s
    for value in arr:
        if value == 1:
            o += 1  # Increment the counter for 1s
        else:
            e += 1  # Increment the counter for 0s

    # Step 5: For each query, determine if the length of the subarray is odd
    index = n + 2
    for _ in range(k):
        l = int(data[index])  # Read the left index of the subarray
        r = int(data[index + 1])  # Read the right index of the subarray
        index += 2

        if (r - l + 1) % 2 == 1:
            res.append("0")  # Append "0" if the length is odd
        else:
            # Step 6: If the length of the subarray is even, check if the number of 1s and 0s is sufficient
            if (r - l + 1) // 2 <= o and (r - l + 1) // 2 <= e:
                res.append("1")  # Append "1" if the condition is satisfied
            else:
                res.append("0")  # Append "0" if the condition is not satisfied

    # Step 7: Print the result
    print("\n".join(res))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
