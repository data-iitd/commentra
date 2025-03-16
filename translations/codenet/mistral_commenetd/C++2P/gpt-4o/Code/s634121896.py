def fast_io():
    import sys
    input = sys.stdin.read
    return input().splitlines()

def solve(nums):
    n = len(nums)
    # Initialize a vector to store the prefix sum of the number of ways to reach each index
    dp = [0] * (n + 1)
    # Set the initial value of the prefix sum at index 0
    dp[0] = 1
    # Initialize two maps to keep track of the previous index of each number and the number of ways to reach the previous index
    kek = {}
    prev = {}
    
    # Iterate through the numbers from 1 to n
    for i in range(1, n + 1):
        # Calculate the prefix sum at the current index
        dp[i] = dp[i - 1] + (kek.get(nums[i - 1], 0) if prev.get(nums[i - 1], -1) != i - 1 else 0)
        dp[i] %= 1000000007  # MOD
        # Update the maps
        kek[nums[i - 1]] = dp[i]
        prev[nums[i - 1]] = i
    
    # Output the result
    print(dp[n])

# Main function to run the program
if __name__ == "__main__":
    input_data = fast_io()
    n = int(input_data[0])
    nums = list(map(int, input_data[1:n + 1]))
    solve(nums)

# <END-OF-CODE>
