def solution(n, a):
    # Initialize a memo table to store the number of occurrences of each number
    memo = [0] * (int(1e5) + 2)

    # Iterate through the array and update the memo table
    for num in a:
        # Increment the memo table for the current number and the next two numbers
        memo[num] += 1
        memo[num + 1] += 1
        memo[num + 2] += 1

    # Initialize output variable to store the maximum number of occurrences found
    out = 0

    # Iterate through the memo table and update the output variable if a larger number is found
    for count in memo:
        if count > 0:
            # Update the output variable with the maximum number found so far
            out = max(out, count)

    # Return the maximum number of occurrences found
    return out

# Main function to read input and call the solution function
if __name__ == "__main__":
    # Read the size of the array from the standard input
    n = int(input())

    # Allocate memory for the array and read its elements from the standard input
    a = list(map(int, input().split()))

    # Call the solution function and print the result
    print(solution(n, a))

# <END-OF-CODE>
