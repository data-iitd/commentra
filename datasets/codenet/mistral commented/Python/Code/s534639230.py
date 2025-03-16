# Function to solve the problem
def solve():

    # Read input: number of elements N and list D
    N = int(input())
    D = list(map(int, input().split()))

    # Define the modulus for calculations
    mod = 998244353

    # Check if the first element of the list is zero
    if D[0] != 0:
        # If it is not zero, print 0 and return
        print(0)
        return

    # Use Counter to count the occurrences of each element in the list
    cnt = Counter(D)

    # Check if there is more than one occurrence of any element except the first one
    if cnt[0] > 1:
        # If there is, print 0 and return
        print(0)
        return

    # Initialize result to 1
    res = 1

    # Iterate through all possible elements i from 1 to the maximum element in the list
    for i in range(1, max(D)+1):
        # If the current element i-1 occurs only once, skip to the next iteration
        if cnt[i-1] == 1:
            continue

        # Multiply the result with the product of the count of the current element i and its previous occurrences
        res *= cnt[i-1]**cnt[i] % mod

        # Update the result by taking the modulo with the defined modulus
        res %= mod

    # Print the final result
    print(res)
