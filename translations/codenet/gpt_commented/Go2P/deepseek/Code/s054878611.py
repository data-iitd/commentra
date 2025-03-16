def solution(n, a):
    # Create a memoization array to count occurrences of numbers and their successors.
    memo = [0] * (10**5 + 2)
    
    # Iterate through each number in the input array.
    for num in a:
        # Increment the count for the current number and its two successors.
        memo[num] += 1
        memo[num + 1] += 1
        memo[num + 2] += 1
    
    # Initialize the output variable to track the maximum frequency found.
    out = 0
    
    # Iterate through the memoization array to find the maximum frequency.
    for num in memo:
        # Update the output if the current count is greater than the current maximum.
        if num > 0:
            out = max(out, num)
    
    # Return the maximum frequency found.
    return out

# max function returns the greater of two integers x and y.
def max(x, y):
    if x > y:
        return x
    return y

# main function is the entry point of the program.
def main():
    # Declare a variable to hold the number of elements.
    n = int(input())
    
    # Create a list to hold the input integers.
    a = list(map(int, input().split()))
    
    # Call the solution function and print the result.
    print(solution(n, a))

main()
