def main():
    # Step 1: Read the input values for n and k
    n, k = map(int, input().split())  # Read the size of the array and the number of queries

    # Step 2: Read the array elements
    arr = list(map(int, input().split()))  # Read each element of the array

    # Step 3: Initialize two counters, o and e, to count the number of 1s and 0s in the array, respectively
    o = arr.count(1)  # Count the number of 1s
    e = arr.count(0)  # Count the number of 0s

    # Step 4: For each query, determine if the length of the subarray is odd
    results = []  # To store the results
    for _ in range(k):
        l, r = map(int, input().split())  # Read the left and right indices of the subarray

        if (r - l + 1) % 2 == 1:
            results.append("0\n")  # Append "0" if the length is odd
        else:
            # Step 5: If the length of the subarray is even, check if the number of 1s and 0s is sufficient
            if (r - l + 1) // 2 <= o and (r - l + 1) // 2 <= e:
                results.append("1\n")  # Append "1" if the condition is satisfied
            else:
                results.append("0\n")  # Append "0" if the condition is not satisfied

    # Step 6: Print the result
    print("".join(results))


if __name__ == "__main__":
    main()
