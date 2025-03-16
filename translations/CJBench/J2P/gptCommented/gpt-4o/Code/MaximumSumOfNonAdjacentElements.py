class Main:
    # Method to calculate the maximum sum of non-adjacent elements using dynamic programming (Approach 1)
    @staticmethod
    def get_max_sum_approach_1(arr):
        # If the array is empty, return 0 as the maximum sum
        if len(arr) == 0:
            return 0
        
        n = len(arr)  # Get the length of the array
        dp = [0] * n  # Create a dp array to store maximum sums
        
        dp[0] = arr[0]  # Initialize the first element of dp with the first element of arr
        
        # Iterate through the array starting from the second element
        for ind in range(1, n):
            not_take = dp[ind - 1]  # Maximum sum if we do not take the current element
            take = arr[ind]  # Start with the current element
            
            # If we are not at the first element, add the maximum sum from two elements before
            if ind > 1:
                take += dp[ind - 2]
            
            # Store the maximum of taking or not taking the current element
            dp[ind] = max(take, not_take)
        
        # Return the maximum sum found for the entire array
        return dp[n - 1]

    # Method to calculate the maximum sum of non-adjacent elements using a space-optimized approach (Approach 2)
    @staticmethod
    def get_max_sum_approach_2(arr):
        # If the array is empty, return 0 as the maximum sum
        if len(arr) == 0:
            return 0
        
        n = len(arr)  # Get the length of the array
        prev1 = arr[0]  # Initialize prev1 with the first element of arr
        prev2 = 0  # Initialize prev2 to 0
        
        # Iterate through the array starting from the second element
        for ind in range(1, n):
            not_take = prev1  # Maximum sum if we do not take the current element
            take = arr[ind]  # Start with the current element
            
            # If we are not at the first element, add the maximum sum from two elements before
            if ind > 1:
                take += prev2
            
            # Calculate the current maximum sum
            current = max(take, not_take)
            
            # Update prev2 and prev1 for the next iteration
            prev2 = prev1
            prev1 = current
        
        # Return the maximum sum found for the entire array
        return prev1

    # Main method to execute the program
    @staticmethod
    def main():
        import sys
        
        # Read the number of elements in the array
        n = int(input())
        array = list(map(int, input().split()))  # Read the elements of the array from input
        
        # Read the choice of approach from input
        choice = int(input())
        result = 0  # Variable to store the result
        
        # Determine which approach to use based on user choice
        if choice == 1:
            result = Main.get_max_sum_approach_1(array)  # Use Approach 1
        else:
            result = Main.get_max_sum_approach_2(array)  # Use Approach 2
        
        # Print the result
        print("The maximum sum of non-adjacent elements is:", result)

# Execute the main method
if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
