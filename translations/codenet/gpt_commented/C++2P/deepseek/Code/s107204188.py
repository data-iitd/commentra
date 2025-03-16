def main():
    # Initialize minA to a value larger than any possible element in A
    minA = 10**9 + 1
    num = 0  # Counter for the number of valid pairs

    # Read the size of the array and the threshold value
    n, t = map(int, input().split())
    A = list(map(int, input().split()))  # Create a list to store the elements of the array

    # Iterate through the array to find the minimum value and count valid pairs
    for i in range(n):
        # Update minA if the current element is smaller
        if minA > A[i]:
            minA = A[i]
        else:
            # Check the difference between the current element and minA
            if f == A[i] - minA:
                num += 1  # Increment the count if the difference matches the previous one
            elif f < A[i] - minA:
                num = 1  # Reset count if a larger difference is found
                f = A[i] - minA  # Update the frequency to the new difference

    # Output the total count of valid pairs
    print(num)


main()
